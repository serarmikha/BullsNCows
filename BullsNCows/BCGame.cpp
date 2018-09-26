#include "BCGame.h"

BCGame::BCGame()
{
	Reset();
}

void BCGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	const std::string GAME_WORD = "zebra";//TODO replace const with random selection from list of isograms

	currentTryNum = 0;
	maxTries = MAX_TRIES;
	hiddenWord = GAME_WORD;
}

int BCGame::GetMaxTries() const
{
	return maxTries;
}

int BCGame::GetCurrentTry() const
{
	return currentTryNum;
}


//determines if user's current input is the winning input
bool BCGame::IsWon(std::string guess) const
{
	return (guess == hiddenWord);
}

EInputStatus BCGame::CheckValid(std::string) const
{
	return EInputStatus::ok;//TODO make actual errors
}
//recieives valid guess, increments 
BCcount BCGame::GuessInput(std::string guess)
{
	//increment turn
	currentTryNum++;

	BCcount bullCowCount;

	//loop through all letters, and decide if bull or cow
	int wordSize = hiddenWord.size();
	for (int i = 0; i < wordSize; i++)
	{
		for (int j = 0; j < wordSize; j++)
		{
			if (guess[i] == hiddenWord[j])
			{
				if (i==j)
					bullCowCount.bulls++;
				else
				{
					bullCowCount.cows++;
				}
			}

		}
	}

	return bullCowCount;
}
