#include"Share_P1.h"
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	Project1
//	Filename:	Share_P1.cpp
//	Version:	v2 (8 Mar 2019)
//	Author:		Changjiang Jia
//	Summary:	the share class copy constructor
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

Share::Share(const Share& source)
{
	this->Price = source.Price;
	this->Volatility = source.Volatility;
	this->Path = source.Path;
}

Share::Share(double p0, double vol0) :Price(p0), Volatility(vol0) {
	Monte_Carlo_Process(p0, vol0, Path);

};