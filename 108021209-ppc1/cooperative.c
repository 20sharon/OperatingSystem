#include <8051.h>
#include "cooperative.h"
/*
* @@@ [2 pts] declare the static globals here using
* __data __at (address) type name; syntax
* manually allocate the addresses of these variables, for
* - saved stack pointers (MAXTHREADS)
* - current thread ID
* - a bitmap for which thread ID is a valid thread;
* maybe also a count, but strictly speaking not necessary
* - plus any temporaries that you need.
*/
__data __at (0x30) char saved_SP_Thread0;
__data __at (0x31) char saved_SP_Thread1;
__data __at (0x32) char saved_SP_Thread2;
__data __at (0x33) char saved_SP_Thread3;
__data __at (0x34) char bitmap_for_Thread;
__data __at (0x35) ThreadID CurrentThreadID;
__data __at (0x20) ThreadID created_ThreadID;
__data __at (0x21) char created_Thread_SP;
__data __at (0x22) char temp_for_SP;
/*
* @@@ [8 pts]
* define a macro for saving the context of the current thread by
* 1) push ACC, B register, Data pointer registers (DPL, DPH), PSW
* 2) save SP into the saved Stack Pointers array
* as indexed by the current thread ID.
* Note that 1) should be written in assembly,
* while 2) can be written in either assembly or C
*/
#define SAVESTATE \
{ __asm \
            PUSH ACC \
            PUSH B \
            PUSH DPL \
            PUSH DPH \
            PUSH PSW \
        __endasm; \
    if(CurrentThreadID == 0){ \
        saved_SP_Thread0 = SP; \
    }else if(CurrentThreadID == 1){ \
        saved_SP_Thread1 = SP; \
    }else if(CurrentThreadID == 2){ \
        saved_SP_Thread2 = SP; \
    }else{ \
        saved_SP_Thread3 = SP; \
    } \
}

/*
* @@@ [8 pts]
* define a macro for restoring the context of the current thread by
* essentially doing the reverse of SAVESTATE:
* 1) assign SP to the saved SP from the saved stack pointer array
* 2) pop the registers PSW, data pointer registers, B reg, and ACC
* Again, popping must be done in assembly but restoring SP can be
* done in either C or assembly.
*/
#define RESTORESTATE \
{ \
    if(CurrentThreadID == 0){ \
        SP = saved_SP_Thread0; \
    }else if(CurrentThreadID == 1){ \
        SP = saved_SP_Thread1; \
    }else if(CurrentThreadID == 2){ \
        SP = saved_SP_Thread2; \
    }else{ \
        SP = saved_SP_Thread3; \
    } \
    __asm \
        POP PSW \
        POP DPH \
        POP DPL \
        POP B \
        POP ACC \
    __endasm; \
}
/*
* we declare main() as an extern so we can reference its symbol
* when creating a thread for it.
*/
extern void main(void);
/*
* Bootstrap is jumped to by the startup code to make the thread for
* main, and restore its context so the thread can run.
*/
void Bootstrap(void) {
/*
* @@@ [2 pts]
* initialize data structures for threads (e.g., mask)
*
* optional: move the stack pointer to some known location
* only during bootstrapping. by default, SP is 0x07.
*
* @@@ [2 pts]
* create a thread for main; be sure current thread is
* set to this thread ID, and restore its context,
* so that it starts running main().
*/
    bitmap_for_Thread = 0b00000000;
    saved_SP_Thread0 = 0x3F;
    saved_SP_Thread1 = 0x4F;
    saved_SP_Thread2 = 0x5F;
    saved_SP_Thread3 = 0x6F;

    CurrentThreadID = ThreadCreate(main);
    RESTORESTATE;
}
/*
* ThreadCreate() creates a thread data structure so it is ready
* to be restored (context switched in).
* The function pointer itself should take no argument and should
* return no argument.
*/

