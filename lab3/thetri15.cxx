
#include <iostream>
#include <cmath>

int convto10(int syst, int &inpu);
void convfrom10(int &a, int syst);
void t15()
{
	
	int n, inp1,  inp2, sum=0;
	std::cout << "Введите число 1: ";
	std::cin >> inp1;
	std::cout << "Введите число 2: ";
	std::cin >> inp2;
	std::cout << "Введите систему счисления P (2<=P<=9): ";
	std::cin >> n;
	if(n<2 || n>9)
	{
		std::cout << "Некорректная система счисления\n";
		return;
		}
	sum = convto10(n, inp1) + convto10(n, inp2);
	std::cout << "Результат в десятич.: " << sum << "\n";
	std::cout << "Результат: ";
	convfrom10(sum, n); 
	
}

int convto10(int syst, int &inpu)
{

	int b, j = 0, sum = 0;
	while(inpu>0)
	{
		b = inpu%10;
		sum+=b*pow(syst, j);
		inpu/=10;
		j++;
		}
	return sum;
	
	}
	
void convfrom10(int &a, int syst)
{
	
	int i = 1;
	int oupt = 0;
	while (i<=a)
	{
		i*=10;
		}
	i/=10;
	
	while (a != 0)
	{
			oupt=((a%syst));
			std::cout << oupt;
			a/=syst;
	}
	std::cout << "\n";
	}