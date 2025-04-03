#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

string ArrayToString(const size_t& n,
					 const double* const& v)

{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}


bool ImportVectors(const string& inputFile,
				   size_t& n,
				   double& S, 
				   double*& v1,
				   double*& v2)

{
	ifstream file(inputFile);
	
	if (file.fail())
		return false; 
	
	string tmp;
	//prima riga
	getline(file,tmp, ';');
	file >> S;
	file.ignore();
	
	//seconda riga
	getline(file,tmp, ';');
	file >> n;
	file.ignore();
	
	// terza riga
	getline(file,tmp);
	
	//righe successive
	
	v1 = new double[n];
	v2 = new double[n];
	
	for (unsigned int i = 0; i < n; i++)
	{
		getline(file,tmp, ';');
		v1[i] = stod(tmp);
		
		file >> v2[i];
		file.ignore();
	}

	return false;
}

double return_V(const double S, const double* v1, const double* v2, const size_t n)
{	
	double V = 0;
	for(unsigned int i = 0; i<n; i++)
	{
		double partS = S * v1[i];
		V += (1 + v2[i])* partS;
	}
	return V;
}
double rate_of_return(const double S, const double V)
{
	double rate = (V/S)-1;
	return rate;
}

	
		
	