#pragma once
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem1
//	Filename:	Share_P1.h
//	Version:	v1 (29 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	the share class will simulate the set number of stock price paths and store the result.the result will be used in next steps to 
//calculate the price and delta.here we store the simulate results to avoid simulating the process for every option. If the expiry year is long, 
//this way will save a lot of time

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXXXXXXXXXXXXXX
#include"Monte_Carlo_P1.h"
using namespace std;
class Share {
public:
	~Share() {};
	Share(double p0, double vol0);
	Share(const Share& source);//here is a copy constructor which will be used in delta calculation
	double GetSharePrice() { return Price; }
	double GetShareVolatility() { return Volatility; }
	vector <vector<double>>& GetSharePath() { return Path; }
	//return the reference of the Path
private:
	double Price;
	double Volatility;
	vector <vector<double>> Path = {};
	//this vector is used to save the simulated result for stock price.and its referencer will be transfered to 
};

