/******************************************************************************
 * File:         sendsignal.c
 * Version:      1.0
 * Date:         2019-12-14
 * Author:       W. Meijer
 * Description:  OPS exercise 5: To send or not to send. only one gets it
 ******************************************************************************/
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// define the signal
#define TheSignal 25

// where it al happens
int main(int argc, char *argv[])
{
    pid_t pid;
    int fd;

    // get pid from fifo
    //open fifo

    if(fd < 0) {
        printf("opening PIDpipe failed");
    } else {
        // read pid from fifo
        // close fifo
    }

    // send TheSignal every 3 seconds
    while(1)
    {
        kill(pid, TheSignal);
        printf("It is what it is\n");
        sleep(3);
    }
}