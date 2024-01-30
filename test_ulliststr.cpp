#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{

  ULListStr list;

  list.push_back("a");

  

  std::cout << "pos 0 " << list.get(0) << std::endl;
  
  list.pop_back();

  std::cout << "pos 0 " << list.get(0) << std::endl;

}
