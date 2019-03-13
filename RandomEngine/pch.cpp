
// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed
#include "pch.h"


const bool isAlpha(const std::string& testString) { //returns true if string contains spaces and alphabetical numbers only
	for (unsigned int i = 0; i < testString.length(); i++) {
		if (!isalpha(testString[i]) && (testString[i] != 32)) {
			std::cout << "Erroronous character: '" << testString[i] << "' on position " << 1 + i << " for string " << testString;
			return false;
		}

	}
	return true;
}

const bool isAlphaStrict(const std::string& testString) { // returns true if string contains alphabetical chars only
	for (unsigned int i = 0; i < testString.length(); i++) {
		if (!isalpha(testString[i])) {
			std::cout << "Erroronous character: '" << testString[i] << "' on position " << 1 + i << " for string " << testString;
			return false;
		}
	}
	return true;
}

const bool isAlphaNum(const std::string& testString) {// returns true if contains alphanum characters and spaces
	for (unsigned int i = 0; i < testString.length(); i++) {
		if (!isalnum(testString[i]) && (testString[i] != 32)) {
			std::cout << "Erroronous character: '" << testString[i] << "' on position " << 1 + i << " for string " << testString;
			return false;
		}

	}
	return true;
}

const bool isAlphaNumStrict(const std::string& testString) { //returns true if contains Alphanum + spaces
	for (unsigned int i = 0; i < testString.length(); i++) {
		if (!isalnum(testString[i]) && (testString[i] != 32)) {
			std::cout << "Erroronous character: '" << testString[i] << "' on position " << 1 + i << " for string " << testString;
			return false;
		}
	}
	return true;
}




MyRand::MyRand(void) {
	unsigned int i = 4000000000;
	unsigned int b;
	while (true) {//test to find largest unsigned int-ish
		b = i;
		i += 1111;
		if (i < b) {
			unsignedLimit = b/2;
			break;
		}
	}
}

MyRand::MyRand(unsigned int customSeed) 
	: theSeed(customSeed){
	MyRand();
}


unsigned int MyRand::trueRand(void) {
	while (theSeed > 10000) {
		theSeed /= 9;
	}
	theSeed *= 11111 % unsignedLimit;
	return theSeed;
}

bool MyRand::fiftyFifty(void) {
	return static_cast<bool>(trueRand()%2);
}

void MyRand::trueTest(void) {
	MyRand myEngine;
	unsigned int trueCounter{ 0 };
	unsigned int falseCounter{ 0 };
	for (unsigned int i = 0; i < 546; i++) {
		if (myEngine.fiftyFifty()) {
			trueCounter++;
		}
		else {
			falseCounter++;
		}
	}

	long double ratio = static_cast<long double>(trueCounter) / static_cast<long double>(falseCounter);
	std::cout << "falseCounter: " << falseCounter << std::endl
		<< "trueCounter: " << trueCounter << std::endl
		<< "ratio false to true is: " << ratio << std::endl;
}


// In general, ignore this file, but keep it around if you are using pre-compiled headers.
