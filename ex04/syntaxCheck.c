/******************************************************************************
 * File:         syntaxCheck.c
 * Version:      1.4
 * Datum:        2018-02-20
 * Author:       M. van der Sluys, J.H.L. Onokiewicz, R.B.A. Elsinghorst, J.G. Rouland
 * Description:  OPS exercise 2:  definitions of test functions for display.c
 ******************************************************************************/

#include <stdlib.h>
#include "syntaxCheck.h"


// Test whether an argument contains a non-negative number:
ErrCode TestNr(char *numberOfTimes) {
  ErrCode fout = NO_ERR;

  // if negative sign trow fault
  if (*numberOfTimes == '-')  fout = ERR_NR;
  
  return fout;
}

// Test whether an argument contains a non-negative number:
ErrCode TestNc(char *numberOfTimes) {
  ErrCode fout = NO_ERR;

  // if negative sign trow fault
  if (*numberOfTimes == '-')  fout = ERR_NC;
  
  return fout;
}