// done for checkpoint5 // should // done add semaphore for #thread <- check
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

// free
__data __at (0x23) char car_get_spot_time[5]; // 0x23~0x27
__data __at (0x28) char car_leave_spot_time[5]; // 0x28~0x2C
__data __at (0x3B) char car_spot[5]; // 0x3B~0x3F
__data __at (0x39) char delay_time[2]; // 0x39~0x3A
__data __at (0x38) char i;
__data __at (0x37) char num_thread;
__data __at (0x36) char mutex;
//char turn; // turn==1->Producer1; turn==0->Producer2
__data __at (0x2D) char Time; // Time=n -> n time unit
__data __at (0x2E) char spot[2]; // range:0->none; 1->have car -> 0000~0100
__data __at (0x35) ThreadID CurrentThreadID;
/* [8 pts] for this function
* the producer in this test program generates one characters at a
* time from 'A' to 'Z' and starts from 'A' again. The shared buffer
* must be empty in order for the Producer to write.
*/

int cmp(char * a, char b){
    return (*a==b);
}

void Car0(void) {
    /*
    * @@@ [2 pt]
    * initialize producer data structure, and then enter
    * an infinite loop (does not return)
    */
    while (1) {
        while(delay_time[CurrentThreadID-2]!=0);
        // delay[1] == 0
        // exter spot
        // find a free spot
        SemaphoreWait(mutex);
        for(i=0;i<2;i++){
            //spot[i] = 0x07;
            //if(spot[i]=='_'){ // wrong way
            if(!spot[i] && !car_spot[0]){ // correct way
                // car1 -> spot[i]
                spot[i] = 1;
                car_spot[0] = i+1;
                car_get_spot_time[0] = now();
                delay(12);
                break;
            }
        }
        // exit spot
        if(delay_time[CurrentThreadID-2]==0 && (spot[car_spot[0]-1]) && !car_leave_spot_time[0]){
            //spot[car_spot[0]]!=0x07 <-> spot[car_spot[0]]&0x07 != 0x07
            // can exit
            spot[car_spot[0]-1] = 0;
            car_leave_spot_time[0] = now();
            //car_spot[0]--;
            SemaphoreSignal(mutex);
            ThreadExit();
          //  break;
        }else{
            SemaphoreSignal(mutex);
        }
        //SemaphoreSignal(mutex);
    }
    //while(1);
}

void Car1(void) {
    /*
    * @@@ [2 pt]
    * initialize producer data structure, and then enter
    * an infinite loop (does not return)
    */
    while (1) {
        while(delay_time[CurrentThreadID-2]!=0); // still wating for time
        // delay[1] == 0
        SemaphoreWait(mutex);

        // exter spot
        // find a free spot

        for(i=0;i<2;i++){
            if(!spot[i] && !car_spot[1]){ // correct way
                // car1 -> spot[i]
                spot[i] = 1;
                car_spot[1] = i+1;
                car_get_spot_time[1] = now();
                delay(4);
                break;
            }
        }

        // exit spot
        if(delay_time[CurrentThreadID-2]==0 && spot[car_spot[1]-1] && !car_leave_spot_time[1]){
            // can exit
            spot[car_spot[1]-1] = 0;
            car_leave_spot_time[1] = now();
            //car_spot[1]--;
            SemaphoreSignal(mutex);
            ThreadExit();
           // break;
        }else{
            SemaphoreSignal(mutex);
        }

        //SemaphoreSignal(mutex);
    }
   // while(1);
}

void Car2(void) {
    /*
    * @@@ [2 pt]
    * initialize producer data structure, and then enter
    * an infinite loop (does not return)
    */
    while (1) {
        while(delay_time[CurrentThreadID-2]!=0);
        // delay[1] == 0
        // exter spot
        // find a free spot
        SemaphoreWait(mutex);
        for(i=0;i<2;i++){
            if(!spot[i] && !car_spot[2]){ // correct way
                // car1 -> spot[i]
                spot[i] = 2;
                car_spot[2] = i+1;
                car_get_spot_time[2] = now();
                delay(1);
                break;
            }
        }
        // exit spot
        if(delay_time[CurrentThreadID-2]==0 && spot[car_spot[2]-1] && !car_leave_spot_time[2]){
            // can exit
            spot[car_spot[2]-1] = 0;
            car_leave_spot_time[2] = now();
            //car_spot[2]--;
            SemaphoreSignal(mutex);
            ThreadExit();
            //break;
        }else{
            SemaphoreSignal(mutex);
        }
        //SemaphoreSignal(mutex);
    }
    //while(1);
}

