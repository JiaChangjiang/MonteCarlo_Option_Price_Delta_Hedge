//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem1
//	Filename:	EuropeanOption_P1.cpp
//	Version:	v1 (20 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	defination of member function of the base class
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include"European_Option_P1.h"

EuropeanOption::EuropeanOption(Share & EuropeanOption_underlying, double  EuropeanOption_strike0, double  EuropeanOption_expiry)
	:Option(EuropeanOption_underlying, EuropeanOption_strike0, EuropeanOption_expiry)
{
	dividend = 0;
	share_price = EuropeanOption_underlying.GetSharePrice();
	volatility = EuropeanOption_underlying.GetShareVolatility();
	d1 = (log(share_price / strike_price) + ((interest - dividend) + 0.5*volatility*volatility)*T) / (volatility*sqrt(T));//calculate the d1 for further calculating the greeks 
	d2 = d1 - volatility*sqrt(T);
}

