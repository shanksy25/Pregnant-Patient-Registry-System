/*
 * Patient.h
 *
 *  Created on: Nov 5, 2018
 *      Author: l2hason
 */

#ifndef PATIENT_H_
#define PATIENT_H_

#include <string>
#include <limits>
using namespace std;
//Patient conditions
enum condition {UNKNOWN, LABOUR, ADMIT};
//Patient class stores data
class Patient
{
	private:
		string name;
		int health_card;
		condition patient_condition;
		int cervix_dilation;
	//Functions relating to patient data storage and display
	public:
		Patient();
		void setName(string name);
		void setHealthCardNo(int x);
		void setPatientCondition (condition patient_condition);
		void setCervixDilation (int e);
		void Displayname (Patient x);
		void displayPatientData ();
};


#endif /* PATIENT_H_ */
