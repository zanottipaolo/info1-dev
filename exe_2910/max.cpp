#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
  int num1, num2;

  cout << "\nMax from 2 numbers\n\n";
  cout << "Digit the first number \n\n";
  cout << "First number: ";
  cin >> num1;
  cout << "Second number: ";
  cin >> num2;

  if (num1 > num2)
     cout << "\n" << num1 << " is greater than " << num2 << "\n\n";
  else {
     cout << "\n" << num1 << " is less or equal than ";
     cout << num2 << "\n\n";
  }
  
  return 0;
}
