//============================================================================
// Name        : lab05.cpp
// Author      : Adithya Shankar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Register.h"
#include "Patient.h"
#include <limits>
using namespace std;


int main(int argc, const char * argv[]){

	Tregister reg;
	string name= "";
	int HCN;
	condition patientCondition;
	int choice;

	do
	{
		cout<<"============================================"<<endl<<endl
		<<"There are currently "<< reg.SizeOfQueue()<<" patient(s) in the list"<<endl<<endl
		<<"Please choose an option:"<<endl
		<<"1. Register Patient"<<endl
		<<"2. Examine Patient"<<endl
		<<"3. Display Patients"<< endl
		<<"4. Quit"<<endl;

		cin>>choice;// User input to choose function
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch(choice){
			case 1:
				// get data from user
				cout<<"==================="<<endl;
				cout<<"[Register Patient]"<<endl;
				cout<<"Enter Name:";
				getline (cin, name);
				cout<<"Enter Health Card Number:";
				cin>> HCN;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				reg.AddToQueue(name,HCN);

				break;
			case 2:
				//Examine data
				cout <<"Examine Patient"<<endl;
				reg.ExaminePatient(patientCondition);

				break;

			case 3:
				//Display data
				cout<<"[Display Patients]"<<endl;
				reg.DisplayAllPatients();

				break;

			default:
				break;
		}
	}while (choice!=4);// choice 4 quits program
		return 0;
}

