//  checker.cpp: mutual exclusion checker

#include <string>
#include <sstream>
using namespace std;

#include "checker.h"

// Global Variables
extern int numThreads; // number of threads (included from main.cpp)
extern int numRounds;  // number of rounds of eating & thinking (included from main.cpp)
static int*  timesPhilosopherAte = NULL; // array of counts of times each philosopher ate
static bool* isPhilosopherEating = NULL; // array of flags to indicate
                                         // if (true) each philosopher is currently eating

// Global Error Messages
static string error = "ERROR: internal error (this should never happen)";
static string sharingChopstick =
  "VIOLATION: two philosophers are sharing a chopstick (two adjacent philosophers are eating at the same time)";
static string alreadyEating =
  "VIOLATION: a philosopher is starting to eat while they were already eating";
static string thinkingWithoutEating =
  "VIOLATION: a philosopher is thinking on an empty stomach (did not eat before thinking)";
static string tooManyRounds =
  "VIOLATION: a philosopher attempted to eat and/or think too many times";
static string insufficientRounds =
  "VIOLATION: a philosopher did not eat and think enough times before finishing";


// updateAndCheck: Updates the status of the checker and checks for violations.
// Returns a pointer to an error message if a violation occurs and NULL otherwise.
//
static const char *updateAndCheck(string section, string property)
{
  // Allocate things that are not allocated yet
  if (NULL == isPhilosopherEating) {
    isPhilosopherEating = new bool[numThreads];
    for (int i = 0; i < numThreads; ++i) {
      isPhilosopherEating[i] = false;
    }
  }
  if (NULL == timesPhilosopherAte) {
    timesPhilosopherAte = new int[numThreads];
    for (int i = 0; i < numThreads; ++i) {
      timesPhilosopherAte[i] = 0;
    }
  }

  // Check allocation (possible to file if Out of Memory, for example)
  if (NULL == isPhilosopherEating || NULL == timesPhilosopherAte) {
    return error.c_str();
  }

  // Get the philosopher ID from the property
  istringstream idStream(property);
  int id;
  idStream >> id;
  // Check that ID is valid
  if (id < 0 || id >= numThreads) {
    return error.c_str();
  }

  if (section == "Eating") {
    if (isPhilosopherEating[id]) {
      return alreadyEating.c_str();
    }

    if (isPhilosopherEating[(id+1)%numThreads] ||
        isPhilosopherEating[(id-1)%numThreads]) {
      return sharingChopstick.c_str();
    }

    isPhilosopherEating[id] = true;
    timesPhilosopherAte[id] += 1;

    if (timesPhilosopherAte[id] > numRounds) {
      return tooManyRounds.c_str();
    }
  }
  else if (section == "DoneEating") {
    if (!isPhilosopherEating[id]) {
      return thinkingWithoutEating.c_str();
    }
    isPhilosopherEating[id] = false;
  }
  else if (section == "DoneRounds") {
    if (timesPhilosopherAte[id] < numRounds) {
      return insufficientRounds.c_str();
    }
  }

  return NULL;
}

// Callback function to register with MDAT
const char *checkerCallback(int id, const char *section, const char *property)
{
  return updateAndCheck(section, property);
}
