//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	Project1
//	Filename:	Option_P1.cpp
//	Version:	v2 (8 Mar 2019)
//	Author:		Changjiang Jia
//	Summary:	the base class of the whole project
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


#include"Option_P1.h"	
#include<iostream>
using namespace std;


Option::Option(Share& s0, const double& strike0, const double& expiry) :underlying_share(s0), strike_price(strike0), T(expiry)
{
	path_number = underlying_share.GetSharePath().size();
	sample_number = int(365 * T);
	discount_fac = exp(-interest*T);
	if (T > initial_simulate_year) {
		//if T is greater than the initial simulate year, we need to simulate more years 
		double vol = underlying_share.GetShareVolatility();
		std::random_device random_dev;
		std::mt19937 random_gen(random_dev());
		std::normal_distribution<double> normal_dist(0, 1);
		vector <vector<double>>& overall_path = underlying_share.GetSharePath();

		for (int i = 0; i < MonteCarloSimulate_Path; i++) {
			double s = (overall_path[i]).back();//get the last value of former simulation result in path i
			for (int j = 0; j < 1 + 365 * (T-initial_simulate_year); j++) {
				//here we just simulate 365 * (T-initial_simulate_year) days more is ok
				s = s + s*interest*dt + s*vol*sqrt(dt)*normal_dist(random_dev);
				//use SDE formula to simulate the GBM process to avoid use exp() function which will cost more time
				(overall_path[i]).push_back(s);
			}
		
		}
		initial_simulate_year = T;

	}













}
