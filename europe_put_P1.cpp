//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem1
//	Filename:	europe_put_P1.cpp
//	Version:	v1 (20 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	defination of the member functions in EuropeanCall
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


#include"EuropeanPut_P1.h"

double  EuropeanPut::PriceOptionAnalytical() {
	//using b-s model to calculate the option price
	double result = (exp(-(interest)*T)*(strike_price*cdf(-d2))) - (share_price*exp(-dividend*T)*cdf(-d1));
	return result;
}


double EuropeanPut::MonteCarloDelta()
{
	{
		double dPrice = DeltaCalculate_DifferentialSharePrice;
		double DeltaResult0 = 0;
		double temp0 = 0;
		double temp1 = 0;
		{long double result = 0;
		for (int i = 0; i < path_number; i++) {
			// for delta calculation. I also shift the path by multiplying a small coefficient and for european option ,we just adjust the expiry day value is ok.
			temp0 = temp0 + std::max(strike_price-underlying_share.GetSharePath()[i][sample_number] * (1 - dPrice) , 0.0);
			temp1 = temp1 + std::max(strike_price-underlying_share.GetSharePath()[i][sample_number] * (1 + dPrice), 0.0);
		}
		//
		result = (temp1 - temp0)*discount_fac / (2 * underlying_share.GetSharePrice()*dPrice);
		result = (result) / path_number;
		MonteCarloDelta_Result = result;
		return result;

		}



	}


}
double EuropeanPut::MonteCarloOption() {
	{
		{long double result = 0;
		for (int i = 0; i < path_number; i++) {
			// for european put,we just need to judge the condition on the expiry day
			result = result + std::max(strike_price - underlying_share.GetSharePath()[i][sample_number], 0.0);
			Simulation_Result.push_back(discount_fac*std::max(strike_price - underlying_share.GetSharePath()[i][sample_number], 0.0));
			//store every path's price in the simulation_result in case of exporting data and analyze the error
		}
		result = (result) / path_number;
		MonteCarloPrice = discount_fac*result;
		return discount_fac*result;

		}
	};
}
