#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;
int Nod (long int n1, long int n2);
void Sokr (long int &n1, long int &n2);
void Summ ( long int &n1, long int &n2, long int &n3, long int &n4);
void Mult ( long int &n1, long int &n2, long int &n3, long int &n4);
int main()
{

	srand(time(0));
	long int userchoice, a, b, c, d, k, m, e, f;
	cout << "Задача 6.1: Вычисление выражения ((a/b)+(c/d)+(k/m))*e/f\n0 - сгенерировать случайно\n1 - ввести вручную\n 2 - выйти из программы\n(0/1/2)" << endl;
	while(userchoice != 0 && userchoice != 1 && userchoice != 2)
	{
		cin >> userchoice;
		}
	if(userchoice == 2)
	{}
	else
	{
		if (userchoice == 1) {
			for (int i = 0; i<8; i++)
			{
				switch(i)
				{
					case 0:
					cout << "a = ";
					cin >> a;
					break;
					case 1:
					cout << "b = ";
					cin >> b;
					break;
					case 2:
					cout << "c = ";
					cin >> c;
					break;
					case 3:
					cout << "d = ";
					cin >> d;
					break;
					case 4:
					cout << "k = ";
					cin >> k;
					break;
					case 5:
					cout << "m = ";
					cin >> m;
					break;
					case 6:
					cout << "e = ";
					cin >> e;
					break;
					case 7:
					cout << "f = ";
					cin >> f;
					break;
				}
			}
		}
		else {
			for (int i = 0; i < 8; i++) {
				switch (i) {
					case 0:
						a = rand() % 200;
						cout << "a = " << a << endl;
						break;
					case 1:
						b = rand() % 200;
						cout << "b = " << b << endl;
						break;
					case 2:
						c = rand() % 200;
						cout << "c = " << c << endl;
						break;
					case 3:
						d = rand() % 200;
						cout << "d = " << d << endl;
						break;
					case 4:
						k = rand() % 200;
						cout << "k = " << k << endl;
						break;
					case 5:
						m = rand() % 200;
						cout << "m = " << m << endl;
						break;
					case 6:
						e = rand() % 200;
						cout << "e = " << e << endl;
						break;
					case 7:
						f = rand() % 200;
						cout << "f = " << f << endl;
						break;
				}
			}
		}
		if (b == 0 || d == 0  || m == 0 || f == 0) {
			std::cout << "ошибка: не могу делить на 0";
			return 0;
		}
		Sokr(a, b);
		Sokr(c, d);
		Sokr(k, m);
		Sokr(e, f);
		Summ(a, c, b, d);
		Summ(a,k,b,m);
		Mult (a, e,b,f);
		std::cout << "Answer:\n" << a << std::endl << "----\n" << b << std::endl;
	}
}
int Nod (long int n1, long int n2) {
	if (n1==n2)
		{return n2;}
	if (n1==0 || n2==0)
		{return 0;}
	while (n2 != 0) {
		int temp = n2;
		n2 = n1 % n2;
		n1 = temp;
	}
	return n1;
}
void Sokr (long int &n1, long int &n2) {
	int nod = Nod (n1, n2);
	n1/= nod;
	n2/= nod;
}
void Summ ( long int& n1, long int& n2, long int& n3, long int& n4) {
	if (n3 == n4) {
		n1+=n2;
		n2=n1;
	}
	else {
		n1*=n4;
		n2*=n3;
		n3*=n4;
		n4=n3;
		n1+=n2;
		n2=n1;
		Sokr(n1, n3);
		n2=n1; n4=n3;
	}
}
void Mult ( long int &n1, long int &n2, long int &n3, long int &n4) {
	n1*=n2;
	n3*=n4;
	Sokr(n1, n3);
	n2 = n1;
	n4 = n3;
}