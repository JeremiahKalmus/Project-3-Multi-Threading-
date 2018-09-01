//Jeremiah Kalmus
//CPSC 3500
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define NUM_CHECKOUTS 20

pthread_mutex_t pen_mutex;
pthread_mutex_t paper_mutex;
pthread_mutex_t toner_mutex;
pthread_mutex_t laptops_mutex;

//Global variables for the products being sold
int pen = 200;
int paper = 100;
int toner = 35;
int laptops = 20;

//function to restock products as they reach
//zero capacity
void restock(string);

//Thread function that will act as a checkout counter
//processing a file
void* checkout_thread(void *filename){
	
	string item;
	long total_sales;
	string *file = (string*) filename;
	ifstream infile;
	infile.open((*file));
	if(infile.fail()){
		cerr << "ERROR opening file!" << endl;    
		exit(-1);
	}
	
	while(getline(infile,item)){
		
		if(item == "pen"){
			if(0 != pthread_mutex_lock(&pen_mutex)){
				cerr << "ERROR fail to lock thread!" << endl;
				exit(-1);
			}
			pen--;
			if(pen == 0){
				restock(item);
			}
			total_sales++;
			if(0 != pthread_mutex_unlock(&pen_mutex)){
				cerr << "ERROR fail to unlock thread!" << endl;
				exit(-1);
			}
		}
		else if(item == "paper"){
			if(0 != pthread_mutex_lock(&paper_mutex)){
				cerr << "ERROR fail to lock thread!" << endl;
				exit(-1);
			}
			paper--;
			if(paper == 0){
				restock(item);
			}
			total_sales++;
			if(0 != pthread_mutex_unlock(&paper_mutex)){
				cerr << "ERROR fail to unlock thread!" << endl;
				exit(-1);
			}
		}
		else if(item == "toner"){
			if(0 != pthread_mutex_lock(&toner_mutex)){
				cerr << "ERROR fail to lock thread!" << endl;
				exit(-1);
			}
			toner--;
			if(toner == 0){
				restock(item);
			}
			total_sales++;
			if(0 != pthread_mutex_unlock(&toner_mutex)){
				cerr << "ERROR fail to unlock thread!" << endl;
				exit(-1);
			}
		}
		else if(item == "laptop"){
			if(0 != pthread_mutex_lock(&laptops_mutex)){
				cerr << "ERROR fail to lock thread!" << endl;
				exit(-1);
			}
			laptops--;
			if(laptops == 0){
				restock(item);
			}
			total_sales++;
			if(0 != pthread_mutex_unlock(&laptops_mutex)){
				cerr << "ERROR fail to unlock thread!" << endl;
				exit(-1);
			}
		}
		
	}
	infile.close();
	pthread_exit((void*)total_sales);
}

int main()
{
	const string BASE = "/home/fac/lillethd/cpsc3500/projects/p3a/sales";
	const string EXT = ".txt";
	string file_arr[NUM_CHECKOUTS]; 
	string temp;
	long thread_total = 0;
	long thread_result = 0;

	//Initializing mutex locks
	pen_mutex = PTHREAD_MUTEX_INITIALIZER;
	paper_mutex = PTHREAD_MUTEX_INITIALIZER;
	toner_mutex = PTHREAD_MUTEX_INITIALIZER;
	laptops_mutex = PTHREAD_MUTEX_INITIALIZER;
	
	//Loads file names into an array to be passed into
	//individual threads
	for(int i = 0;i <  NUM_CHECKOUTS;i++){
		temp = (BASE + to_string(i+1) + EXT);
		file_arr[i] = temp;
	}
	
	//Threads for the checkout registers, where customers will buy things.
	pthread_t checkout_tids[NUM_CHECKOUTS];
	for(int i = 0;i < NUM_CHECKOUTS; ++i){
		if(0 != pthread_create(&checkout_tids[i], NULL, checkout_thread,
			(void *) &file_arr[i])){
			cerr << "ERROR creating thread!" << endl;
			return 1;
		}
		
	}
	//Joins threads
	//Waits for all threads to finish before progressing
	for(int i = 0;i < NUM_CHECKOUTS; ++i){
		if(0 != pthread_join(checkout_tids[i], (void**)&thread_result)){
			cerr << "ERROR joining thread!" << endl;
		}
		cout << thread_result << endl;
		thread_total = thread_total + thread_result;
	}
	
	//Prints store inventory and total sales to the screen
	cout << "Pens in stock: " << pen << endl;
	cout << "Paper in stock: " << paper << endl;
	cout << "Toner in stock: " << toner << endl;
	cout << "Laptops in stock: " << laptops << endl;
	cout << "Total sales: " << thread_total << endl;
	
	return 0;
}

void restock(string item){
	
	if(item == "pen"){
		pen = 200;
	}
	else if(item == "paper"){
		paper = 100;
	}
	else if(item == "toner"){
		toner = 35;
	}
	else if(item == "laptop"){
		laptops = 20;
	}
	return;
}