ThreadID ThreadCreate(FunctionPtr fp) {
/*
* @@@ [2 pts]
* check to see we have not reached the max #threads.
* if so, return -1, which is not a valid thread ID.
*/
    if(bitmap_for_Thread == 0b00001111){// 0x0F){
        return -1;
    }
    /*
    * @@@ [5 pts]
    * otherwise, find a thread ID that is not in use,
    * and grab it. (can check the bit mask for threads),
    *
    * @@@ [18 pts] below
    * a. update the bit mask
    (and increment thread count, if you use a thread count,
    but it is optional)
    b. calculate the starting stack location for new thread
    c. save the current SP in a temporary
    set SP to the starting location for the new thread
    d. push the return address fp (2-byte parameter to
    ThreadCreate) onto stack so it can be the return
    address to resume the thread. Note that in SDCC
    convention, 2-byte ptr is passed in DPTR. but
    push instruction can only push it as two separate
    registers, DPL and DPH.
    e. we want to initialize the registers to 0, so we
    assign a register to 0 and push it four times
    for ACC, B, DPL, DPH. Note: push #0 will not work
    because push takes only direct address as its operand,
    but it does not take an immediate (literal) operand.
    f. finally, we need to push PSW (processor status word)
    register, which consist of bits
    CY AC F0 RS1 RS0 OV UD P
    all bits can be initialized to zero, except <RS1:RS0>
    which selects the register bank.
    Thread 0 uses bank 0, Thread 1 uses bank 1, etc.
    Setting the bits to 00B, 01B, 10B, 11B will select
    the register bank so no need to push/pop registers
    R0-R7. So, set PSW to
    00000000B for thread 0, 00001000B for thread 1,
    00010000B for thread 2, 00011000B for thread 3.
    g. write the current stack pointer to the saved stack
    pointer array for this newly created thread ID
    h. set SP to the saved SP in step c.
    i. finally, return the newly created thread ID.
    */
    // a // b
    if((bitmap_for_Thread & 0b00000001) == 0b00000000){
        // thread0 is not used
        bitmap_for_Thread = (bitmap_for_Thread | 0b00000001);
        created_ThreadID = 0;
        created_Thread_SP = 0x3F;
    }else if((bitmap_for_Thread & 0x02) == 0x00){
        // thread1 is not used
        bitmap_for_Thread = bitmap_for_Thread | 0x02;
        created_ThreadID = 1;
        created_Thread_SP = 0x4F;
    }else if((bitmap_for_Thread & 0x04) == 0x00){
        // thread2 is not used
        bitmap_for_Thread = bitmap_for_Thread | 0x04;
        created_ThreadID = 2;
        created_Thread_SP = 0x5F;
    }else if((bitmap_for_Thread & 0x08) == 0x00){
        // thread3 is not used
        bitmap_for_Thread = bitmap_for_Thread | 0x08;
        created_ThreadID = 3;
        created_Thread_SP = 0x6F;
    }
    // c
    temp_for_SP = SP;
    SP = created_Thread_SP;
    /*
    __asm
        MOV temp_for_SP, SP
        MOV SP, created_Thread_SP
    __endasm;
    */
    // d
    __asm
        PUSH DPL
        PUSH DPH
    __endasm;
    // e
    //ACC = 0;
    __asm
        CLR A
        PUSH ACC
        PUSH ACC
        PUSH ACC
        PUSH ACC
    __endasm;
    // f // g
    if(created_ThreadID == 0){
        PSW = 0b00000000;
        __asm
            // MOV PSW, #0H
            PUSH PSW
            // MOV 0x32, SP // 0x30
        __endasm;
        // SP = saved_SP_Thread0; //wrong
        saved_SP_Thread0 = SP;
    }else if(created_ThreadID == 1){
        PSW = 0b00001000;
        __asm
            // MOV PSW, #8H
            PUSH PSW
            // MOV 0x31, SP
        __endasm;
        // SP = saved_SP_Thread1; //wrong
        saved_SP_Thread1 = SP;
    }else if(created_ThreadID == 2){
        PSW = 0b00010000;
        __asm
            // MOV PSW, #10H // 16dec = 10hex
            PUSH PSW
            // MOV 0x32, SP
        __endasm;
        // SP = saved_SP_Thread2; //wrong
        saved_SP_Thread2 = SP;
    }else{
        PSW = 0b00011000;
        __asm
            // MOV PSW, #18H  // 24dec = 18hex
            PUSH PSW
            // MOV 0x33, SP
        __endasm;
        // SP = saved_SP_Thread3; //wrong
        saved_SP_Thread3 = SP;
    }
    // h
    SP = temp_for_SP;
    /*
    __asm
        MOV SP, temp_for_SP
    __endasm;
    */
    // i
    return created_ThreadID;
}


