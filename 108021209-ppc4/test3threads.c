// done for checkpoint4
/*
* file: testpreempt.c
*/
#include <8051.h>
#include "preemptive.h"
/*
* @@@ [2pt]
* declare your global variables here, for the shared buffer
* between the producer and consumer.
* Hint: you may want to manually designate the location for the
* variable. you can use
* __data __at (0x30) type var;
* to declare a variable var of the type
*/


__data __at (0x23) char P_C_buffer[3];
__data __at (0x26) char P_C_bufferisempty;
__data __at (0x27) char nextitem1;
__data __at (0x28) char mutex;
__data __at (0x29) char full;
__data __at (0x2A) char empty;
__data __at (0x2B) char in;
__data __at (0x2C) char out;
__data __at (0x2D) char nextitem2;
__data __at (0x2E) char turn; // turn==1->Producer1; turn==0->Producer2
__data __at (0x35) ThreadID CurrentThreadID;
/* [8 pts] for this function
* the producer in this test program generates one characters at a
* time from 'A' to 'Z' and starts from 'A' again. The shared buffer
* must be empty in order for the Producer to write.
*/
void Producer1(void) {
    /*
    * @@@ [2 pt]
    * initialize producer data structure, and then enter
    * an infinite loop (does not return)
    */
    nextitem1 = 'A';

    while (1) {
        /* @@@ [6 pt]
        * wait for the buffer to be available,
        * and then write the new data into the buffer */

        // P_C_bufferisempty == 1 // is empty
        //EA = 0;

if(turn == 0){
    continue;
}

        SemaphoreWait(empty);
        SemaphoreWait(mutex);
turn = 0;
            P_C_buffer[in] = nextitem1;
            in = (in+1)%3;
            //P_C_bufferisempty = 0; // not empty

            if(nextitem1 == 'Z'){
                nextitem1 = 'A';
            }else{
                nextitem1 ++ ;
            }
        // EA = 1;
        SemaphoreSignal(mutex);
        SemaphoreSignal(full);

    }
}

void Producer2(void) {
    /*
    * @@@ [2 pt]
    * initialize producer data structure, and then enter
    * an infinite loop (does not return)
    */
    nextitem2 = '0';

    while (1) {
        /* @@@ [6 pt]
        * wait for the buffer to be available,
        * and then write the new data into the buffer */

        // P_C_bufferisempty == 1 // is empty
        //EA = 0;

if(turn == 1){
    continue;
}

        SemaphoreWait(empty);
        SemaphoreWait(mutex);
turn = 1;
            P_C_buffer[in] = nextitem2;
            in = (in+1)%3;
            //P_C_bufferisempty = 0; // not empty

            if(nextitem2 == '9'){
                nextitem2 = '0';
            }else{
                nextitem2 ++ ;
            }
        // EA = 1;
        SemaphoreSignal(mutex);
        SemaphoreSignal(full);
    }
}

/* [10 pts for this function]
* the consumer in this test program gets the next item from
* the queue and consume it and writes it to the serial port.
* The Consumer also does not return.
*/
void Consumer(void) {
    /* @@@ [2 pt] initialize Tx for polling */
    TMOD |= 0x20;
    TH1 = -6;
    SCON = 0x50;
    TR1 = 1;

    while (1) {
        /* @@@ [2 pt] wait for new data from producer
        * @@@ [6 pt] write data to serial port Tx,
        * poll for Tx to finish writing (TI),
        * then clear the flag
        */
        //while(P_C_bufferisempty == 1){ // is empty
        //    // ThreadYield();
        //}
        // the buffer is not empty
        //EA = 0;
        SemaphoreWait(full);
        SemaphoreWait(mutex);
            SBUF = P_C_buffer[out];
            out = (out+1)%3;
            while(!TI){}
            TI = 0;
        //EA = 1;
        SemaphoreSignal(mutex);
        SemaphoreSignal(empty);

    }
}
/* [5 pts for this function]
* main() is started by the thread bootstrapper as thread-0.
* It can create more thread(s) as needed:
* one thread can act as producer and another as consumer.
*/
void main(void) {
/*
* @@@ [1 pt] initialize globals
* @@@ [4 pt] set up Producer and Consumer.
* Because both are infinite loops, there is no loop
* in this function and no return.
*/
    // initialize globals
    P_C_bufferisempty = 1;
    P_C_buffer[0]=0; P_C_buffer[1]=0; P_C_buffer[2]=0;
    SemaphoreCreate(mutex, #0x01);
    SemaphoreCreate(full, #0x00);
    SemaphoreCreate(empty, #0x03);
    in = 0;
    out = 0;
    turn = 1;
    // set up Producer() and Consumer()
    ThreadCreate(Producer1);
    ThreadCreate(Producer2);
    Consumer();
}
void _sdcc_gsinit_startup(void) {
    __asm
        ljmp _Bootstrap
    __endasm;
}
void _mcs51_genRAMCLEAR(void) {}
void _mcs51_genXINIT(void) {}
void _mcs51_genXRAMCLEAR(void) {}

void timer0_ISR(void) __interrupt(1){
    __asm
        ljmp _myTimer0Handler
    __endasm;
}
