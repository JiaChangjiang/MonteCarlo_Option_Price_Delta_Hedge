//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem1
//	Filename:	other_function_P1.h
//	Version:	v1 (20 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	declare the other functions about the cdf and the PricePortfoiloOfOptions CalculateDeltaRisk functions
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#pragma once
//#include"EuropeanOption_P1.h"
#include"Option_P1.h"
#include<cmath>
double cdf(double x);
double PricePortfoiloOfOptions(const vector <Option*>& set, const vector<int>& call_num);
double CalculatePortfoiloDeltaRisk(const vector <Option*>& set, const vector<int>& call_num, const vector<unsigned int>& shareID);
