//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem1
//	Filename:	BarrierOptionBaseClass_P1.cpp
//	Version:	v3 (8 Mar 2019)
//	Author:		Changjiang Jia
//	Summary:	define the member function of Barrier option
//I write the monte carlo price and analytic price and monte carlo delta in this function
//for each sub-class of barrier option, they only return the value to show which type it is 
//
// 2.GetSubClassInorOut if the option is knock - in option return 1, out return 0
//3 GetSubClassCallorPut  if the option is Call option return 1,put return 0
//4 GetSubClassUporDown if the option is Up option return 1,Down return0
//
//and the specific formula is stored in the base class Barrier Option,which will be easy to mange
//code and improve the performance
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


#include"BarrierOption_P1.h"
#include"EuropeanPut_P1.h"
#include"European_Call_P1.h"
#include"BarrierOptionSubclass_P1.h"
using namespace std;
	double BarrierOption :: PriceOptionAnalytical(void) {
		//this function is used to calculate the analytical value of the option
		//because the formula is so long ,we can calculate some terms before judge which kind of option is
		double s0 = underlying_share.GetSharePrice();
		double k = strike_price;
		double q = 0;
		double h = Barrier_Price;
		double r = interest;
		double v = underlying_share.GetShareVolatility();
		double lmada = (r - q + pow(v, 2) / 2) / (pow(v, 2));
		double y = log(h*h / (s0*k)) / (v*sqrt(T)) + lmada*v*sqrt(T);
		double x1 = log(s0 / h) / (v*sqrt(T)) + lmada*v*sqrt(T);
		double y1 = log(h / s0) / (v*sqrt(T)) + lmada*v*sqrt(T);
		int option_kind = 100 * GetSubClassUporDown() + 10 * GetSubClassInorOut() + GetSubClassCallorPut();
		//this variable option_kind can tell how to identify each option and decide which formula to calcualte
		switch (option_kind)
		{
		case((111)) : {//UpInCall
			double result = s0*cdf(x1)*exp(-q*T) - k*exp(-r*T)*cdf(x1 - v*sqrt(T)) - s0*exp(-q*T)*pow((h / s0), 2 * lmada)*(cdf(-y) - cdf(-y1)) + k*exp(-r*T)*pow((h / s0), 2 * lmada - 2)*(cdf(-y + v*sqrt(T)) - cdf(-y1 + v*sqrt(T)));
			return result;
			break;
		}

		case(110) : {//UpInPut
			double result = -s0*exp(-q*T)*pow((h / s0), 2 * lmada)*cdf(-y) + k*exp(-r*T)*pow((h / s0), 2 * lmada - 2)*cdf(-y + v*sqrt(T));
			return result;
			break;
		}
		case(101) : {//UpOutCall
			double result = s0*cdf(x1)*exp(-q*T) - k*exp(-r*T)*cdf(x1 - v*sqrt(T)) - s0*exp(-q*T)*pow((h / s0), 2 * lmada)*(cdf(-y) - cdf(-y1)) + k*exp(-r*T)*pow((h / s0), 2 * lmada - 2)*(cdf(-y + v*sqrt(T)) - cdf(-y1 + v*sqrt(T)));
			result = EuropeanCall(underlying_share, k, T).PriceOptionAnalytical() - result;
			return result;
			break;
		}
		case(100) : {//UpOutPut
			double result = -s0*exp(-q*T)*pow((h / s0), 2 * lmada)*cdf(-y) + k*exp(-r*T)*pow((h / s0), 2 * lmada - 2)*cdf(-y + v*sqrt(T));
			result = EuropeanPut(underlying_share, k, T).PriceOptionAnalytical() - result;
			return result;
			break;
		}

		case(11) : {//DownInCall
			double result = s0*exp(-q*T)*pow((h / s0), 2 * lmada)*cdf(y) - k*exp(-r*T)*pow((h / s0), 2 * lmada - 2)*cdf(y - v*sqrt(T));
			return result;
			break;
		}

		case(10) : {//DownAndInPutOption
			double result = -s0*cdf(-x1)*exp(-q*T) + k*exp(-r*T)*cdf(-x1 + v*sqrt(T)) + s0*exp(-q*T)*pow((h / s0), 2 * lmada)*(cdf(y) - cdf(y1)) - k*exp(-r*T)*pow((h / s0), 2 * lmada - 2)*(cdf(y - v*sqrt(T)) - cdf(y1 - v*sqrt(T)));
			return result;

			break;
		}
		case(1) : {//DownOutCal
			double result = s0*exp(-q*T)*pow((h / s0), 2 * lmada)*cdf(y) - k*exp(-r*T)*pow((h / s0), 2 * lmada - 2)*cdf(y - v*sqrt(T));
			result = EuropeanCall(underlying_share, k, T).PriceOptionAnalytical() - result;
			return result;
			break;
		}
		case(0) : {//DownAndOutPutOption
			double result = -s0*cdf(-x1)*exp(-q*T) + k*exp(-r*T)*cdf(-x1 + v*sqrt(T)) + s0*exp(-q*T)*pow((h / s0), 2 * lmada)*(cdf(y) - cdf(y1)) - k*exp(-r*T)*pow((h / s0), 2 * lmada - 2)*(cdf(y - v*sqrt(T)) - cdf(y1 - v*sqrt(T)));
			result = EuropeanPut(underlying_share, k, T).PriceOptionAnalytical() - result;
			return result;
			break;
		}

		default:
			return 0;
			break;
		}

	}


	BarrierOption::BarrierOption(Share & Option_underlying0, double  Option_strike0, double Option_expiry0, double Barrier0)
		:Option(Option_underlying0, Option_strike0, Option_expiry0), Barrier_Price(Barrier0)
	{}
	//the constructor


	//define up and dowm option and generate the feasiable path
	BarrierUpOption::BarrierUpOption(Share & EuropeanOption_underlying, double  EuropeanOption_strike0, double  EuropeanOption_expiry, double Barrier0)
		:BarrierOption(EuropeanOption_underlying, EuropeanOption_strike0, EuropeanOption_expiry, Barrier0) {
		FeasiablePath = {};//feasiable has been defined in the base class BarrierOption
		for (int i = 0; i < path_number; i++) {
			FeasiablePath.push_back(0);
			//assume the path dose not work.for up option,if it up the barrier price we change 0 to1
			for (int j = 1; j <= sample_number; j++) {//check every step of  path i
				if (((underlying_share.GetSharePath()[i])[j]) >= Barrier_Price) {
					FeasiablePath[i] = 1;//if path i can work,change the 0 to 1
					break;
				}

			}

		}
	}

	BarrierDownOption::BarrierDownOption(Share & Option_underlying0, double  Option_strike0, double Option_expiry0, double Barrier0)
		:BarrierOption(Option_underlying0, Option_strike0, Option_expiry0, Barrier0) {
		FeasiablePath = {};

		for (int i = 0; i < path_number; i++) {
			FeasiablePath.push_back(0);
			//assume the path dose not work.for down option,if it  is down the barrier price we change 0 to1
			for (int j = 1; j <= sample_number; j++) {
				if (((underlying_share.GetSharePath()[i])[j]) <= Barrier_Price) {//check every step of  path i
					FeasiablePath[i] = 1;//if path i can work,change the 0 to 1
					break;
				}

			}

		}

	}


	double  BarrierOption::MonteCarloOption(void) {
		//Here I write all calculate in there,it is easy to manange and change the code.you don't have to check every sub-class option
		double result = 0;
		int option_kind = 100 * GetSubClassUporDown() + 10 * GetSubClassInorOut() + GetSubClassCallorPut();
		switch (option_kind)
		{
		case((111)) : {//UpInCall
			{
				for (int i = 0; i < path_number; i++) {
					//for up and in option,we first calculate the possible payoff
					double payoff = std::max(underlying_share.GetSharePath()[i][sample_number] - strike_price, 0.0);
					if (!FeasiablePath[i]) {
						//if the path dose not work,push back 0 in simulation result
						Simulation_Result.push_back(0);
					}
					if (FeasiablePath[i]) {
						////if the path works,push back payoff*discount_factor
						Simulation_Result.push_back(payoff*discount_fac);
						result = result + payoff*discount_fac / (path_number);
					}

				}
				MonteCarloPrice = result;
				return result;
			}
			break;
		}

		case(110) : {//UpInPut
			{
				for (int i = 0; i < path_number; i++) {
					double payoff = std::max(strike_price - underlying_share.GetSharePath()[i][sample_number], 0.0);
					if (!FeasiablePath[i]) {
						Simulation_Result.push_back(0);
					}
					if (FeasiablePath[i]) {
						Simulation_Result.push_back(payoff*discount_fac);
						result = result + payoff*discount_fac / (path_number);
					}

				}
				MonteCarloPrice = result;
				return result;
			}
			break;
		}
		case(101) : {//UpOutCall
			{
				for (int i = 0; i < path_number; i++) {
					double payoff = std::max(underlying_share.GetSharePath()[i][sample_number] - strike_price, 0.0);
					if (FeasiablePath[i]) {
						//for out option the feasiable path means it can not work ,the specific reason  is in BarrierOption_P1.h file.
						//so I push back 0 in the result
						Simulation_Result.push_back(0);
					}
					if (!FeasiablePath[i]) {
						//we inverse the feasiable path to 
						Simulation_Result.push_back(payoff*discount_fac);
						result = result + payoff*discount_fac / (path_number);
					}

				}
				MonteCarloPrice = result;
				return result;
			}
			break;
		}
		case(100) : {//UpOutPut
			for (int i = 0; i < path_number; i++) {
				double payoff = std::max(strike_price - underlying_share.GetSharePath()[i][sample_number], 0.0);
				if (FeasiablePath[i]) {
					Simulation_Result.push_back(0);
				}
				if (!FeasiablePath[i]) {
					Simulation_Result.push_back(payoff*discount_fac);
					result = result + payoff*discount_fac / (path_number);
				}

			}
			MonteCarloPrice = result;
			return result;
			break;
		}

		case(11) : {//DownInCall
			{
				for (int i = 0; i < path_number; i++) {
					double payoff = std::max(underlying_share.GetSharePath()[i][sample_number] - strike_price, 0.0);
					if (!FeasiablePath[i]) {
						Simulation_Result.push_back(0);
					}
					if (FeasiablePath[i]) {
						Simulation_Result.push_back(payoff*discount_fac);
						result = result + payoff*discount_fac / (path_number);
					}

				}

			}
			MonteCarloPrice = result;
			return result;
			break;
		}

		case(10) : {//DownAndInPutOption
			for (int i = 0; i < path_number; i++) {
				double payoff = std::max(strike_price - underlying_share.GetSharePath()[i][sample_number], 0.0);
				if (!FeasiablePath[i]) {
					Simulation_Result.push_back(0);
				}
				if (FeasiablePath[i]) {
					Simulation_Result.push_back(payoff*discount_fac);
					result = result + payoff*discount_fac / (path_number);
				}

			}
			MonteCarloPrice = result;
			return result;
			break;
		}
		case(1) : {//DownOutCal
			{
				for (int i = 0; i < path_number; i++) {
					double payoff = std::max(underlying_share.GetSharePath()[i][sample_number] - strike_price, 0.0);
					if (FeasiablePath[i]) {
						Simulation_Result.push_back(0);
					}
					if (!FeasiablePath[i]) {
						Simulation_Result.push_back(payoff*discount_fac);
						result = result + payoff*discount_fac / (path_number);
					}

				}
				MonteCarloPrice = result;
				return result;
			}
			break;
		}
		case(0) : {//DownAndOutPutOption
			for (int i = 0; i < path_number; i++) {
				double payoff = std::max(strike_price - underlying_share.GetSharePath()[i][sample_number], 0.0);
				if (FeasiablePath[i]) {
					Simulation_Result.push_back(0);
				}
				if (!FeasiablePath[i]) {
					Simulation_Result.push_back(payoff*discount_fac);
					result = result + payoff*discount_fac / (path_number);
				}


			}
			MonteCarloPrice = result;
			return result;
			break;
		}

		default:
			return 0;
			break;
		}


	}






	double BarrierOption::MonteCarloDelta() {
		double dPrice = DeltaCalculate_DifferentialSharePrice;
		double DeltaResult0 = 0;
		Share NewShare0(underlying_share);
		Share NewShare1(underlying_share);
		//using copy constructor to copy orginal share's path

		for (int i = 0; i < path_number; i++) {//shift every path with same coefficient to get two new share paths
			for (int j = 1; j <= sample_number; j++) {
				NewShare0.GetSharePath()[i][j] = NewShare0.GetSharePath()[i][j] * (1 - dPrice);
				NewShare1.GetSharePath()[i][j] = NewShare1.GetSharePath()[i][j] * (1 + dPrice);
			}
		}
		int option_kind = 100 * GetSubClassUporDown() + 10 * GetSubClassInorOut() + GetSubClassCallorPut();
		//this value is used to identify the kind of specific option
		dPrice = underlying_share.GetSharePrice() * 2 * dPrice;
		//calculate the the differce of two new share starting price
		GetDifferentBarrierOptionDelta(NewShare0, NewShare1, option_kind, DeltaResult0, strike_price, Barrier_Price, T, dPrice);
		//call the function to calculate delta of the two new shares 
		MonteCarloDelta_Result = DeltaResult0;
		return DeltaResult0;


	};


	void GetDifferentBarrierOptionDelta(Share& NewShare0, Share& NewShare1, const int& option_kind, double& DeltaResult, const double& strike_price, const double& Barrier_Price, const double& T, const double& dPrice)
	{//here we can create different sub class option can calculate the delta ,notice the reference of DeltaResult is not const,beacause I want to
		//change the value directly
		switch (option_kind)
		{//according to different option_kinds we will create different option to calculate the delta
		case((111)) : {
			UpAndInCallOption NewTempOption0(NewShare0, strike_price, T, Barrier_Price);
			UpAndInCallOption NewTempOption1(NewShare1, strike_price, T, Barrier_Price);
			DeltaResult = CalculateDelta(NewTempOption0, NewTempOption1, dPrice);
			//this function can return the result of the delta.because i define the monte carlo price function in the base class Option,Now use 
			//the Polymorphism of the base class to calculate the monte carlo price
			break;
		}


		case(110) : {
			UpAndInPutOption NewTempOption0(NewShare0, strike_price, T, Barrier_Price);
			UpAndInPutOption NewTempOption1(NewShare1, strike_price, T, Barrier_Price);
			DeltaResult = CalculateDelta(NewTempOption0, NewTempOption1, dPrice);
			break;
		}
		case(101) : {
			UpAndOutCallOption NewTempOption0(NewShare0, strike_price, T, Barrier_Price);
			UpAndOutCallOption NewTempOption1(NewShare1, strike_price, T, Barrier_Price);
			DeltaResult = CalculateDelta(NewTempOption0, NewTempOption1, dPrice);
			break;
		}
		case(100) : {
			UpAndOutPutOption NewTempOption0(NewShare0, strike_price, T, Barrier_Price);
			UpAndOutPutOption  NewTempOption1(NewShare1, strike_price, T, Barrier_Price);
			DeltaResult = CalculateDelta(NewTempOption0, NewTempOption1, dPrice);
			break;
		}

		case(11) : {
			DownAndInCallOption NewTempOption0(NewShare0, strike_price, T, Barrier_Price);
			DownAndInCallOption NewTempOption1(NewShare1, strike_price, T, Barrier_Price);
			DeltaResult = CalculateDelta(NewTempOption0, NewTempOption1, dPrice);
			break;
		}

		case(10) : {
			DownAndInPutOption NewTempOption0(NewShare0, strike_price, T, Barrier_Price);
			DownAndInPutOption NewTempOption1(NewShare1, strike_price, T, Barrier_Price);
			Option* ptr = &NewTempOption1;
			DeltaResult = CalculateDelta(NewTempOption0, NewTempOption1, dPrice);
			break;
		}
		case(1) : {
			DownAndOutCallOption NewTempOption0(NewShare0, strike_price, T, Barrier_Price);
			DownAndOutCallOption NewTempOption1(NewShare1, strike_price, T, Barrier_Price);
			DeltaResult = CalculateDelta(NewTempOption0, NewTempOption1, dPrice);
			break;
		}
		case(0) : {
			DownAndOutPutOption NewTempOption0(NewShare0, strike_price, T, Barrier_Price);
			DownAndOutPutOption  NewTempOption1(NewShare1, strike_price, T, Barrier_Price);
			DeltaResult = CalculateDelta(NewTempOption0, NewTempOption1, dPrice);
			break;
		}

		default:
			break;
		}

	}

	double CalculateDelta(Option& NewOption0, Option& NewOption1, double dPrice) {
		double r1 = NewOption1.MonteCarloOption();
		double r0 = NewOption0.MonteCarloOption();
		return((r1 - r0) / (dPrice));
	}
