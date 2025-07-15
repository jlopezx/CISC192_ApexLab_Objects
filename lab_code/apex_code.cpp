//
//
#include "apex_code.h"

void ZodiacSign::Print() {
  cout << name << endl;
  cout << "\tMonth: " << monthStrings[month] << endl;
  cout << "\tElement: " << elementsStrings[element] << endl;
  cout << "\t" << description << endl;
}

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
