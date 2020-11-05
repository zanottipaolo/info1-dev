#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{ 
  int num, max;

  max = 0;
  num = 1;

  while (num != 0)
  {
     cout << "Digit a number (digit 0 to exit): ";
     cin >> num;

     if (num > max)
        max = num;
  }
  
  cout << "\nThe max is " << max << "\n";

  return 0;
}
