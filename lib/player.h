#include <iostream>
#include "helpers.h"

using namespace std;

class Player {
  public:
    bool isHuman;
    string name;
    string choice;
    int lives = 3;

    Player(string n, bool h) {
      name = n;
      isHuman = h;
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
};