//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem1
//	Filename:	other_function_P1.cpp
//	Version:	v1 (20 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	the defination of other functions
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


#include"other_function_P1.h"
#include<iostream>
using namespace std;


double cdf(double x) {
// get the cdf of  normoal distribution  and return the probality of x
return (0.5*erfc(-x / sqrt(double(2))));
}

double PricePortfoiloOfOptions(const vector <Option*>& set, const vector<int>& call_num) {
	{
		double result = 0;
		if (set.size() != call_num.size()) {
			//check the size of the two vectors are same
			cout << "the number of calls must be the same with the call's kind" << endl;
			return 0;
		}
		else {
			for (int i = 0; i < int(set.size()); i++) {
				//using for loop to calcualte the result
				result = result + set[i]->GetMonteCarloPrice()*call_num[i];
			}
			return result;
		}
	}

}
double CalculatePortfoiloDeltaRisk(const vector <Option*>& set, const vector<int>& call_num, const vector<unsigned int>& shareID) {
	double result = 0;
	if (set.size() != call_num.size()) {
		cout << "the number of calls must be the same with the call's kind" << endl;
		return 0;
	}
	else {
		for (int i = 0; i <int( set.size()); i++) {
			//using loop to calcualte the result,the delta result has been stored in the class,here just use GetMonteCarloDelta_Result()
			result = result + set[i]->GetMonteCarloDelta_Result()*call_num[i]* shareID[i];
		}
		return result;
	}




}


