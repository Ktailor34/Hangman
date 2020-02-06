#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <time.h>

using namespace std;

string generateRandomWord (vector<string> wordBank) {
  srand(time(NULL));
  int random = rand() % 5;
  return wordBank[random];
}

int main() {
  vector<string> wordBank{ "hello","world","banana","beta","cookies"};
  int lives = 5;
  int checkCorrect = 0;
  char guess;
  set<char> usedChars;
  bool guessFlag = false;

  string pickedString = generateRandomWord(wordBank);
  string hidden (pickedString.length(), 'X');

  cout << "Here is your hidden string: " << hidden << endl;

  while (lives > 0) {
    cout << "Please input your next guess (chars only)" << endl;
    cin >> guess;
    guess = tolower(guess);

    if(usedChars.find(guess) != usedChars.end()){
      cout << "duplicate character" << endl;
    }
    else {
    usedChars.insert(guess);

    for (int i = 0; i < pickedString.length(); i++) {
      if(guess == pickedString[i]) {
        checkCorrect +=1;
        if(guessFlag == false) {
          cout << "guess successful!" << endl;
        }
        hidden[i] = guess;
        guessFlag = true;
      }
    }
    if (guessFlag == false) {
      cout << "incorrect guess! You lost a life" << endl;
      lives -= 1;
    }
    if (lives == 0) {
      cout << "No more lives! YOU LOSE" << endl;
      break;
    }

    if (checkCorrect == pickedString.length()) {
      cout << "YOU WIN" << endl;
      cout << "Word was: " << hidden << endl;
      break;
    }
    guessFlag= false;
    cout << "after guess string is: " << hidden << endl;
    cout << "amount of lives: " << lives << endl << endl;
  }
  }
}