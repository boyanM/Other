#include <iostream>
#include <math.h>
using namespace std;

void input(double &input)
{

do
{
	cout<<"Enter number between bigger  than 0 and smaller 100000:	";
	cin>>input;
}while(input < 0 && input > 100000);

}


int main() {

double n ,a,b,c;

cin>>n>>a>>b>>c;

if(n < 0 || n > 100000)input(n);
if(a < 0 || a > 100000)input(a);
if(b < 0 || b > 100000)input(b);
if(c < 0 || c > 100000)input(c);

int george_points = n / a;
int gergana_points = n / b;

int length = (int)n+1;

int *george = new int[george_points];
int *gergana = new int[gergana_points];
int *line = new int[length];
for(int i = 0; i < length;i++)
{
	line[i] = 0;
}

bool all_line = false;

double distance = 0;
int counter = 0;
while(distance <= n)
{
distance = distance + a;
george[counter] = distance;
counter++;
}

distance = n;
counter = 0;

while(distance >= 0)
{
	distance = distance - b;
	gergana[counter] = distance;
	counter++;
}

if(a == c || b == c)all_line = true;
cout<<"-------------------------"<<endl;
for(int i = 0;i < george_points;i++)
{
		for(int j = 0;j < gergana_points;j++)
		{

				int result = george[i] - gergana[j];
				if(abs(result) == c)
				{
					cout<<george[i]<<"	"<<gergana[j]<<endl;
						line[george[i]] = 1;
						line[gergana[j]] = 1;
				}
		}
}
//check in the both ends of the line
for(int i = 0 ; i < george_points;i++)
{
	int start_result = 0 - george[i];
	int fin_result = (int)n - george[i];
	if(abs(start_result) == c)line[0] = 1;
	if(abs(fin_result) == c)line[length-1] = 1;
}

for(int i = 0 ; i < gergana_points;i++)
{
	int start_result = 0 - gergana[i];
	int fin_result = (int)n - gergana[i];
	if(abs(start_result) == c)line[0] = 1;
	if(abs(fin_result) == c)line[length-1] = 1;
}

int count = 0;
for(int i = 1; i < length;i++)
{
	if(line[i-1] == 0 && line[i] == 0 )count++;
	if(line[i-1] == 1 && line[i] == 0 )count++;
	if(line[i-1] == 0 && line[i] == 1) count++; 	
}


if(all_line == true)
{
		count = 0;
cout<<"Output: "<<count<<endl;
}

else
{
	cout<<"Output: "<<count<<endl;
}

for(int i = 0; i < length;i++)
{
	cout<<line[i]<<endl;	
}







	return 0;
}
