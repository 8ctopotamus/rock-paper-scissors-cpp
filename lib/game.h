#include <iostream>
#include "helpers.h"
#include "player.h"

using namespace std;

class Game {
  public:
    int numRounds = 1;
    bool gameOver = false;
    Player players[2];
    
    void compareChoices(string uC, string cC) 
    {
      string result;
      if ( 
        uC == "r" && cC == "s" ||
        uC == "p" && cC == "r" ||
        uC == "s" && cC == "p" 
      ) 
      {
        // wins++;
        result = "won";
      } else if (uC == cC)
      {
        // ties++;
        result = "tied";
      } else 
      {
        // losses++;
        result = "lost";
      }
      cout << "Round " << result << "!" << endl;
      numRounds++;
    }

    bool askToQuit() 
    {
      cout << "Press q to quit or any other key to keep playing: " << endl;
      string choice;
      cin >> choice;
      return toLowerCase(choice) == "q";
    }

    // void check4GameOver()
    // {
    //   if (wins == 3 || losses == 3 || ties == 3) {
    //     string result;
    //     if (wins == 3)
    //       result = "WON";
    //     else if (ties == 3)
    //       result = "TIED";
    //     else
    //       result = "LOST";
    //     cout << "GAME OVER! YOU " << result << "!" << endl;
    //     bool shouldQuit = askToQuit();
    //     if (shouldQuit) 
    //     {
    //       gameOver = true;
    //       cout << "See ya!" << endl;
    //     }
    //     else
    //     {
    //       cout << "Keep on rockin'!" << endl;
    //     }
    //   }
    // }

    // void rpsRound() 
    // {
    //   cout << "!!! ROUND " << numRounds << " !!!" << endl;
    //   string uC = getUserChoice();
    //   string cC = getComputerChoice();
    //   compareChoices(uC, cC);
    //   check4GameOver();
    // }


  // while (!gameOver) 
  // {
  //   rpsRound();
  // }
  
};