#include <iostream>
#include <string>

using namespace std;

string choices[3] = { "r", "p", "s" };

main()
{
  string userChoice;
  cout << "Choose r, p, s" << endl;
  cin >> userChoice;
  
  cout << "You chose: " + userChoice << endl;

  system("pause");
  return 0;
}