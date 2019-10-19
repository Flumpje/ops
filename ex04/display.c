/******************************************************************************
 * File:         display.c
 * Version:      1.4
 * Date:         2018-02-20
 * Author:       M. van der Sluys, J.H.L. Onokiewicz, R.B.A. Elsinghorst, J.G. Rouland
 * Description:  OPS exercise 3: no idea what i am doing
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "displayFunctions.h"
#include <unistd.h>
#include <sys/resource.h>


int main(int argc, char *argv[]) {
  unsigned long int numOfTimes;
  char printMethod, printChar;
  ErrCode err = NO_ERR;
  int inputChars = 0, niceIncr = 0, iChild = 0, result = 0, prio = 0;
  pid_t pid; // fork status
  int which = PRIO_PROCESS;
  
  //err = SyntaxCheck(argc, argv);  // Check the command-line parameters
  if(err != NO_ERR) {
    DisplayError(err);        // Print an error message
  } else {
    printMethod = argv[1][0];
    numOfTimes = strtoul(argv[2], NULL, 10);  // String to unsigned long
    printChar = argv[4][0];
    niceIncr = atoi(argv[3]); // string to int

    inputChars = argc - 4;
    //printf("nummer of chars is %d \n", inputChars);
    
    for (int iChild = 1; iChild <= inputChars; iChild++)
    {
      //printf("\n ronde %d", iChild);
      pid = fork();


      if (pid) {
	; // parrent fork
        } else if(pid == 0) {
	//printf("[SON] pid %d from [PARENT] pid %d\n",getpid(),getppid());
            // code
	    result = setpriority(which, pid, iChild*niceIncr);
	    prio = getpriority(which, pid);
	    if (!result) {
	      printf("child nr%d with an nice value of %d and as last char %s \n", iChild, prio, argv[iChild]);
	    PrintCharacters(printMethod, numOfTimes, argv[3+iChild][0]);
	    } else {
	      printf("fail");
	    }
	      
            exit(0);
            //break;
        }
        else {
            printf("fork error\n");
            exit(1);
        }
      wait(NULL);
      
    }
  }
  
  printf("\n");  // Newline at end

  return 0;
}
