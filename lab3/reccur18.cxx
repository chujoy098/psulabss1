
#include <iostream>
#include <cmath>

void r18()
{
	using namespace std;
	int n;
	float sum = 0;
	cout << "Введите N: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		sum+= float(2*i)/float(1+2*i);
		}	
	cout << sum;
}