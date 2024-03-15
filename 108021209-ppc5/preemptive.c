// done for checkpoint2
#include <8051.h>
#include "preemptive.h"
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
__data __at (0x37) char num_thread;
__data __at (0x39) char delay_time[2];
__data __at (0x20) ThreadID created_ThreadID;
__data __at (0x21) char created_Thread_SP;
__data __at (0x22) char temp_for_SP;
__data __at (0x28) char car_leave_spot_time[5]; // 0x28~0x2C
__data __at (0x2D) char Time;
__data __at (0x2E) char spot[2];

/*
* @@@ [8 pts]
* define a macro for saving the context of the current thread by
* 1) push ACC, B register, Data pointer registers (DPL, DPH), PSW
* 2) save SP into the saved Stack Pointers array
* as indexed by the current thread ID.
* Note that 1) should be written in assembly,
* while 2) can be written in either assembly or C
*/

void delay(unsigned char n){
    EA = 0;
    // delay[0] .. [2] // CurrentThreadID = 1 .. 3
    //delay_time[CurrentThreadID-2] = n;
    __asm \
        mov	r7,dpl \
        mov	a,_CurrentThreadID \
        add	a,#0xfe \
        add	a,#_delay_time \
        mov	r0,a \
        mov @r0, dpl \
        /*mov	@r0,ar7 \ */
    __endasm; \
    EA = 1;
}
unsigned char now(void){
    return Time/16; // (Time - Time%4)/4;
}

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

    TMOD = 0;
    IE = 0x82;
    TR0 = 1;

    Time = 0;
    for(int i=0;i<2;i++){
        spot[i] = 0;
    }
    for(int i=0;i<2;i++){
        delay_time[i] = 0;
    }
    for(int i=0;i<5;i++){
        car_leave_spot_time[i] = 0;
    }
    num_thread = 0;
    //SemaphoreCreate(num_thread, #0x03)//number thread
    CurrentThreadID = ThreadCreate(main);
    RESTORESTATE;
}
/*
* ThreadCreate() creates a thread data structure so it is ready
* to be restored (context switched in).
* The function pointer itself should take no argument and should
* return no argument.
*/

ThreadID ThreadCreate(FunctionPtr fp) /*__critical*/{
/*
* @@@ [2 pts]
* check to see we have not reached the max #threads.
* if so, return -1, which is not a valid thread ID.
*/

    //num_thread++;
    if(fp != main){
        SemaphoreWait(num_thread);
    }
    EA = 0;
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
/*
    if((bitmap_for_Thread & 0b00000001) == 0b00000000){
        // thread0 is not used
        bitmap_for_Thread = (bitmap_for_Thread | 0b00000001);
        created_ThreadID = 0;
        created_Thread_SP = 0x3F;
    }else
*/
    if((bitmap_for_Thread & 0x02) == 0x00){
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
        // clr psw
    __endasm;
    // f // g
    if(created_ThreadID == 0){
        //PSW = 0b00000000;
        __asm
            CLR A
            MOV PSW, #0x00
            PUSH PSW
        __endasm;

        saved_SP_Thread0 = SP;
    }else if(created_ThreadID == 1){
        // PSW = 0b00001000;
        __asm
            CLR A
            MOV PSW, #0x08
            PUSH PSW
        __endasm;

        saved_SP_Thread1 = SP;
    }else if(created_ThreadID == 2){
        PSW = 0b00010000;
        __asm
            // MOV PSW, #10H // 16dec = 10hex
            PUSH PSW
        __endasm;

        saved_SP_Thread2 = SP;
    }else{
        PSW = 0b00011000;
        __asm
            PUSH PSW
        __endasm;

        saved_SP_Thread3 = SP;
    }
    // h
    SP = temp_for_SP;
    // PSW: created thread -> current thread
    if(CurrentThreadID == 0){
        PSW = 0b00000000;
    }else if(CurrentThreadID == 1){
        PSW = 0b00001000;
    }else if(CurrentThreadID == 2){
        PSW = 0b00010000;
    }else{
        PSW = 0b00011000;
    }
    EA = 1;
    // i
    return created_ThreadID;
}


/*
* this is called by a running thread to yield control to another
* thread. ThreadYield() saves the context of the current
* running thread, picks another thread (and set the current thread
* ID to it), if any, and then restores its state.
*/

void ThreadYield(void) __critical{
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
void ThreadExit(void) /*__critical*/{
/*
* clear the bit for the current thread from the
* bit mask, decrement thread count (if any),
* and set current thread to another valid ID.
* Q: What happens if there are no more valid threads?
*/
    EA = 0;

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
        if(CurrentThreadID == 3){
            CurrentThreadID = 1;
            if((bitmap_for_Thread & 0x02)){ // test if free. if free, then can use // !=0x02 == ==0
                break;
            }
        }else if(CurrentThreadID == 1){ // main thread
            CurrentThreadID = 2;
            if(bitmap_for_Thread == 0){ //bitmap_for_Thread==0000

                    while(1); // the last thread to exit, enter an infinite loop
            }
            if(bitmap_for_Thread & 0x04){ // test if free // !=0x04 == ==0


                break;
            }
        }else if(CurrentThreadID == 2){
            CurrentThreadID = 3;
            if((bitmap_for_Thread & 0x08)){ // test if free // !=0x08 == ==0
                break;
            }
        }
        /*
        else{
            CurrentThreadID = 0;
            if((bitmap_for_Thread & 0x01) == 0){ // test if free // !=0x01 == ==0x00
                break;
            }
        }*/
        // test if free
    } while (1);
    RESTORESTATE;
    //num_thread--;
    SemaphoreSignal(num_thread);
    EA = 1;
}

void myTimer0Handler(void) { // igmore thread0 for AR7...AR0
    EA = 0;
    SAVESTATE;
    Time++; // 4 time, one time unit

    if(Time%16 == 0){
        for(int i=0;i<2;i++){
            if(delay_time[i]>0){ // mean thread[i+1]->car in spot
                delay_time[i]--;
            }
        }
    }
    do {
        if(CurrentThreadID == 1){
            CurrentThreadID = 2;
            if((bitmap_for_Thread & 0x04) != 0){ // test if free
                // is free
                break;
            }
        }else if(CurrentThreadID == 2){
            CurrentThreadID = 3;
            if((bitmap_for_Thread & 0x08) != 0){ // test if free
                // thread3 is free
                break;
            }
        }else{ // if CurrentThreadID == 3
            CurrentThreadID = 1;
            if((bitmap_for_Thread & 0x02) != 0){ // test if free
                // is free
                break;
            }
        }
/*
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
*/
    } while (1);
    RESTORESTATE;
    EA = 1;
    __asm
        reti
    __endasm;
}

