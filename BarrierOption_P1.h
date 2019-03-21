#pragma once

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem1
//	Filename:	BarrierOptionSubclass.h
//	Version:	v1 (29 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	declare the base class BarrierOption the whole file is used to 
//define the base barrier option and some function will be used to calculate the monte carlo price and delta
//I write all calculate funtion in the base class to avoid to write a lot of similar sentences in the sub-class,which is  not efficient and
// not easy to manage and change
//but the different option has different calculation rule so I use 
//2.GetSubClassInorOut if the option is knock-in option return 1,out return 0  
//3 GetSubClassCallorPut  if the option is Call option return 1,put return 0
//4 GetSubClassUporDown if the option is Up option return 1,Down return0
// to identify the specific sub-class

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX



#include"Option_P1.h"
#include"other_function_P1.h"

void GetDifferentBarrierOptionDelta(Share& NewShare0, Share& NewShare1, const int& bool_value, double& DeltaResult, const double& strike_price, const double& Barrier_Price, const double& T, const double& dPrice);
//this function is used to calculate the delta and generte two new share to calculate
double CalculateDelta(Option& NewOption0, Option& NewOption1, double dPrice);
//this function will use the base class Option Polymorphism to calculate the price
class BarrierOption :public Option {
public:
	 ~BarrierOption() {};
	
	double PriceOptionAnalytical(void);
	virtual int GetSubClassUporDown() = 0;//if 1 if is up
	virtual int GetSubClassInorOut() = 0;//return 1 if is in
	virtual int GetSubClassCallorPut() = 0;//return 1 if call
	BarrierOption::BarrierOption(Share & Option_underlying0, double  Option_strike0, double Option_expiry0, double Barrier0);
	double MonteCarloDelta();
	double MonteCarloOption(void);

protected:
	double Barrier_Price;
	vector<int> FeasiablePath = {};
	//the vector is used to save the feasiable paths,for one path if the option can be exercised at the expiry day,push back 1 in the vector
	//if the option can not be exercised,push back 0 in the vector,according to different type option up and down,the vector is defined here
	//and initial it in the subclass BarrierUpOption and  subclass BarrierDownOption's contructors
	//the feasiable path judge whether the path over the barrier
	//for in option the feasiable path means the option can be exercised
	//for out option the feasiable path means the option can not be exercised

};

//define up and dowm
class BarrierUpOption :public BarrierOption {
public:
	BarrierUpOption::BarrierUpOption(Share & Option_underlying0, double  Option_strike0, double Option_expiry0, double Barrier0);
	~BarrierUpOption() {}
	int GetSubClassUporDown() { return 1; }

};

class BarrierDownOption :public BarrierOption {
public:
	BarrierDownOption::BarrierDownOption(Share & Option_underlying0, double  Option_strike0, double Option_expiry0, double Barrier0);
	~BarrierDownOption() {}
	int GetSubClassUporDown() { return 0; }
};




















