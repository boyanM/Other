#include "filter.h"

Filter::Filter()
{
	input.open("result_20190813-16-49_out.txt");
	output.open("markers.txt");
}


void Filter::filterSeparators()
{
	if(input.is_open())
	{
		bool lineNum = true;
		while(getline(input,this->line))
		{
			if(lineNum)
			{
				line.clear();
				lineNum = false;
				continue;
			}

			this->line = checkForLeadingZeros(this->line);
			this->line = deleteFirstSeparators(this->line);
			output<<this->line<<endl;
		}

		output.clear();
		output.seekg(0,ios::beg);
		while(getline(output,line))
		{
		//cout<<line<<endl;
		}

	}
	else
	{
		cout<<"Error with opening input file !"<<endl;
	}
}

string Filter::checkForLeadingZeros(string line)
{
	while(line[0] == '0')
	{
		line.erase(0,1);
		//cout<<line<<endl;
	}
	return line;
}

string Filter::deleteFirstSeparators(string line)
{
	int indexOfSeparator = line.find("|");
	line.erase(indexOfSeparator,5);
	line.insert(indexOfSeparator,",");

	indexOfSeparator = line.find("|");
	line.replace(indexOfSeparator,1,",");
	line.insert(indexOfSeparator+1,"\"");

	indexOfSeparator = line.find("|");
	line.replace(indexOfSeparator,1,",");
	line.insert(indexOfSeparator,"\"");

	indexOfSeparator = line.find("|");
	line.replace(indexOfSeparator,1,",");

	line = line + ",generated";



	return line;

}

Filter::~Filter()
{
	input.close();
	output.close();
}
