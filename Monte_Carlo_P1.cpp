//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	Project1
//	Filename:	Share_P1.cpp
//	Version:	v2 (8 Mar 2019)
//	Author:		Changjiang Jia
//	Summary:	the monte carlo method to simulate stock price path,here I set the initial_simulate_year=1
//if the option have a longer expiry, the path can be expanded .
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include"Monte_Carlo_P1.h"
#include"Option_P1.h"
using namespace std;

double initial_simulate_year = 1;

//here we set the initial simulate year, but for share ,the expiry is infinite,so in the Base class Option constructor, I will use judge sentence to 
//decide whether simulate more years,initial the value in the monte_carlo process
void Monte_Carlo_Process(double s, double vol, vector<vector<double>>&overall_path) {
	
	double temp_s = s;
	std::random_device random_dev;
	std::mt19937 random_gen(random_dev());
	std::normal_distribution<double> normal_dist(0, 1);

	for (int i = 0; i < MonteCarloSimulate_Path; i++) {
		vector<double> path = {};
		for (int j = 0; j <= 1 + 365 * initial_simulate_year; j++) {
			path.push_back(s);
			s = s*exp((interest - 0.5*vol*vol)*dt + vol*sqrt(dt)*normal_dist(random_dev));
			//s = s + s*interest*dt + s*vol*sqrt(dt)*normal_dist(random_dev);
			//the  PDe formula should not be used here
		}
		overall_path.push_back(path);
		s = temp_s;
	}



}
