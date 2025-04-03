#include <iostream>
#include <fstream>
#include <sstream>
#include <sstream>
#include <string>
#include <iomanip>

#include "Utils.hpp"  
using namespace std;

int main()
{
	string inputFile = "data.txt";
	size_t n;
	double S;
	double *w = nullptr;
	double *r = nullptr;
	
	ImportVectors(inputFile, n, S, w, r);
	
	double V = return_V(S, w, r, n);
	double ratereturn = rate_of_return(S, V);
	
	ofstream printout("result.txt");
	printout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl; //fixed per non notazione scientifica 
	printout << "w = " << ArrayToString(n, w)<< endl;
	printout << "r = " << ArrayToString(n, r)<< endl;
	printout << "Rate of return of the portfolio: " << fixed << setprecision(4) << ratereturn << endl; 
	printout << "V: " << fixed << setprecision(2) << V << endl;
	
}


