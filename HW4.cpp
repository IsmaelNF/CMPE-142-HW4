#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;
int chef(int &food1, int &food2, int foodAvail[])
{
	unsigned seed = time(0);
	srand(seed);
	food1 = (rand() % 3) + 1;
	food2 = food1;
	while(food1 == food2)
	{
		food2 = (rand() % 3) + 1;
	}
	foodAvail[0] = food1;
	foodAvail[1] = food2;
	
	if(food1 == 1 || food2 == 1)
	{
		cout << "Created Hamburger\n"; //1 for Hamburger
	}
	if(food1 == 2 || food2 == 2)
	{
		cout << "Created Fries\n"; //2 for Fries
	}
	if(food1 == 3 || food2 == 3)
	{
		cout << "Created Soda\n"; //3 for Soda
	}
}

int hamburger_customer(int foodAvail[], int &eatCount){
	if(foodAvail[0] == 2 || foodAvail[1] == 2){
		if(foodAvail[0] == 3 || foodAvail[1] == 3){
			eatCount++;
			foodAvail[0] = 0;
			foodAvail[1] = 0;
		}
	}
}

int fries_customer(int foodAvail[], int &eatCount){
	if(foodAvail[0] == 1 || foodAvail[1] == 1){
               if(foodAvail[0] == 3 || foodAvail[1] == 3){
                       eatCount++;
                       foodAvail[0] = 0;
                       foodAvail[1] = 0;
               }
       }
}

int soda_customer(int foodAvail[], int &eatCount){
   if(foodAvail[0] == 1 || foodAvail[1] == 1){
                if(foodAvail[0] == 2 || foodAvail[1] == 2){
                        eatCount++;
                        foodAvail[0] = 0;
                        foodAvail[1] = 0;
                }
        }	
}

int main()
{
	int food1;
	int food2;
	int foodAvail[2];
	int hamburger_eatCount = 0;
	int fries_eatCount = 0;
	int soda_eatCount = 0;
	chef(food1, food2, foodAvail);
	for(int i = 0; i < 2; i++)
	{
		cout << foodAvail[i] << '\t';
	}
	hamburger_customer(foodAvail, hamburger_eatCount);
	fries_customer(foodAvail, fries_eatCount);
	soda_customer(foodAvail, soda_eatCount);
	cout << "Hamburger ate: " << hamburger_eatCount << "\tFries ate: " << fries_eatCount << "\tSoda ate: " << soda_eatCount << "\n";

}
