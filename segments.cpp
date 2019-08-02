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

if(a == 1 || b == 1)all_line = true;

for(int i = 0;i < george_points;i++)
{
		for(int j = 0;j < gergana_points;j++)
		{
				int result = george[i] - gergana[j];
				if(abs(result) == c)
				{
						line[george[i]] = 1;
						line[gergana[j]] = 1;
				}
		}
}
int count = 0;
for(int i = 0; i < length;i++)
{
	if(line[i] == 0)count++;
}

if(all_line == true)
{
	cout<<0<<endl;
}
else
{
	cout<<count;
}




	return 0;
}
