#pragma once
#include <string>

struct BCcount
{
	int bulls = 0;
	int cows = 0;

};

enum class EInputStatus
{
	ok,
	not_iso,
	too_long,
	too_short,
	not_lowercase
};

class BCGame {
public:
	BCGame(); //Constructor
	//~BCGame();


	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsWon(std::string guess) const; 

	void Reset(); ///TODO make a more riche return value
	EInputStatus CheckValid(std::string guess) const; //TODO make a richer return value
	
	//counts Bulls and Cows, increases tries
	BCcount GuessInput(std::string); 

private:
	int currentTryNum;
	int maxTries;

	std::string hiddenWord;//TODO initialize somewhere

	bool IsIsogram(std::string word) const; //TODO write function that checks if input is an Isogram
	

};