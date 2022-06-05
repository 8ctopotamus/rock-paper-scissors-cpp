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
    if (awaitingValidChoice) 
    {
      cout << "try again" << endl;
    }
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

// compare choices and update score
void compareChoices(string uC, string cC) {
  string result;
  if ( 
    uC == "r" && cC == "s" ||
    uC == "p" && cC == "r" ||
    uC == "s" && cC == "p" 
  ) 
  {
    wins++;
    result = "won";
  } else if (uC == cC)
  {
    ties++;
    result = "tied";
  } else 
  {
    losses++;
    result = "lost";
  }
  cout << "Round " << result << "!" << endl;
  printf("Score: WINS: %i | TIES: %i | LOSSES: %i\n", wins, ties, losses);
  numRounds++;
}

bool askToQuit() 
{
  cout << "Press q to quit or any other key to keep playing: " << endl;
  string choice;
  cin >> choice;
  return toLowerCase(choice) == "q";
}

void check4GameOver()
{
  if (wins == 3 || losses == 3 || ties == 3) {
    string result;
    if (wins == 3)
      result = "WON";
    else if (ties == 3)
      result = "TIED";
    else
      result = "LOST";
    cout << "GAME OVER! YOU " << result << "!" << endl;
    bool shouldQuit = askToQuit();
    if (shouldQuit) 
    {
      gameOver = true;
      cout << "See ya!" << endl;
    }
    else
    {
      cout << "Keep on rockin'!" << endl;
    }
  }
}

void rpsRound() 
{
  cout << "!!! ROUND " << numRounds << " !!!" << endl;
  string uC = getUserChoice();
  string cC = getComputerChoice();
  compareChoices(uC, cC);
  check4GameOver();
}

main()
{
  while (!gameOver) 
  {
    rpsRound();
  }
  return 0;
}