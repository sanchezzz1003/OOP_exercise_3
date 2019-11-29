#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#include "Figure.h"


int main(){
	vector <Figure*> objects;
	int action = 0, i = 0, arg = 0, number;



	do{
		cout << "Options:\n";
		cout << "1. Create figure\n";
		cout << "2. Print all figures\n";
		cout << "3. Print information about figure\n";
		cout << "4. Print total square\n";
		cout << "5. Delete figure from vector\n";
		cout << "6. Quit\n";
	    cout << "Enter Option:  ";
	    while (!(cin >> action))
	    { 
	        cin.clear(); 
	        cout << "Wrong argument\nEnter Option: ";
	        char c;
	        cin >> c;
	    }

	    switch(action){
	    	case 1:
	    	{
	    		cout << "Choose type of the figure:\n1. Triangle\n2. Hexagon\n3. Octagon\n";
	    		cin >> arg;
	    		switch(arg){
	    			case 1:
	    			{
	    				objects.push_back(new Triangle(i+1, 3));
	    				++i;
	    			}
	    			break;
	    			case 2:
	    			{
	    				objects.push_back(new Hexagon(i+1, 6));
	    				++i;
	    			}
	    			break;
	    			case 3:
	    			{
	    				objects.push_back(new Octagon(i+1, 8));
	    				++i;
	    			}
	    			break;
	    		}
	    	}
	    	break;

	    	case 2:
	    	{
	    		for (int j = 0; j < i; ++j){
	    			objects[j]->Angles();
	    		}
	    	}
	    	break;

	    	case 3:{
	    		cout << "Enter figure ID:\n";
	    		cin >> number;
	    		for (int j = 0; j <= i; ++j){
	    			if (j == i){
	    				cout << "Wrong ID\n"; 
	    				break;
	    			}
	    			if (j+1 == number){
	    				objects[j]->Angles();
	    				objects[j]->Center();
	    				cout << "Figure " << objects[j]->getID() << " square is " << objects[j]->Square() << endl;
	    				break;
	    			}
	    		}
	    	}
	    	break;

	    	case 4:
	    	{
	    		double sumSquare = 0;
	    		for (int j = 0; j < i; ++j)
	    			sumSquare += objects[j]->Square();
	    		cout << "Total square is " << sumSquare << endl;
	    	}
	    	break;

	    	case 5:
	    	{
				cout << "Enter figure ID to delete:\n";
				cin >> number;
				while (number > i){
						cout << "Wrong ID\n";
						cin >>  number;
					}
					for (int j = 0; j <= i; ++j){
						if (j+1 == number){
							delete objects[j];
							auto iter = objects.cbegin(); 
							objects.erase(iter + j);
							i--;
						}
						if (j+1 >= number){
							objects[j]->setID(j+1);
						}
					}
	    	}
	    	break;

	    	default:
	    	{
	    		cout << "Wrong Option\n";
	    	}
	    }

	}while (action != 6);



	return 0;
}

