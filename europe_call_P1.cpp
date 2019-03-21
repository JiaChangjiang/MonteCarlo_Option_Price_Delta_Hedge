//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem1
//	Filename:	main_P2.cpp
//	Version:	v1 (20 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	define the member function of EuropeanCall
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include"European_Call_P1.h"

EuropeanCall::EuropeanCall(Share& EuropeanCall_underlying, double EuropeanCall_strike0, double EuropeanCall_expiry)
	: EuropeanOption(EuropeanCall_underlying, EuropeanCall_strike0, EuropeanCall_expiry) {}

double EuropeanCall::MonteCarloOption() {
	{long double result = 0;
	for (int i = 0; i < path_number; i++) {
		result = result + std::max(underlying_share.GetSharePath()[i][sample_number] - strike_price, 0.0);
		Simulation_Result.push_back(discount_fac*(std::max(underlying_share.GetSharePath()[i][sample_number] - strike_price, 0.0)));
		//the sample_number=expiry_time*365,for the european call,if year=1 I calculate the day 365 price with max(stock_price-strike_price,)
		//as I said before,I use underlying_share.GetSharePath()[i][sample_number] to get the stock simulation result stored in the share class
	}
	result = (result) / path_number;
	MonteCarloPrice = discount_fac*result;
	return MonteCarloPrice;

	}
};

double  EuropeanCall::PriceOptionAnalytical() {
	//using b-s model to calculate the option price
	double result = (share_price*(cdf(d1)) - strike_price*exp(0 - (interest - dividend)*(T))*cdf(d2))*exp(-dividend*(T));
	return result;
}



double EuropeanCall::MonteCarloDelta()
{
	double dPrice = DeltaCalculate_DifferentialSharePrice;
	double DeltaResult0 = 0;
	double temp0=0;
	double temp1=0;
	{long double result = 0;
	for (int i = 0; i < path_number; i++) {
// for delta calculation. I also shift the path by multiplying a small coefficient and for european option ,we just adjust the expiry day value is ok.
		temp0= temp0 + std::max(underlying_share.GetSharePath()[i][sample_number]*(1- dPrice) - strike_price, 0.0);
		temp1 = temp1 + std::max(underlying_share.GetSharePath()[i][sample_number]*(1 + dPrice) - strike_price, 0.0);
	}

	result = (temp1 - temp0)*discount_fac / (2 * underlying_share.GetSharePrice()*dPrice);
	result = (result) / path_number;
	MonteCarloDelta_Result = result;
	return result;

	}


	
}

