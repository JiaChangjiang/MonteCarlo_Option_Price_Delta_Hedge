#pragma once
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem1
//	Filename:	Option_P1.h
//	Version:	v1 (20 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	declare the base class Option
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include<cmath>
#include<vector>
#include"Share_P1.h"

using namespace std;

const double dt = double(1) / 365;
//here we set the sample  time

const double MonteCarloSimulate_Path = 1000;
//here I define the const variable simulation_path is the monte carlo simulations times on share price
const double interest = 0.01;
const double DeltaCalculate_DifferentialSharePrice = 0.000001;
//this is the Central difference variable I used in monte carlo Delta Calculation, it means the share price path will shift this coefficient
//DeltaCalculate_DifferentialSharePrice*Share_Price .for example the share price 50 will get 2 new starting share 50.0005 and 49.9995
//if the orignal share price is bigger, you can change it into a smaller number

class Option {
public:
	~Option() {};
	Option( Share& s0, const double& strike0, const double& expiry);
	//the share class will be cast to the base class option by reference to calculate the price and delta.I store the simulation stock path result in share class
	//here the Share reference is not a const reference,because when we meet a longer expiry time such 10 years,we can use the reference to add more steps further.
	//which means the Share simulation steps can be infinte  that is similiar to the real world.
	virtual double PriceOptionAnalytical(void)=0 ;
	virtual double MonteCarloOption(void) = 0;
	virtual double MonteCarloDelta(void) = 0;
	double GetMonteCarloPrice() { return MonteCarloPrice; }
	double GetMonteCarloDelta_Result() { return MonteCarloDelta_Result; }
	vector<double>& GetSimulation_Result() { return Simulation_Result; }
protected:
	//the base member is defined as protected to be inherited ,any sub-class  will have these variables 
	Share& underlying_share;
	//in this base class,the reference will help us to use the data in share class
	double strike_price;
	double T;// the expiry year
	int path_number;// how many paths the share simulated
	int sample_number;//the expiry year*365
	double discount_fac;//the discount factor
	double MonteCarloPrice;
	double MonteCarloDelta_Result;
	vector<double>Simulation_Result;
	//this vector is used for the store the option price in every path for further output into a text 
};

