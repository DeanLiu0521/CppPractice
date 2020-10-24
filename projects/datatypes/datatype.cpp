#include <iostream>
using namespace std;

int main() {
  float f1=35e3;
  double d1=12E4;
  cout << f1 << "\n";
  cout << d1 << "\n";
  char mychar = 'A';
  cout << mychar << "\n";
  char mychar2 = 66;
  cout << mychar2 << "\n";
  string mystr;
  cout << "Please input a string: ";
  getline(cin, mystr);
  cout << "The input string is: " << mystr;
  int a;
  cout << "Please input a number: ";
  cin >> a;
  string result = (a<10) ? "a is less than 10" : "a is greater than 10";
  cout << result << "\n";

  return 0;
}