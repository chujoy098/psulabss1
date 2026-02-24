
#include <iostream>
#include <iomanip>]
double Ln1(int x, double prec);
void p43()
{
	using namespace std;
	int n;
	double pare;
	cout << "Введите x: ";
	cin >> n;
	cout << "Введите е: ";
	cin >> pare;
	cout << "Результат: " << Ln1(n, pare) << endl;

}
double Ln1(int x, double prec)
{
	
	long double sum = 0;
	double counter = 0;
	for (double i = 0; i<100; i++)
	{
		sum+=x;
		x*=(-x)/i+2;
		}
	do {
		prec*=10;
		counter++;
	}while (prec<1);
	std::setprecision(counter);
	return sum;
	
	}