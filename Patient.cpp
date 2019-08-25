/*
 * Patient.cpp
 *
 *  Created on: Nov 5, 2018
 *      Author: l2hason
 */
#include <iostream>
#include <stdio.h>
#include "Register.h"
#include "Patient.h"
using namespace std;
#include <limits>
//Intializes Patient type

Patient::Patient()
{

	patient_condition = UNKNOWN;
	cervix_dilation = 0;
	health_card= 0;
}
//Stores name
void Patient::setName (string name)
{
	this->name = name;
}
//Stores Health card number
void Patient::setHealthCardNo (int x)
{
	health_card = x;
}
//Decides Patient condition
void Patient::setPatientCondition (condition patient_condition)
{
	this->patient_condition = patient_condition;
}
//Stores cervix dilation
void Patient::setCervixDilation (int e)
{
	cervix_dilation= e;
}
//Displays name of patient
void Patient::Displayname(Patient x)
{
	cout<<"Name:   "<<x.name<<endl;
}
//Displays patient's data
void Patient::displayPatientData()
{
	cout <<name<<"    "<<health_card<<"   "<<cervix_dilation;
	if (patient_condition == UNKNOWN)
	{
		cout<<"  UNKNOWN"<<endl;
	}
	else if (patient_condition == LABOUR)
	{
		cout<<"  LABOUR"<<endl;
	}
	else if (patient_condition == ADMIT)
	{
		cout<<"  ADMIT"<<endl;
	}
}




