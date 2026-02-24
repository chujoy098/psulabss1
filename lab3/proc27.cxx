#include <iostream>
#include <cmath>
#include <random>
bool IsPowerN(int k, int n);
void p27()
{
	using namespace std;
	srand(time(0));
	int a, counter = 0, inpu;
	int list[10];
	std::cout << "Введите N: ";
	std::cin >> a;
	std::cout << "Рандом или ввести самому? 1-ран. 2-сам.\n";
	std::cin >> inpu;
	if(inpu == 1)
	{
	for (int i = 0; i<10; i++)
	{
		list[i]=rand()%100;
		std::cout << list[i] << " ";
		}
	}
	else
	{
		if (inpu == 2)
		{
			for(int i=0; i<10; i++)
			{
				std::cin >> list[i];
			}
		}
			else
			{
				std::cout << "Error!\n";
			}
		}
	std::cout << endl;
	for (int i = 0; i<10; i++)
	{
		
		if (IsPowerN(list[i], a))
		{
			counter++;
			}
		
		}
	cout << "Кол-во степеней: " << counter << endl;
}
bool IsPowerN(int k, int n)
{
	for(int i = 0; i<20; i++)
	{
		
		if (pow(n, i) == k)
		{
			return true;
			}
		
		}
	return false;
	}