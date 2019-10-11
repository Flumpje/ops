#include <iostream.h>
#include <getopt.h>

#define no_argument 0
#define required_argument 1 
#define optional_argument 2


int main(int argc, char * argv[])
{
  std::cout << "Hello" << std::endl;

  const struct option longopts[] =
  {
    {"version",   no_argument,        0, 'v'},
    {"help",      no_argument,        0, 'h'},
    {"stuff",     required_argument,  0, 's'},
    {0,0,0,0},
  };

  int index;
  int iarg=0;

  //turn off getopt error message
  opterr=1; 

  while(iarg != -1)
  {
    iarg = getopt_long(argc, argv, "svh", longopts, &index);

    switch (iarg)
    {
      case 'h':
        std::cout << "You hit help" << std::endl;
        break;

      case 'v':
        std::cout << "You hit version" << std::endl;
        break;

      case 's':
        std::cout << "You hit stuff" << std::endl;
        break;
    }
  }

  std::cout << "GoodBye!" << std::endl;

  return 0; 
}
