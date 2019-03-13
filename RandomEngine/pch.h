// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H
constexpr auto PI_VALUE = 3.141592653589;
#include <iostream>
#include <string>
#include <array>		
#include <sstream> 
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#include <math.h>
#include <stdexcept>
#include <chrono>



const bool isAlpha(const std::string&); //returns true if string contains spaces and alphabetical numbers only
const bool isAlphaStrict(const std::string&); // returns true if string contains alphabetical chars only
const bool isAlphaNum(const std::string&); // returns true if contains alphanum characters and spaces
const bool isAlphaNumStrict(const std::string&); //returns true if contains Alphanum + spaces

class RandEngine {
private:
	unsigned int theSeed;
	unsigned int unsignedLimit;

public:
	RandEngine(void);
	RandEngine(unsigned int customSeed);
	static void trueTest(void); //function to test ratios of true/false with current settings
	static void rangeTest(void); //test frequencies of random numbers from 1 to 5

	unsigned int trueRand(void); //returns random value from 0 to unsignedLimit
	unsigned int randRange(unsigned int lowerBound, unsigned int upperBound); //return rand value from lowerBound to upperBound (inclusive)
	unsigned int myRand(unsigned int upperBound) { return randRange(1, upperBound); } //return rand value from 1 to upperBound (inclusive)
	bool fiftyFifty(void);

};


void trueTest(void);
// TODO: add headers that you want to pre-compile here'

/*
conventional software engineering wiston says that to use an object of a calss, the client code needs
to know only
	- What member functions to call
	- What arguments to provide to each member function
	- What return type to expect from each member function

*/

#endif //PCH_H


