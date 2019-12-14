/******************************************************************************
 * File:         parent.c
 * Version:      1.4
 * Date:         2019-11-27
 * Author:       W. Meijer, M. van der Sluys, J.H.L. Onokiewicz, R.B.A. Elsinghorst, J.G. Rouland
 * Description:  OPS exercise 4: no idea what i am doing
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "displayFunctions.h"
#include <unistd.h>
#include <sys/resource.h>

int main(int argc, char *argv[])
{
  ErrCode err = NO_ERR;
  int inputChars = 0, niceIncr = 0, result = 0, prio = 0;
  pid_t pid; // fork status
  int which = PRIO_PROCESS;

  err = SyntaxCheck(argc, argv); // Check the command-line parameters
  if (err != NO_ERR)
  {
    DisplayError(err); // Print an error message
  }
  else
  {
    niceIncr = atoi(argv[3]); // string to int

    inputChars = argc - 4;
    //printf("nummer of chars is %d \n", inputChars);

    for (int iChild = 1; iChild <= inputChars; iChild++)
    {
      //printf("\n ronde %d", iChild);
      pid = fork();

      if (pid == -1)
      {
        // failed fork
        printf("fork error\n");
        exit(1);
      }
      else if (pid == 0)
      {
        //printf("[SON] pid %d from [PARENT] pid %d\n",getpid(),getppid());
        // code
        result = setpriority(which, pid, iChild * niceIncr);
        prio = getpriority(which, pid);
        if (!result)
        {
          printf("Child: nr%d with an nice value of %d and as char %s \n", iChild, prio, argv[iChild + 3]);
          //printf("dit wordt je command: ./display %s %s %s", argv[1], argv[2], argv[iChild + 3]);
          if (execlp("../ex02/display", "display", argv[1], argv[2], argv[iChild + 3], NULL))
          {
            //printf("\nyou suck");
            DisplayError(ERR_EX);

          }

          printf("\n");
        }
        else
        {
          printf("fail");
        }
        exit(0);
        //break;
      }
      else
      {
        //parent fork
        //printf("Parent: waiting for child to finish\n");
        //wait(NULL);
        //printf("Parent: child has finished\n");
      }
    }
    //printf("Parent: waiting for child to finish\n");
    wait(NULL);
    printf("Parent: All childeren have finished\n");
  }
  return 0;
}
