//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem1
//	Filename:	European_Call_P1.h
//	Version:	v1 (20 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	declare the member function of class  EuropeanCall
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#pragma once
#include"European_Option_P1.h"

class  EuropeanCall :public EuropeanOption {
public:
	//EuropeanCall() {};
	//virtual ~EuropeanCall() {};
	EuropeanCall::EuropeanCall(Share& EuropeanCall_underlying, double EuropeanCall_strike0, double EuropeanCall_expiry);
	double PriceOptionAnalytical();
	//get the analytical price for the option
	double MonteCarloOption();
	//get the montecarlo price for the option
	double MonteCarloDelta();
	//get the monte carlo  delta for the option


};
