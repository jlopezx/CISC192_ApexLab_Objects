//
// Don't modify code in this file, with the exception
// of adding test cases.
//
#include "apex_code.h"
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

static int testNum = 0;
static int testsCorrect = 0;

static int funcTestNum = 0;
static int funcTestCorrect = 0;

bool near(double expected, double result, double threshold) {
  return abs(expected - result) < threshold;
}

// Use when testing double/float values
bool testNear(double expected, double result) {
  if (false == near(expected, result, 0.002)) {
    cout << "FAILED: Expected " << expected << ", received " << result << ".\n";
  } else {
    cout << "PASS\n";
  }

  return expected == result;
}

// Use for everything other than doubles/floats
template <typename T> bool test(T expected, T result) {
  funcTestNum++;
  testNum++;

  if (expected != result) {
    cout << "FAILED: Expected " << expected << ", received " << result << ".\n";
  } else {
    cout << "PASS\n";

    testsCorrect++;
    funcTestCorrect++;
  }

  return expected == result;
}

/**
 * Mark the starting point for the tests of a specific function.
 *
 * @param startFuncName the function name to start testing
 */
void startTests(string startFuncName) {
  cout << "----- Start of testing " << startFuncName << " -----" << endl;

  funcTestNum = 0;
  funcTestCorrect = 0;
}

/**
 * Mark the ending point for the tests of a specific function.
 *
 * @param endFuncName the function name to end testing
 */
void endTests(string endFuncName) {
  if (funcTestNum == funcTestCorrect) {
    cout << "----- All tests passed for " << endFuncName << "! -----" << endl;
  } else {
    cout << "----- Some tests failed for " << endFuncName << " :( -----"
         << endl;
  }
  cout << endl;
}

/**
 * Mark the end of the test suite.
 */
void endAllTests() {
  if (testsCorrect == testNum) {
    cout << "All tests passed! Let's goooo" << endl;
  } else {
    cout << "Some tests failed. Keep trying!" << endl;
  }
}

int main() {
  startTests("ZodiacSign, GetName, and GetMonth");
  ZodiacSign firstSign("this", ZodiacSign::Elements::AIR, "that",
                       ZodiacSign::FEBRUARY);
  (void)test<string>("this", firstSign.GetName());
  (void)test<ZodiacSign::Months>(ZodiacSign::FEBRUARY, firstSign.GetMonth());
  endTests("ZodiacSign, GetName, and GetMonth");

  startTests("Zodiac, AddSign, Clear, and Populate");
  Zodiac testZodiac;
  (void)test<bool>(false,
                   testZodiac.AddSign("this", ZodiacSign::INVALID_ELEMENT,
                                      "that", ZodiacSign::FEBRUARY));
  (void)test<bool>(false, testZodiac.AddSign("this", ZodiacSign::NUM_ELEMENTS,
                                             "that", ZodiacSign::FEBRUARY));
  (void)test<bool>(
      false, testZodiac.AddSign("this", static_cast<ZodiacSign::Elements>(-1),
                                "that", ZodiacSign::FEBRUARY));
  (void)test<bool>(false, testZodiac.AddSign("this", ZodiacSign::FIRE, "that",
                                             ZodiacSign::INVALID_MONTH));
  (void)test<bool>(false, testZodiac.AddSign("this", ZodiacSign::FIRE, "that",
                                             ZodiacSign::NUM_MONTHS));
  (void)test<bool>(false,
                   testZodiac.AddSign("this", ZodiacSign::FIRE, "that",
                                      static_cast<ZodiacSign::Months>(-1)));

  (void)test<bool>(true, testZodiac.AddSign("NewSign", ZodiacSign::FIRE,
                                            "I made it up", ZodiacSign::MARCH));

  testZodiac.Clear();

  testZodiac.Populate();
  // March was added as part of the populate call so this should fail as a
  // second add attempt
  (void)test<bool>(false,
                   testZodiac.AddSign("NewSign", ZodiacSign::FIRE,
                                      "I made it up", ZodiacSign::MARCH));
  // LEO was added as part of the populate call so this should fail as a second
  // add attempt
  (void)test<bool>(false,
                   testZodiac.AddSign("LEO", ZodiacSign::FIRE, "I made it up",
                                      ZodiacSign::MARCH));
  endTests("Zodiac, AddSign, Clear, and Populate");

  startTests("GetMySign, GetName");
  ZodiacSign mySign = testZodiac.GetMySign(ZodiacSign::JULY);
  (void)test<string>("CANCER", mySign.GetName());
  mySign = testZodiac.GetMySign(ZodiacSign::NUM_MONTHS);
  (void)test<string>("None", mySign.GetName());
  endTests("GetMySign, GetName");

  endAllTests();

  return 0;
}
