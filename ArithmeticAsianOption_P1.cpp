//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem1
//	Filename:	ArithmeticAsianOption_P1.cpp
//	Version:	v3 (8 Mar 2019)
//	Author:		Changjiang Jia
//	Summary:	define the member function of Asian option

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


#include"ArithmeticAsianOption_P1.h"

double ArithmeticAsianCallOption::VectorAverage(const vector<double>& s) {
	//given the simulate share price path,this function is used to calculate the mean of the share price with sample_number
	//if the expiry year =1,the sample_number is 1*365=365.the function will calculate the mean price from day1 to day 365
		double result = 0;
		for (int i = 1; i <= sample_number; i++) {
			result = result + s[i] / sample_number;
		}
		return result;
	}

	
double ArithmeticAsianCallOption::PriceOptionAnalytical() { return -1; };
//as for there is no analytical formula for asian option,here just return -1 to show there is no analytical price



ArithmeticAsianCallOption::ArithmeticAsianCallOption(Share & Option_underlying0, double  Option_strike0, double  Option_expiry0)
		:Option(Option_underlying0, Option_strike0, Option_expiry0)
	{
	}
	
double ArithmeticAsianCallOption::MonteCarloOption() {
		{long double result = 0;
		for (int i = 0; i < path_number; i++) {
			double AveragePrice = VectorAverage((underlying_share.GetSharePath())[i]);
			//use the defined function to calculate the average price
			Simulation_Result.push_back(discount_fac*std::max(AveragePrice - strike_price, 0.0));
			//save the every path's result in order to export to txt 
			result = result + std::max(AveragePrice - strike_price, 0.0);
		}
		result = result / path_number;
		MonteCarloPrice = result*discount_fac;
		return MonteCarloPrice;

		}
	};
	
double  ArithmeticAsianCallOption::MonteCarloDelta() {
		double dPrice = DeltaCalculate_DifferentialSharePrice;
		double temp0 = 0;
		double temp1 = 0;
		{long double result = 0;
		for (int i = 0; i < path_number; i++) {
			//for asian option, the logic of calculating the delta is same,because we shift the every path to get a new path
			//we just need to let the original average share price multiply the shift coeffiecient (1-dPrice)
			double AveragePrice = (1-dPrice)*VectorAverage((underlying_share.GetSharePath())[i]);
			temp0 = temp0 + std::max(AveragePrice - strike_price, 0.0);
			 AveragePrice = (1+dPrice)*VectorAverage((underlying_share.GetSharePath())[i]);
			temp1 = temp1 + std::max(AveragePrice - strike_price, 0.0);
		}
		result = discount_fac*(temp1-temp0) /( 2*dPrice*underlying_share.GetSharePrice()*path_number);
		MonteCarloDelta_Result = result;
		return result;

		}

	}




	double  ArithmeticAsianPutOption::VectorAverage(const vector<double>& s) {
		double result = 0;
		for (int i = 1; i <= sample_number; i++) {
			result = result + s[i] / sample_number;
			//given the simulate share price path,this function is used to calculate the mean of the share price with sample_number
	//for example,if the expiry year =1,the sample_number is 1*365=365.the function will calculate the mean price from day1 to day 365
		}
		return result;
	}


	double  ArithmeticAsianPutOption::PriceOptionAnalytical() { return -1; };
	//as for there is no analytical formula for asian option,here just return -1 to show there is no analytical price


	ArithmeticAsianPutOption::ArithmeticAsianPutOption(Share & Option_underlying0, double  Option_strike0, double  Option_expiry0)
		:Option(Option_underlying0, Option_strike0, Option_expiry0)
	{
	}
	double ArithmeticAsianPutOption::MonteCarloOption() {
		{long double result = 0;
		for (int i = 0; i < path_number; i++) {
			double AveragePrice = VectorAverage((underlying_share.GetSharePath())[i]);
			Simulation_Result.push_back(discount_fac*std::max(strike_price - AveragePrice, 0.0));
			result = result + std::max(strike_price - AveragePrice, 0.0);
		}
		result = result / path_number;
		MonteCarloPrice = result*discount_fac;
		return result*discount_fac;

		}
	};


	double  ArithmeticAsianPutOption::MonteCarloDelta() {
		{
			double dPrice = DeltaCalculate_DifferentialSharePrice;
			double temp0 = 0;
			double temp1 = 0;
			{long double result = 0;
			for (int i = 0; i < path_number; i++) {
				double AveragePrice = (1 - dPrice)*VectorAverage((underlying_share.GetSharePath())[i]);
				temp0 = temp0 + std::max(strike_price- AveragePrice , 0.0);
				 AveragePrice = (1 + dPrice)*VectorAverage((underlying_share.GetSharePath())[i]);
				temp1 = temp1 + std::max(strike_price-AveragePrice, 0.0);
			}
			result = discount_fac*(temp1 - temp0) / (2 * dPrice*underlying_share.GetSharePrice()*path_number);
			MonteCarloDelta_Result = result;
			return result;

			}

		}

	}


