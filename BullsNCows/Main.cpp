#include <iostream>
#include <string>
#include "BCGame.h"

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool PlayAgainRequest();

int main() {

	bool playAgain = false;
	


	do {

	} while (playAgain);

	PlayGame();

	//TODO Summarize Game


}


void PrintIntro() {
	cout << "This is a game" << endl;



}

void PlayGame()
{
	BCGame BullCow;
	
	int maxTries = BullCow.GetMaxTries();

	for (int i = 0; i <= maxTries; i++)
	{
		string guess = GetGuess(); //TODO validate guess input

		cout << "Your Guess Was: " << guess << endl;
		BCcount count = BullCow.GuessInput(guess);
		cout << "Bulls: " << count.bulls << endl;
		cout << "Cows: " << count.cows << endl;
	}

}

string GetGuess()
{
	string guess = "none";

	cout << "input plz" << endl;
	cin >> guess;

	return guess;
}