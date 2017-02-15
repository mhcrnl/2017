/*
  Simple hangman game
    Do not use caps
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
  cout << "Enter the word for other player to guess" << endl;

  string word;
  getline(cin, word);

  string copy = word;

  string Underscore;

  for(int i=0; i!=word.length(); i++){

    if(word.at(i) == ' '){
      Underscore += " ";
    } else{
      Underscore += "_";
    }
  }

  for(int i=0; i!=50; ++i){
    cout << endl;
  }

  string guess;
  int wrong=0;

  while(1){
    if(wrong == 6){
      cout << "You Lose! The word was: " << word << endl;
      break;
    }

    cout << Underscore << endl;
    cout << "There are " << word.length() << " letters with spaces" << endl;
    cout << "You have " << 6 - wrong << " more tries left" << endl;

    if(Underscore == word){
      cout << "You win!" << endl;
      break;
    }

    cout << "Guess a letter or a word" << endl;
    getline(cin, guess);

    if(guess.length() > 1){
      if(guess == word){
        cout << "That's right, you win!" << endl;
        break;
      } else{
        cout << "wrong word " << endl;
        wrong++;
      }
    } else if(copy.find(guess) != -1){
        while(copy.find(guess) != -1){
          Underscore.replace(copy.find(guess), 1, guess);
          copy.replace(copy.find(guess), 1, "_");
        }
    } else{
      cout << "That's wrong" << endl;
      wrong++;
    }

    cout << endl;
  }
  return 0;
}
