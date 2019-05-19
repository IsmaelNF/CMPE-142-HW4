#include <stdlib.h>
#include <ctime>
#include <iostream>

using namespace std;
int chef(int &food1, int &food2)
{
	unsigned seed = time(0);
	srand(seed);
	food1 = (rand() % 3) + 1;
	food2 = food1;
	while(food1 == food2)
	{
		food2 = (rand() % 3) + 1;
	}
	
	if(food1 == 1 || food2 == 1)
	{
		cout << "Created Hamburger\n";
	}
	if(food1 == 2 || food2 == 2)
	{
		cout << "Created Fries\n";
	}
	if(food1 == 3 || food2 == 3)
	{
		cout << "Created Soda\n";
	}
}

int main()
{
	int food1;
	int food2;
	chef(food1, food2);
	cout << food1 << "\n";
	cout << food2 << "\n";
}
