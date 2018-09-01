//  main.cpp: driver

#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

#include <getopt.h>
#include <pthread.h>

#include "checker.h"
#include "sections.h"
#include "mdat.h"

// Parameter struct
struct ThreadParam {
  int id;		// id number for thread
  int numRounds;	// number of rounds 
};

// Function prototype for initial thread function
void *threadStart(void *param);

// Prints command line usage.
void usage()
{
  cerr << "Required flags: " << endl;
  cerr << "-t <num-threads>  (or --threads)	Number of threads" << endl;
  cerr << "-r <num-rounds>   (or --rounds)      Number of rounds" << endl;
  cerr << "Optional flags: " << endl;
  cerr << "-i                (or --interactive) Run in interactive mode" << endl;
  cerr << "-o <filename>     (or --output)      Create output trace in specified file" << endl;
  cerr << "-s <number>       (or --seed)        Sets the random number generator seed" << endl;
}


int numThreads = -1;	// number of threads
int numRounds = -1;		// number of rounds

int 
main(int argc, char *argv[])
{
  // Initialize variables
  char *traceName = NULL;	// name of trace file
  bool useInteractive = false;  // set if interactive mode is used
  bool useSeed = false;		// use a random seed
  unsigned int seed = 0;	// specified seed value			

  // Process command line arguments
  int opt;
  const struct option longOpts[] = {
    {"threads", 1, 0, 't'},
    {"rounds", 1, 0, 'r'},
    {"interactive", 0, 0, 'i'},
    {"output", 1, 0, 'o'},
    {"seed", 1, 0, 's'},
    {0, 0, 0, 0}
  };
  while ((opt = getopt_long(argc, argv, "t:r:io:s:", longOpts, NULL)) != -1) { 
    switch (opt) {
      case 't':
        numThreads = atoi(optarg);
        break;
      case 'r':
        numRounds = atoi(optarg);
        break;
      case 'i':
        useInteractive = true;
        break;
      case 'o':
        traceName = optarg;
        break;
      case 's':
        useSeed = true;
        seed = strtoul(optarg, NULL, 0);
        break;
      case '?':
        usage();
        return -1;
    }
  }

  // Check for required parameters
  if (numThreads <= 0) {
    cerr << "Command line missing required argument: -t <num-threads>" << endl;
    usage();
    return -1;
  }
  if (numRounds <= 0) {
    cerr << "Command line missing required argument: -r <num-rounds> " << endl;
    usage();
    return -1;
  }

  // More initialization
  pthread_t *tArray = new pthread_t[numThreads]; // array of thread ids
  mdat_init(numThreads, traceName, checkerCallback, useInteractive, useSeed, seed);
  sectionInitGlobals(numThreads);

  // Create the threads
  for (int i = 0; i < numThreads; i++) {
    ThreadParam *paramPtr = new ThreadParam;
    paramPtr->id = i;
    paramPtr->numRounds = numRounds;
    int status = pthread_create(&tArray[i], NULL, threadStart, (void *) paramPtr);
    if (status) {
      cerr << "pthread_create failure" << endl;
      return -1;
    }
  }

  // Wait for the threads to finish
  for (int i = 0; i < numThreads; i++) {
    int status = pthread_join(tArray[i], NULL);     
    if (status) {
      cerr << "pthread_join failure" << endl;
      return -1;
    }
  }

  // Clean up
  delete [] tArray;

  return 0;
}

// Initial thread function
void *threadStart(void *param)
{
  // Extract the parameters
  ThreadParam *paramPtr = (ThreadParam *) param;
  int id = paramPtr->id;
  int numRounds = paramPtr->numRounds;
  delete paramPtr;

  // Start thread in mdat library
  ostringstream idString;
  idString << id;
  mdat_thread_start(id, idString.str().c_str());

  // Execute the sections
  sectionRunPhilosopher(id, numRounds);
  mdat_enter_section("DoneRounds");

  // Finish up execution
  mdat_thread_finish();
  pthread_exit(NULL);
}
