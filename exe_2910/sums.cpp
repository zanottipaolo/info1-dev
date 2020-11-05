#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{  
  int num, sum;

  sum = 0;
  num = 1;

  while (num != 0) 
  {
      cout << "\n Digit a number (digit 0 to exit): ";
      cin >> num;
      sum = sum + num;
  }

  cout << "\nThe result is " << sum << endl << endl;

  return 0;
}
