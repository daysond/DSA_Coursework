/********************************************************************/
/*                                                                  */
/*   lab 2 timing file                                              */
/*                                                                  */
/*   To compile: g++ lab2.cpp lab2timing.cpp timer.cpp -std=c++0x   */
/*   NOTE: if you are working in windows, change the #define        */
/*   PLATFORM line in timer.h, see comments in that file            */
/*                                                                  */
/*                                                                  */
/********************************************************************/
#include "timer.h"
#include <iostream>
#include<fstream>
#include <iomanip>
#include <map>
// #define FIB
#define POWER 
using namespace std;

unsigned int factorial(unsigned int n);
// double power(double base, unsigned int n);
unsigned long long power (unsigned int base, unsigned int n);
unsigned int fibonacci(unsigned int n);
unsigned long long efficient_power (unsigned int base, unsigned int n);
int main(void)
{

#ifdef FIB
	unsigned int n = 25;
	unsigned int rc;
	cout << setw(10) << left << "n"
		 << "time(s)" << endl;
	cout << setw(30) << setfill('-') << "" << setfill(' ') << endl;
	for (; n <= 50; n++)
	{
		Timer t;
		t.start();
		rc = fibonacci(n);
		t.stop();
		cout << setw(10) << left << n << fixed << setprecision(5) << t.currtime() << endl;
	}
#endif

#ifdef POWER
	
	unsigned int n = 10;
	unsigned long long int rc;
	int max = 50000;
	int start = 1;
	int interval = 1;
	int base = 6;
	double factor = 1000;
	ofstream f;

	Timer t;

	t.start();
	for (n = start; n <= max; n += interval) 
		rc = power(base, n);
	t.stop();

	cout << "Regular power took " << t.currtime() * factor << " ms." << endl;

	t.reset();
	

	t.start();
	for (n = start; n <= max; n += interval) 
		rc = efficient_power(base, n);
	t.stop();

	cout << "Efficient power took " << t.currtime() * factor << " ms." << endl;

	t.reset();


	/* File output*/
	factor = 1000000;
	interval = 10;
	f.open("/Users/daysondong/Desktop/SES_LAB3/regpwr.txt");
	for (n = start; n <= max; n += interval) {
		t.start();
		rc = power(base, n);
		t.stop();
		f << n << "," << t.currtime() * factor << endl;
		t.reset(); 
	}
	f.close();

	f.open("/Users/daysondong/Desktop/SES_LAB3/effpwr.txt");
	for (n = start; n <= max; n += interval) {
		t.start();
		rc = efficient_power(base, n);
		t.stop();
		f << n << "," << t.currtime() * factor << endl;
		t.reset(); 
	}
	f.close();

#endif

	return 0;
}

/*
Original Timing main

int main(void){
	unsigned int n = 35;
	unsigned int rc;
	Timer t;
	t.start();
	rc=fibonacci(n);
	t.stop();
	cout << "fibonacci (" << n << ") = " << rc << endl;
	cout << "fibonacci (" << n << ") took " << t.currtime() << " s" << endl;
	return 0;
}


*/