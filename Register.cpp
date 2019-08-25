/*
 * Register.cpp
 *
 *  Created on: Nov 5, 2018
 *      Author: l2hason
 */

#include "Patient.h"
#include "Register.h"
#include <stdio.h>

#include <iostream>
using namespace std;

// Initializes Register type
Tregister::Tregister()
{
	front= -1;
	rear = -1;
	size = 0;
}

//If queue is empty returns true
bool Tregister:: IsEmpty()
{
	return (front == -1 && rear == -1);
}
//If queue is full returns false
bool Tregister:: IsFull()
{
	if (((rear+1)%10)== front)
	{
		return true;
	}
	else
		return false;
}
//Adds patient to queue - ENQUEUE
void Tregister::AddToQueue (string name, int HCN)
{
	Patient x;
	x.setName(name);
	x.setHealthCardNo(HCN);
//If queue is full returns to main
	if (IsFull())
	{
		cout<<"Error: Queue is Full\n";
		return;
	}
	size++;// increments patient size after adding a patient

	//If queue is empty initializes
	if (IsEmpty())
	{
		front= rear = 0;
	}
	//increment rear value monitoring end of queue
	else
	{
		rear= (rear+1)%10;
	}
	array[rear]= x;
	cout<<"..[Registering]"<<endl;
}
void Tregister::ExaminePatient (condition patientCondition)
{
	if (front == -1)
	{
		return;
	}
	else
	{
		Patient x= array[front];
		int cervixDilation;

		x.Displayname(x);
		cout<<"Enter cervix dilation: "<<endl;
		cin>> cervixDilation;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		x.setCervixDilation (cervixDilation);

	if (patientCondition == UNKNOWN)// If a patient's condition is UNKNOWN
	{
		if (cervixDilation >=4)// If the patients's cervix dialtion is >= 4cm, her condition gets changed to ADMIT
		{
			patientCondition= ADMIT;
			x.setPatientCondition(ADMIT);
			cout <<".. [Admitting]"<<endl;
			size--;
			x.displayPatientData();
			if (front == rear)
			{
				rear = front = -1;
			}
			else
			{
				front = front +1;
				if (front ==10)
				{
					front = 0;
				}
			}
		}
		if (cervixDilation <4)// If the patients's cervix dialtion is < 4cm, her condition gets changed to LABOUR
			// The patient again gets added back to the end of the queue
		{
			patientCondition = LABOUR;
			x.setPatientCondition(LABOUR);
			cout<<".. [Going back to queue]"<<endl;
			if (front == rear)
			{
				array[rear] = x;
			}
			else
			{
				front = front +1;
				if (front == 11)
				{
					front =0;
				}
				rear = (rear+1)%10;
				array[rear] = x;
			}
		}
	}
	else if (patientCondition == LABOUR)
	{
		if (cervixDilation >=4)
		{
			patientCondition = ADMIT;
			x.setPatientCondition(ADMIT);
			cout<<".. [Admitting]"<< endl;
			x.displayPatientData();
			size--;
			if (front == rear)
			{
				rear = front = -1;
			}
			else
			{
				front = front +1;
				if (front == 11)
				{
					front = 0;
				}
			}
		}
		if (cervixDilation < 4)
		{
			cout <<".. [Going back to queue]"<<endl;
			if (front == rear)
			{
				array[rear] = x;
			}
			else
				{
				front = front +1;
				if (front == 11)
				{
					front =0;
				}
				rear = (rear+1)% 10;
				array[rear]=x;
				}
			}
		}
}
}
// loops through entire queue to display each patient's data
void Tregister:: DisplayAllPatients()
{
	for (int q = front; q <= rear; q++)
	{
		array[q].displayPatientData();

	}
}
//size of queue
int Tregister::SizeOfQueue()
{
	return size;

}



