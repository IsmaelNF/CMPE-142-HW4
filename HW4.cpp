#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;
int chef(int &food1, int &food2, int foodAvail[])
{
	food1 = (rand()  % 3) + 1;
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

int hamburger_customer(int foodAvail[], int currentFood[], int &eatCount){
	if(foodAvail[0] == 2 || foodAvail[1] == 2){
		if(foodAvail[0] == 3 || foodAvail[1] == 3){
			eatCount++;
			foodAvail[0] = 0;
			foodAvail[1] = 0;
			currentFood[0] = 0;
			currentFood[1] = 0;
		}
	}
}

int fries_customer(int foodAvail[], int currentFood[], int &eatCount){
	if(foodAvail[0] == 1 || foodAvail[1] == 1){
               if(foodAvail[0] == 3 || foodAvail[1] == 3){
                       eatCount++;
                       foodAvail[0] = 0;
                       foodAvail[1] = 0;
		       currentFood[0] = 0;
		       currentFood[1] = 0;
               }
       }
}

int soda_customer(int foodAvail[], int currentFood[], int &eatCount){
   if(foodAvail[0] == 1 || foodAvail[1] == 1){
                if(foodAvail[0] == 2 || foodAvail[1] == 2){
                        eatCount++;
                        foodAvail[0] = 0;
                        foodAvail[1] = 0;
			currentFood[0] = 0;
			currentFood[1] = 0;
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
	
	bool food1_taken = false;
	bool food2_taken = false;
	bool ham_has_first = false;
	bool fries_has_first = false;
	bool soda_has_first = false;

	int hamburger_food[2] = {0,0};
	int fries_food[2] = {0, 0};
	int soda_food[2] = {0, 0};
	/*
	chef(food1, food2, foodAvail);
	for(int i = 0; i < 2; i++)
	{
		cout << foodAvail[i] << '\t';
	}*/

	srand(time(0));
	for(int i = 0; i < 100; i++){		
		chef(food1, food2, foodAvail);
		food1_taken = false;

		if(!food1_taken){
			if(hamburger_food[0] == 0 && (food1 == 2 || food1 == 3)){
				hamburger_food[0] = food1;
				ham_has_first = true;
				food1_taken = true;
			}
			else if(hamburger_food[1] == 0 && (food1 == 2 || food1 == 3)){
				hamburger_food[1] = food1;
				food1_taken = true;
			}
		

			if(fries_food[0] == 0 && (food1 == 1 || food1 == 3)){
				fries_has_first = true;
                        	fries_food[0] = food1;
                        	food1_taken = true;
                	}
			else if(fries_food[1] == 0 && (food1 == 1 || food1 == 3)){
                                fries_food[1] = food1;
                                food1_taken = true;
                        }


			if(soda_food[0] == 0 && (food1 == 1 || food1 == 2)){
				soda_has_first = true;
                        	soda_food[0] = food1;
                        	food1_taken = true;
                	}
			else if(soda_food[1] == 0 && (food1 == 1 || food1 == 2)){
                                soda_food[1] = food1;
                                food1_taken = true;
                        }
                }

		if(!food2_taken){
                        if(hamburger_food[0] == 0 && (food2 == 2 || food2 == 3)){
                                hamburger_food[0] = food2;
                                food2_taken = true;
                        }
                        else if(!ham_has_first && (food2 == 2 || food2 == 3)){
                                hamburger_food[1] = food2;
				ham_has_first = false;
                                food2_taken = true;
                        }

                        
                        if(fries_food[1] == 0 && (food2 == 1 || food2 == 3)){
                                fries_food[1] = food2;
                                food2_taken = true;
                        }	
			else if(!fries_has_first && (food2 == 1 || food2 == 3)){
                                fries_food[1] = food2;
				fries_has_first = false;
                                food2_taken = true;
                        }


                        if(soda_food[0] == 0 && (food2 == 1 || food2 == 2)){
                                soda_food[0] = food2;
                                food2_taken = true;
                        }
                        else if(!soda_has_first && (food2 == 1 || food2 == 2)){
                                soda_food[1] = food2;
				soda_has_first = false;
                                food2_taken = true;
                        }
                }


		hamburger_customer(foodAvail, hamburger_food, hamburger_eatCount);
		fries_customer(foodAvail, fries_food, fries_eatCount);
		soda_customer(foodAvail, soda_food, soda_eatCount);
		
		cout << "Hamburger ate: " << hamburger_eatCount << "\tFries ate: " << fries_eatCount << "\tSoda ate: " << soda_eatCount << "\n";
	}
}
