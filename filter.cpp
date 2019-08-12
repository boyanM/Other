#include <iostream>
#include "filter.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{
string line;

ifstream read;
ofstream write;

read.open("result_20190812-13-22_out.txt");
write.open("markers.csv");

if(read.is_open())
{
		
	while(getline(read,line))
	{
		if(line[0] == '0' && line[1] == '0' && line[2] == '0' && line[3] == '1')
		{
			write<<line<<endl;						
		}
	}


}

else
{
	cout<<"Error, file not opened !"<<endl;
}


	











read.close();
write.close();

	return 0;
}



/*		Prints the file
	while(getline(myfile,line))
	{
		cout<<line<<endl;
	}
*/	
