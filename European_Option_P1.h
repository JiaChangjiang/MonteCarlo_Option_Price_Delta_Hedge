#pragma once
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem1
//	Filename:	European_Option_P1.h
//	Version:	v1 (3 Mar 2019)
//	Author:		Changjiang Jia
//	Summary:	declare the member function of class EuropeanPut
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include"Option_P1.h"
#include<algorithm>
#include"other_function_P1.h"

using namespace std;
class EuropeanOption :public Option {
public:
	 ~EuropeanOption() {};
	EuropeanOption::EuropeanOption(Share & EuropeanOption_underlying, double  EuropeanOption_strike0, double  EuropeanOption_expiry);
	
protected:
	//the base member is defined as protected to be inherited here is the some necessary varoable for calculate the analytical price for european option
	double share_price;
	double volatility;
	double dividend;
	double d1;
	double d2;


};



