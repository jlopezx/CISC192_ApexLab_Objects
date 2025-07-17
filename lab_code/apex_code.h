/* File: apex_code.h
 * Project: Apex Lab 6 - Objects
 * Class: CISC 192 - C++
 * Professor: Alex Chow
 * Written by: Joshua Lopez
 * Description: This code declares member functions and fields for ZodiacSign class and Zodiac class.
 * Definitions can be foind in apex_code.cpp.
 * */
#ifndef APEXLAB_APEX_CODE_H
#define APEXLAB_APEX_CODE_H
#include <iostream>
#include <vector>

using namespace std;

class ZodiacSign
{
public:
	enum Months
	{
		INVALID_MONTH,
		JANUARY,
		FEBRUARY,
		MARCH,
		APRIL,
		MAY,
		JUNE,
		JULY,
		AUGUST,
		SEPTEMBER,
		OCTOBER,
		NOVEMBER,
		DECEMBER,
		NUM_MONTHS
	};

	string monthStrings[NUM_MONTHS] = {"INVALID", "January", "February", 
		"March", "April", "May", "June", "July", "August", "September",
	       	"October", "November", "December"};

	enum Elements
	{
		INVALID_ELEMENT,
		FIRE,
		WATER,
		EARTH,
		AIR,
		NUM_ELEMENTS
	};

	string elementsStrings[NUM_ELEMENTS] = {"INVALID", "FIRE", "WATER",
	       	"EARTH", "AIR"};

	// Declares a constructor w/ signature: string, ZodiacSign::Elements, string, ZodiacSign::Months
	ZodiacSign(const string& name, ZodiacSign::Elements element, const string& description, ZodiacSign::Months month);

	// Declares 3 accessors
	string GetName();
	ZodiacSign::Months GetMonth();
	void Print();

private:
	ZodiacSign();

	string name;
	Months month; 			// enum type
	Elements element;		// enum type
	string description;
};
// END ZodiacSign class

class Zodiac {
public:
	// Declares 3 mutators
	bool AddSign(const string& name, ZodiacSign::Elements element, const string& description, ZodiacSign::Months month);
	void Populate();
	void Clear();

	// Declares 1 accessor
	ZodiacSign GetMySign(ZodiacSign::Months month);
private:
	// A helper function to handle the logic of checking if sign parameters are valid
	bool isValidSign(const string& name, ZodiacSign::Elements element, ZodiacSign::Months month);

	// Declares a vector that holds ZodiacSign objects
	vector<ZodiacSign> signs;
};
// END Zodiac class

#endif //APEXLAB_APEX_CODE_H
