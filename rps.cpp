#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string choices[3] = { "r", "p", "s" };
bool gameOver = false;
int numRounds = 1;
int wins = 0;
int losses = 0;
int ties = 0;

string toLowerCase(string s) 
{
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}

bool isValidChoice(string choice)
{
  return find(begin(choices), end(choices), choice) != end(choices);
}

string getUserChoice() 
{
  string choice;
  bool awaitingValidChoice = true;
  while (awaitingValidChoice)
  {
    printf("Choose r, p, s: ");
    cin >> choice;
    toLowerCase(choice);
    cout << "You chose " + choice << endl;
    awaitingValidChoice = !isValidChoice(choice);
  }
  return choice;
}

string getComputerChoice()
{
  int randIdx = rand() % 2;
  string choice = choices[randIdx];
  cout << "Computer chose: " + choice << endl;
  return choice;
}

bool askToQuit() {
  cout << "Press q to quit: " << endl;
  string choice;
  cin >> choice;
  if (toLowerCase(choice) == "q")
  {
    return true;
  }
  return false;
}

bool rpsRound() 
{
  string uC = getUserChoice();
  string cC = getComputerChoice();
  // compare choices
  // update score
  // check 4 gameover
  numRounds++;
  bool shouldQuit = askToQuit();
  if (shouldQuit) return true;
  return false;
}

main()
{
  while (!gameOver) 
  {
    gameOver = rpsRound();
  }
  cout << "Bye!";
  return 0;
}