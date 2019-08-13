#ifndef __FILTER_H
#define __FILTER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Filter
{
private:
	ifstream input;
	fstream output;
	string line;

public:
Filter();

void filterSeparators();

string checkForLeadingZeros(string line);

string deleteFirstSeparators(string line);


~Filter();
	




};



#endif
