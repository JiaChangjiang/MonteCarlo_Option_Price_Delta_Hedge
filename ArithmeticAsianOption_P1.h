//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem1
//	Filename:	ArithmeticAsianOption_P1.h
//	Version:	v1 (20 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	declare the base class ArithmeticAsianOption
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#pragma once
#include"Option_P1.h"
#include<algorithm>
using namespace std;
class ArithmeticAsianCallOption :public Option {
public:
	double VectorAverage(const vector<double>& s);
	double PriceOptionAnalytical();
	ArithmeticAsianCallOption::ArithmeticAsianCallOption(Share & EuropeanOption_underlying, double  EuropeanOption_strike0, double  EuropeanOption_expiry);
	double MonteCarloOption();
	double MonteCarloDelta();


};


class ArithmeticAsianPutOption :public Option {
public:
	double VectorAverage(const vector<double>& s);
	double PriceOptionAnalytical() ;
	ArithmeticAsianPutOption::ArithmeticAsianPutOption(Share & EuropeanOption_underlying, double  EuropeanOption_strike0, double  EuropeanOption_expiry);
	double MonteCarloOption() ;
	double MonteCarloDelta();


};


