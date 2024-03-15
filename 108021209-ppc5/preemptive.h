// checkpoint3 well done
/*
 * file: preemptive.h
 *
 * this is the include file for the cooperative multithreading
 * package.  It is to be compiled by SDCC and targets the EdSim51 as
 * the target architecture.
 *
 * CS 3423 Fall 2018
 */

#ifndef __PREEMPTIVE_H__
#define __PREEMPTIVE_H__

#define MAXTHREADS 4  /* not including the scheduler */
/* the scheduler does not take up a thread of its own */

#define CNAME(s) _ ## s
#define Clabel(label, b) label ## b
#define CClabel(label, b) Clabel(label, b)
#define newlabel CClabel(__COUNTER__, $)
#define SemaphoreCreate(s, n)\
{   __asm \
    MOV CNAME(s), n \
    __endasm; \
}
#define SemaphoreWaitBody(S, label) \
{   __asm \
label: \
        MOV ACC, CNAME(S) \
        JZ label \
        JB ACC.7, label \
        dec CNAME(S) \
    __endasm; \
}
#define SemaphoreWait(s){ SemaphoreWaitBody(s, newlabel)}
#define SemaphoreSignal(s)\
{   __asm \
        INC CNAME(s) \
    __endasm; \
}



typedef char ThreadID;
typedef void (*FunctionPtr)(void);

void delay(unsigned char n);
unsigned char now(void);

ThreadID ThreadCreate(FunctionPtr);
void ThreadYield(void);
void ThreadExit(void);

#endif // __PREEMPTIVE_H__
