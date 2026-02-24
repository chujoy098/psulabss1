
#include <iostream>
#include <cmath>
#include <random>
void SortDec3(float *m);
void p13()
{
	using namespace std;
	srand(time(0));
	float list1[3];
	float list2 [3];
	for (int i = 0; i<3; i++)
	{
		
		list1[i]=rand()%1000+float(rand()%100)/100.;
		list2[i]=rand()%1000+float(rand()%100)/100.;
		
		
		}
	cout << endl << "Отсортированно:\n";
	SortDec3(list1);
	SortDec3(list2);
	for (int i=0; i<3; i++)
	{
		cout << list1[i] << " ";
		}
	cout << endl;
	for (int i=0; i<3; i++)
	{
		cout << list2[i] << " ";
		}
	cout << endl;
}
void SortDec3(float *m)
{
	int j,r, n=3;
	for (int i=1;i<n;i++)
	{
	r=m[i];
	j=i-1;
	while(j>=0&&m[j]<r)
	{
	m[j+1]=m[j];
	j--;
	}
	m[j+1]=r;
	}
}