void Car3(void) {
    /*
    * @@@ [2 pt]
    * initialize producer data structure, and then enter
    * an infinite loop (does not return)
    */
    while (1) {
        while(delay_time[CurrentThreadID-2]!=0);
        // delay[1] == 0
        // exter spot
        // find a free spot
        SemaphoreWait(mutex);
        for(i=0;i<2;i++){
           if(!spot[i] && !car_spot[3]){ // correct way
                // car1 -> spot[i]
                spot[i] = 3;
                car_spot[3] = i+1;
                car_get_spot_time[3] = now();
                delay(7);
                break;
            }
        }

        // exit spot
        if(delay_time[CurrentThreadID-2]==0 && spot[car_spot[3]-1] && !car_leave_spot_time[3]){
            // can exit
            spot[car_spot[3]-1] = 0;
            car_leave_spot_time[3] = now();
            //car_spot[3]--;
            SemaphoreSignal(mutex);
            ThreadExit();
            //break;
        }else{
            SemaphoreSignal(mutex);
        }

    }
    //while(1);
}

void Car4(void){
    /*
    * @@@ [2 pt]
    * initialize producer data structure, and then enter
    * an infinite loop (does not return)
    */
    while (1) {
        while(delay_time[CurrentThreadID-2]!=0);
        // delay[1] == 0
        // exter spot
        // find a free spot
        SemaphoreWait(mutex);
        for(i=0;i<2;i++){
            if(!spot[i] && !car_spot[4]){ // correct way
                // car1 -> spot[i]
                spot[i] = 4;
                car_spot[4] = i+1;
                car_get_spot_time[4] = now();
                delay(2);
                break;
            }
        }
        // exit spot
        if(delay_time[CurrentThreadID-2]==0 && spot[car_spot[4]-1] && !car_leave_spot_time[4]){
            // can exit
            spot[car_spot[4]-1] = 0;
            car_leave_spot_time[4] = now();
            //car_spot[4]--;
            SemaphoreSignal(mutex);
            ThreadExit();
            //break;
        }else{
            SemaphoreSignal(mutex);
        }
        //SemaphoreSignal(mutex);
    }
    //while(1);
}

/* [10 pts for this function]
* the consumer in this test program gets the next item from
* the queue and consume it and writes it to the serial port.
* The Consumer also does not return.
*/
/*
void Consumer(void) {

    TMOD |= 0x20;
    TH1 = -6;
    SCON = 0x50;
    TR1 = 1;

    while (1) {

        //while(P_C_bufferisempty == 1){ // is empty
        //    // ThreadYield();
        //}
        // the buffer is not empty
        //EA = 0;
        //SemaphoreWait(full);
        //SemaphoreWait(mutex);

            SBUF = P_C_buffer[out];
            out = (out+1)%3;
            while(!TI){}
            TI = 0;

        //EA = 1;
        //SemaphoreSignal(mutex);
        //SemaphoreSignal(empty);

    }
}
*/

/* [5 pts for this function]
* main() is started by the thread bootstrapper as thread-0.
* It can create more thread(s) as needed:
* one thread can act as producer and another as consumer.
*/

void print_human_readable_text(void);

