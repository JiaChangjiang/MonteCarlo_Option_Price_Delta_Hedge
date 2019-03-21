//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem1
//	Filename:	EuropeanPut_P1.h
//	Version:	v1 (20 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	declare the member function of class EuropeanPut
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#pragma once
//#include"Option_P1.h"
#include"European_Option_P1.h"

class EuropeanPut : public EuropeanOption{
public:
	~EuropeanPut() {};
	EuropeanPut(Share& EuropeanPut_underlying, double EuropeanPut_strike0, double EuropeanPut_expiry) : EuropeanOption(EuropeanPut_underlying, EuropeanPut_strike0, EuropeanPut_expiry)
	{}
	double PriceOptionAnalytical();
	double MonteCarloOption();
	double MonteCarloDelta();
};
