//  sections2.c: mutual exclusion model sections

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include "sections.h"
#include "mdat.h"

//Globals
pthread_mutex_t* count;
pthread_mutex_t* forks;
int totalPhilosophers;
int counter;


void
sectionInitGlobals(int numPhilosophers)
{
  int i = 0;
  char name[30];
  totalPhilosophers = numPhilosophers;
  counter = 0;
  
  //Allocating space for an array of mutex's.
  forks = (pthread_mutex_t*) calloc(numPhilosophers, sizeof(pthread_mutex_t*));
  
  //Initializing array of mutex's
  for(i = 0;i < numPhilosophers;i++){
	  sprintf(name, "fork %d",i);
	  mdat_mutex_init(name, &forks[i], NULL);
  }
  //Initialize mutex for the thread counter
  mdat_mutex_init("thread count", count, NULL);
}
void
sectionRunPhilosopher(int philosopherID, int numRounds)
{
	int second_fork = 0;
	int first_fork = 0;
	int i = 0;
	int temp = 0;
	
	//Checks last philosopher and assigns the last fork
	//and the first fork for his use
	if(philosopherID == (totalPhilosophers-1)){
		first_fork = philosopherID;
		second_fork = 0;
	}
	
	//Sets philosopers forks to be the equivalent index as
	//the philosoperID and plus one
	else{
		first_fork = philosopherID;
		second_fork = philosopherID + 1;
	}
	
	//Philosopher eating and thinking for numRounds always making
	//sure that the philosopher grabs the lower index fork first.
	//Implementation of priority.
	for(i = 0;i < numRounds;i++){
		if(first_fork <= second_fork){
			mdat_mutex_lock(&forks[first_fork]);
			mdat_mutex_lock(&forks[second_fork]);
			eat();
			mdat_mutex_unlock(&forks[second_fork]);
			mdat_mutex_unlock(&forks[first_fork]);
			think();
		}
		else{
			temp = first_fork;
			first_fork = second_fork;
			second_fork = temp;
			mdat_mutex_lock(&forks[first_fork]);
			mdat_mutex_lock(&forks[second_fork]);
			eat();
			mdat_mutex_unlock(&forks[second_fork]);
			mdat_mutex_unlock(&forks[first_fork]);
			think();
		}
		
	}
	
	//Keeping track of threads that have finished so
	//the program can deallocate memory on the final thread
	if(counter < totalPhilosophers){
		mdat_mutex_lock(count);
		counter++;
		mdat_mutex_unlock(count);
	}
	else{
		free(forks);
	}
}
