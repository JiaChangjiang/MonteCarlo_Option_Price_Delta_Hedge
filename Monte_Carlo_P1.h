#pragma once

#include<cmath>
#include<random>
#include<vector>
using namespace std;
extern double initial_simulate_year;
//here we set the initial simulate year, but for share ,the expiry is infinite,so in the Base class Option constructor, I will use judge sentence to 
//decide whether simulate more years,initial the value in the monte_carlo_p1.cpp
void Monte_Carlo_Process(double s,double vol,vector<vector<double>>& overall_path);