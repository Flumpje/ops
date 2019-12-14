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

// where it al happens
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        while(1)
        {
            kill(atoi(argv[1]), 25);
            printf("It is what it is\n");
            sleep(3);
        }
    } else {
        printf("You better give me a pid man!\n");
    }
}