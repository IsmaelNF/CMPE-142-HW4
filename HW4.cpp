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
	if(currentFood[0] == 2 || currentFood[0] == 3){
		if(currentFood[1] == 2 || currentFood[1] == 3){
			eatCount++;
			currentFood[0] = 0;
			currentFood[1] = 0;
		}
	}
}

int fries_customer(int foodAvail[], int currentFood[], int &eatCount){
	if(currentFood[0] == 1 || currentFood[0] == 3){
               if(currentFood[1] == 1 || currentFood[1] == 3){
                       eatCount++;
                       currentFood[0] = 0;
		       currentFood[1] = 0;
               }
       }
}

int soda_customer(int foodAvail[], int currentFood[], int &eatCount){
   if(currentFood[0] == 1 || currentFood[0] == 2){
                if(currentFood[1] == 1 || currentFood[1] == 2){
                        eatCount++;
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

	int hamburger_food[2] = {0, 0};
	int fries_food[2] = {0, 0};
	int soda_food[2] = {0, 0};
	
	int prev_food[2] = {0, 0};
	srand(time(0));
	for(int i = 0; i < 100; i++){		
		//chef(food1, food2, foodAvail); //Use to run code without threads
		thread chef1(chef, std::ref(food1), std::ref(food2), foodAvail);
		chef1.join();
		cout<<"Food1= "<<food1<<" Food2= "<<food2<<"\n";
		food1_taken = false;
		food2_taken = false;
		if(!food1_taken){
			if(hamburger_food[0] == 0 && (food1 == 2 || food1 == 3)){
				ham_has_first = true;
				hamburger_food[0] = food1;
				food1_taken = true;
			}
			else if(hamburger_food[1] == 0 && hamburger_food[0] != food1 && (food1 == 2 || food1 == 3)){
				hamburger_food[1] = food1;
				food1_taken = true;
			}
		

			else if(fries_food[0] == 0 && (food1 == 1 || food1 == 3)){
				fries_has_first = true;
                        	fries_food[0] = food1;
                        	food1_taken = true;
                	}
			else if(fries_food[1] == 0 && fries_food[0] != food1  &&(food1 == 1 || food1 == 3)){
				fries_food[1] = food1;
                                food1_taken = true;
                        }


			else if(soda_food[0] == 0 && (food1 == 1 || food1 == 2)){
				soda_has_first = true;
                        	soda_food[0] = food1;
                        	food1_taken = true;
                	}
			else if(soda_food[1] == 0 && soda_food[0] != food1  && (food1 == 1 || food1 == 2)){
				soda_food[1] = food1;
                                food1_taken = true;
                        }
			else{
				food1_taken = true;
			}
                }

		if(food1_taken && !food2_taken){
                        if(hamburger_food[0] == 0 && (food2 == 2 || food2 == 3)){
                                hamburger_food[0] = food2;
                                food2_taken = true;
                        }
			else if(ham_has_first == false && food2 != hamburger_food[0] && (food2 == 2 || food2 == 3)){
				hamburger_food[1] = food2;
				ham_has_first = false;
                                food2_taken = true;
                        }

                        
			else if(fries_food[0] == 0 && (food2 == 1 || food2 == 3)){
				fries_food[0] = food2;
                                food2_taken = true;
                        }	
			else if(fries_has_first == false && food2 != fries_food[0] && (food2 == 1 || food2 == 3)){
				fries_food[1] = food2;
				fries_has_first = false;
                                food2_taken = true;
                        }


			else if(soda_food[0] == 0 && (food2 == 1 || food2 == 2)){
				soda_food[0] = food2;
                                food2_taken = true;
                        }
			else if(soda_has_first == false && food2 != soda_food[0] && (food2 == 1 || food2 == 2)){
				soda_food[1] = food2;
				soda_has_first = false;
                                food2_taken = true;
                        }
			else{
				ham_has_first = false;
				fries_has_first = false;
				soda_has_first = false;
			}
                }

		if(food1_taken && food2_taken){
			foodAvail[0] = 0;
			foodAvail[1] = 0;
		}
		
		for(int z = 0; z < 2; z++){
			cout<<"Hamburger Food["<<z<<"] : "<<hamburger_food[z]<< "\tFries Food["<<z<<"] : "<<fries_food[z]<< "\tSoda Food["<<z<<"] : "<<soda_food[z] <<"\n";
		}
		/*//Use functions below to run without threading
		hamburger_customer(foodAvail, hamburger_food, hamburger_eatCount);
		fries_customer(foodAvail, fries_food, fries_eatCount);
		soda_customer(foodAvail, soda_food, soda_eatCount);*/
		
		
		thread ham(hamburger_customer, foodAvail, hamburger_food, std::ref(hamburger_eatCount));
		thread fries(fries_customer, foodAvail, fries_food, std::ref(fries_eatCount));
		thread soda(soda_customer, foodAvail, soda_food, std::ref(soda_eatCount));
		ham.join();
		fries.join();
		soda.join();
		
		cout << "Hamburger customer ate: " << hamburger_eatCount << "\tFries customer ate: " << fries_eatCount << "\tSoda customer ate: " << soda_eatCount << "\n\n";
	}
}
