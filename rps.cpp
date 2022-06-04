#include <iostream>
#include <string>

using namespace std;

string choices[3] = { "r", "p", "s" };
int wins = 0;
int losses = 0;
int ties = 0;

bool isValidChoice(string choice)
{
  return find(begin(choices), end(choices), choice) != end(choices);
}

string getUserChoice() 
{
  printf("Choose r, p, s");
  string choice;
  cin >> choice;
  cout << "You chose " + choice << endl;
  return choice;
}

main()
{
  string userChoice;
  cout << "Choose r, p, s" << endl;
  
  
  cout << "You chose: " + userChoice << endl;

  system("pause");
  return 0;
}