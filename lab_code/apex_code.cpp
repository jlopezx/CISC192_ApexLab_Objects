/* File: apex_code.cpp
 * Project: Apex Lab 6 - Objects
 * Class: CISC 192 - C++
 * Professor: Alex Chow
 * Written by: Joshua Lopez
 * Description: This file defines member functions for ZodiacSign class and Zodiac class. These functions
 * are a mixture of a constructor, accessors and mutators. ZodiacSign builds a ZodiacSign object with a
 * name, element, description and month. The Zodiac class takes these ZodiacSign objects and stores them
 * in a vector array using the vector class.
 * */
#include "apex_code.h"

// Defines the ZodiacSign constructor that builds its object using 4 parameters.
ZodiacSign::ZodiacSign(const string& name, ZodiacSign::Elements element, const string& description, ZodiacSign::Months month) {
	// Using the this pointer to make it clear I'm accessing the member function given I made the parameter
	// names similar.
	this->name = name;
	this->element = element;
	this->description = description;
	this->month = month;
}

// Defines ZodiacSign member function GetName(). Simply returns the private string name variable.
string ZodiacSign::GetName(){
	return name;
}

// Defines ZodiacSign member function GetMonth(). Simply returns the private enum month variable.
ZodiacSign::Months ZodiacSign::GetMonth(){
	return month;
}

// Defines the ZodiacSign member function, Print(). Outputs the 4 variables that make up a ZodiacSign object
void ZodiacSign::Print() {
	cout << name << endl;
	cout << "\tMonth: " << monthStrings[month] << endl;
	cout << "\tElement: " << elementsStrings[element] << endl;
	cout << "\t" << description << endl;
}

// Defines the Zodiac member function, Populate(). It adds 12 ZodiacSign objects to my vector, signs.
void Zodiac::Populate() {
  AddSign("CAPRICORN", ZodiacSign::Elements::EARTH, "The mountain goat",
          ZodiacSign::Months::JANUARY);
  AddSign("AQUARIUS", ZodiacSign::Elements::AIR, "The water-bearer",
          ZodiacSign::Months::FEBRUARY);
  AddSign("PISCES", ZodiacSign::Elements::WATER, "Two fish",
          ZodiacSign::Months::MARCH);
  AddSign("ARIES", ZodiacSign::Elements::FIRE, "The ram",
          ZodiacSign::Months::APRIL);
  AddSign("TAURUS", ZodiacSign::Elements::EARTH, "The bull",
          ZodiacSign::Months::MAY);
  AddSign("GEMINI", ZodiacSign::Elements::AIR, "The twins",
          ZodiacSign::Months::JUNE);
  AddSign("CANCER", ZodiacSign::Elements::WATER, "The crab",
          ZodiacSign::Months::JULY);
  AddSign("LEO", ZodiacSign::Elements::FIRE, "The lion",
          ZodiacSign::Months::AUGUST);
  AddSign("VIRGO", ZodiacSign::Elements::EARTH, "The maiden",
          ZodiacSign::Months::SEPTEMBER);
  AddSign("LIBRA", ZodiacSign::Elements::AIR, "The scales",
          ZodiacSign::Months::OCTOBER);
  AddSign("SCORPIO", ZodiacSign::Elements::WATER, "The scoprion",
          ZodiacSign::Months::NOVEMBER);
  AddSign("SAGITTARIUS", ZodiacSign::Elements::FIRE, "The archer",
          ZodiacSign::Months::DECEMBER);
}

// Defines a Zodiac member function, AddSign(), takes in 4 parameters that make up a ZodiacSign object
bool Zodiac::AddSign(const string& name, ZodiacSign::Elements element, const string& description, ZodiacSign::Months month) {
	// Calls the isValidSign() helper function to validate the signs are within range of valid values
	// checks there aren't any duplicate names or months, if true, it will add a new ZodiacSign object
	// with the passed in values to signs vector and return true, else it will return false.
	return isValidSign(name, element, month) ?
	       (signs.push_back(ZodiacSign(name, element, description, month)), true) :
	       false;
}

// Defines the Zodiac member function, GetMySign(), with parameter ZodiacSign::Months month which is an enum.
ZodiacSign Zodiac::GetMySign(ZodiacSign::Months month) {
	// Loops through my signs vector, finds any ZodiacSign object with a month equal to month passed in.
	// If true, then it will return that ZodiacSign object.
	for (int i = 0; i < signs.size(); ++i) {
		if (signs.at(i).GetMonth() == month) {
			return signs.at(i);
		}
	}
	// If the program steps here, it means it did not find a matching object and returns an invalid object.
	return ZodiacSign("None", ZodiacSign::INVALID_ELEMENT, "None", ZodiacSign::INVALID_MONTH);
}

// Defines the Zodiac member function, isValidSign(), which checks if a sign is within a valid month and
// element range, and has no duplicate name or month. It will return true if it meets those conditions.
bool Zodiac::isValidSign(const string& name, ZodiacSign::Elements element, ZodiacSign::Months month) {

	// Defines the valid element range and inverts it if false, making it true and returning false.
	if (!(ZodiacSign::INVALID_ELEMENT < element && element < ZodiacSign::NUM_ELEMENTS)) {
		return false;
	}

	// Defines the valid month range and inverts it if false, making it true and returning false.
	if (!(ZodiacSign::INVALID_MONTH < month && month < ZodiacSign::NUM_MONTHS)) {
		return false;
	}

	// Loops through signs vector.
	for (int i = 0; i < signs.size(); ++i) {
		// Checks if any current ZodiacSign objects have duplicate name OR month
		if (signs.at(i).GetName() == name || signs.at(i).GetMonth() == month) {
			// Returns false if there was a match meaning a duplicate name or month was found
			return false;
		}
	}

	// If the program is here, it means there was no duplicates found, and the element and month
	// are valid so it will return true.
	return true;
}

// Zodiac member function, Clear(), is defined here. Simple calls the clear method from the vector class.
void Zodiac::Clear() {
	// This clears the ZodiacSign objects inside my private signs vector.
	signs.clear();
}


