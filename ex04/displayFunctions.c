/******************************************************************************
 * File:         displayFunctions.c
 * Version:      1.4
 * Date:         2018-02-20
 * Author:       M. van der Sluys, J.H.L. Onokiewicz, R.B.A. Elsinghorst, J.G. Rouland
 * Description:  OPS exercise 2:  function definitions for display.c
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "displayFunctions.h"
#include "syntaxCheck.h"

// Check the command-line parameters:
ErrCode SyntaxCheck(int argc, char **argv) {
  ErrCode errCode = NO_ERR;
  //errCode = TestType(argv[1]);                        // Test whether argument 1 has the correct value (print type)
   if(argc <= NUM_OF_PARS) {
    errCode = ERR_PARS;
  } else {
    if(errCode == NO_ERR) errCode = TestNr(argv[2]);    // Test whether argument 2 contains a positive integer (number of times)
    if(errCode == NO_ERR) errCode = TestNc(argv[3]);
  }
  //for (int i = 4; i < argc; i++){
  //    if(errCode == NO_ERR) errCode = TestChar(argv[i]);  // Test whether argument 4 and more contains only one character (print character)
  //}
  //return errCode;
}

// Print an error message:
void DisplayError(ErrCode errCode) {
  switch(errCode) {
  case ERR_PARS:
    printf("\nNumber of command-line parameters is less than four.\n");
    break;
  case ERR_NR:
    printf("\nNumber of times is not a positive integer.\n");
    break;
  case ERR_NC:
    printf("\nNice increment is not a positive integer.\n");
    break;
  case ERR_EX:
    printf("\nYour execl command or path is not working.\n");
    break;
  default:
    printf("\nUnknown error code!\n");
  }
  
  printf("\nCorrect syntax:\n");
  printf("  ./display <print type> <number of times> <nice increment> <print character 1> <print character n>\n\n");
  printf("  first parameter: <print type>: e, p or w\n");
  printf("  second parameter: <number of times>: positive integer\n");
  printf("  second parameter: <nice increment>: positive integer\n");
  printf("  third and more parameter(s): <print character>: a single character\n");
  printf("\n");  // Newline at end
}