void main(void) {
/*
* @@@ [1 pt] initialize globals
* @@@ [4 pt] set up Producer and Consumer.
* Because both are infinite loops, there is no loop
* in this function and no return.
*/
    // initialize globals
    SemaphoreCreate(mutex, #0x01);
    SemaphoreCreate(num_thread, #0x02)//number thread

    //while(num_thread >= 3); // break -> exist 1 thread
    ThreadCreate(Car0);
    // while(num_thread >= 3);
    ThreadCreate(Car1);
     //while(num_thread >= 3);
    ThreadCreate(Car2);
     //while(num_thread >= 3);
    ThreadCreate(Car3);
     //while(num_thread >= 3);
    ThreadCreate(Car4);
     //while(num_thread >= 3);
    //Consumer();
    //while(num_thread>=3); // maybe>=1?

    while(num_thread<2);
    // num of thread == 2 // main is final thread, other thread exit
    //print human-readable text format
    print_human_readable_text();

    ThreadExit();
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



void print_human_readable_text(void){

    TMOD |= 0x20;
    TH1 = -6;
    SCON = 0x50;
    TR1 = 1;

    for(i=0;i<5;i++){
        SBUF = 'c'; while(!TI){} TI = 0;

        SBUF = 'a'; while(!TI){} TI = 0;

        SBUF = 'r'; while(!TI){} TI = 0;

        SBUF = ' '; while(!TI){} TI = 0;

        SBUF = i+0x30;
        while(!TI){}
        TI = 0;

        SBUF = ' '; while(!TI){} TI = 0;

        SBUF = 'g'; while(!TI){} TI = 0;

        SBUF = 'o'; while(!TI){} TI = 0;

        SBUF = 't'; while(!TI){} TI = 0;

        SBUF = ' '; while(!TI){} TI = 0;

        SBUF = 's'; while(!TI){} TI = 0;

        SBUF = 'p'; while(!TI){} TI = 0;

        SBUF = 'o'; while(!TI){} TI = 0;

        SBUF = 't'; while(!TI){} TI = 0;

        mutex = car_spot[i];
        mutex = mutex+0x30;
        SBUF = mutex;
        while(!TI){}
        TI = 0;

        SBUF = ' '; while(!TI){} TI = 0;

        SBUF = 'a'; while(!TI){} TI = 0;

        SBUF = 't'; while(!TI){} TI = 0;

        SBUF = ' '; while(!TI){} TI = 0;

        mutex = car_get_spot_time[i];
        if(mutex>=0 && mutex<=9){
            mutex = mutex + 0x30;
        }else{
            mutex = mutex + 0x37;
        }
        SBUF = mutex;
        while(!TI){}
        TI = 0;

        SBUF = ' '; while(!TI){} TI = 0;

        SBUF = 'a'; while(!TI){} TI = 0;

        SBUF = 'n'; while(!TI){} TI = 0;

        SBUF = 'd'; while(!TI){} TI = 0;

        SBUF = ' '; while(!TI){} TI = 0;

        SBUF = 'l'; while(!TI){} TI = 0;

        SBUF = 'e'; while(!TI){} TI = 0;

        SBUF = 'f'; while(!TI){} TI = 0;

        SBUF = 't'; while(!TI){} TI = 0;

        SBUF = ' '; while(!TI){} TI = 0;

        SBUF = 'a'; while(!TI){} TI = 0;

        SBUF = 't'; while(!TI){} TI = 0;

        SBUF = ' '; while(!TI){} TI = 0;

/*
        SBUF = (car_leave_spot_time[i]/16)+0x30;
        while(!TI){}
        TI = 0;
*/
        //mutex = car_leave_spot_time[i];  //%16;  // car_leave_spot_time[i]&0x0F;
        //mutex = mutex%16;
/*
        __asm \
            mov	ar6,_Time//mov	r6,_Time
            anl	ar6,#0x0f  // anl	ar6,#0x0f
            mov	_mutex,ar6//  mov	_Time,r6
        __endasm; \
*/
        mutex = car_leave_spot_time[i];
        if(mutex>=0 && mutex<=9){
            mutex = mutex + 0x30;
        }else{
            mutex = mutex + 0x37;
        }
        SBUF = mutex;
        while(!TI){}
        TI = 0;

        SBUF = '.'; while(!TI){} TI = 0;

        SBUF = '\n'; while(!TI){} TI = 0;
    }


}
