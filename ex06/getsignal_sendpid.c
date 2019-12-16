/******************************************************************************
 * File:         getsignal.c
 * Version:      1.0
 * Date:         2019-12-14
 * Author:       W. Meijer
 * Description:  OPS exercise 5: To send or not to send. only one gets it
 ******************************************************************************/


// include crap
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

//ex06
#include <sys/stat.h>
#include <fcntl.h>

// define the truth
#define mySigNr 25
#define _XOPEN_SOURCE 500

//global stuff
char nummer = '0';

// proto
void newHandler(int sig);

// where it al happens
int main(int argc, char *argv[])
{
    struct sigaction act, oldact;
    int fd;
    pid_t pid = getpid(); 
    char stemessage[40] = "Ooit, ooit gaat het werken";
/*
    // define shr 
    memset(&act, '\0', sizeof(act));
    act.sa_handler = newHandler;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);

    // install SHR
    printf("%d\n",sigaction(SIGINT, &act, &oldact));
   */ 
    //print pid
    //printf("My pid is: %ld\n", (long)getpid());

    // Send pid through fifo
    mkfifo("PIDpipe", 0666);

    printf("1");
    fd = open("PIDpipe", O_WRONLY);


    printf("2");
    if (fd < 0) {
        printf("opening pipe faild\n");
    }
    
    // looping
    while(1)
    {
        //wite pid to fifo
        printf("im freaking looping right now\n");
        write(fd, &pid, sizeof(pid));
        sleep(1);
    }

    // close fifo
    close(fd);
    unlink("PIDpipe");

    // restore stuff
    sigaction(SIGINT, &oldact, NULL);

    return 0;
}

// SHR newHandler
void newHandler(int sig) 
{
    printf("Signal caught: %d\n", sig);
    nummer++;
}