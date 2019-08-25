/*
 * Register.h
 *
 *  Created on: Nov 5, 2018
 */

#ifndef REGISTER_H_
#define REGISTER_H_

#include "Patient.h"
#include <deque>
#include <limits>

using namespace std;

class Tregister
{
	// variables dealing with queue
	private:
		Patient array[10];
		int front, rear;// front-> front of queue/ rear-> rear of queue
		int size;// size of queue
	//Functions dealing with queue
	public:
		Tregister();
		void AddToQueue (string name, int HCN);
		void DisplayAllPatients();
		void ExaminePatient (condition patientcondition);
		bool IsEmpty ();
		bool IsFull();
		int SizeOfQueue();

};

#endif /* REGISTER_H_ */