/*
* this is called by a running thread to yield control to another
* thread. ThreadYield() saves the context of the current
* running thread, picks another thread (and set the current thread
* ID to it), if any, and then restores its state.
*/

void ThreadYield(void) {
    SAVESTATE;
    do {
    /*
    * @@@ [8 pts] do round-robin policy for now.
    * find the next thread that can run and
    * set the current thread ID to it,
    * so that it can be restored (by the last line of
    * this function).
    * there should be at least one thread, so this loop
    * will always terminate.
    */

        if(CurrentThreadID == 0){
            CurrentThreadID = 1;
            if((bitmap_for_Thread & 0x02) != 0){ // test if free
                // is free // the bitmap for the threadid is one
                break;
            }
        }else if(CurrentThreadID == 1){
            CurrentThreadID = 2;
            if((bitmap_for_Thread & 0x04) != 0){ // test if free
                // is free
                break;
            }
        }else if(CurrentThreadID == 2){
            CurrentThreadID = 3;
            if((bitmap_for_Thread & 0x08) != 0){ // test if free
                // is free
                break;
            }
        }else{ // if CurrentThreadID == 3
            CurrentThreadID = 0;
            if((bitmap_for_Thread & 0x01) != 0){ // test if free
                // is free
                break;
            }
        }

        // test if free
    } while (1);
    RESTORESTATE;
}


/*
* ThreadExit() is called by the thread's own code to terminate
* itself. It will never return; instead, it switches context
* to another thread.
*/
void ThreadExit(void) {
/*
* clear the bit for the current thread from the
* bit mask, decrement thread count (if any),
* and set current thread to another valid ID.
* Q: What happens if there are no more valid threads?
*/
    if(CurrentThreadID == 0){ // 1111 1110
        bitmap_for_Thread = bitmap_for_Thread & 0b11111110; // 0xFF;
    }else if(CurrentThreadID == 1){ // 1111 1101
        bitmap_for_Thread = bitmap_for_Thread & 0b11111101; // 0xFE;
    }else if(CurrentThreadID == 2){ // 1111 1011
        bitmap_for_Thread = bitmap_for_Thread & 0b11111011; // 0xFB;
    }else if(CurrentThreadID == 3){ // 1111 0111
        bitmap_for_Thread = bitmap_for_Thread & 0b11110111; // 0xF7;
    }
    do {
        if(CurrentThreadID == 0){
            CurrentThreadID = 1;
            if((bitmap_for_Thread & 0x02) != 0x02){ // test if free
                break;
            }
        }else if(CurrentThreadID == 1){
            CurrentThreadID = 2;
            if((bitmap_for_Thread & 0x04) != 0x04){ // test if free
                break;
            }
        }else if(CurrentThreadID == 2){
            CurrentThreadID = 3;
            if((bitmap_for_Thread & 0x08) != 0x08){ // test if free
                break;
            }
        }else{
            CurrentThreadID = 0;
            if((bitmap_for_Thread & 0x01) != 0x01){ // test if free
                break;
            }
        }
        // test if free
    } while (1);
    RESTORESTATE;
}
