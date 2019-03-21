//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	Project1
//	Filename:	main_P1.cpp
//	Version:	v2 (8 Mar 2019)
//	Author:		Changjiang Jia
//	Summary:	the main function of Project1 .Define all options and export 
//the result into txt,the const variable such as interest and simulation_path 
//is defined in the Option_P1.h
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include"European_Call_P1.h"
#include"EuropeanPut_P1.h"
#include"other_function_P1.h" 
#include"string"
#include"Monte_Carlo_P1.h"
#include"Share_P1.h"
#include"Option_P1.h"
#include"ArithmeticAsianOption_P1.h"
#include"BarrierOption_P1.h"
#include"BarrierOptionSubclass_P1.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include <iomanip>

using namespace std;

int main() {
	


	Share share1(50, 0.2);
	Share share2(40, 0.3);
	//create the two share class and simulate the paths at the same time,

	EuropeanCall Call1(share1, 50., 1.);

	UpAndInCallOption UpAndInCallOption1(share1, 50., 1., 70.);

	UpAndOutCallOption UpAndOutCallOption1(share1,50.,1.,70.);

	ArithmeticAsianCallOption AsianCall1(share1, 50., 1.);

	EuropeanCall Call2(share2, 35., 2.);

	EuropeanPut Put2(share2, 35., 2.);

	//
	EuropeanPut Put3(share2, 35., 2.);
	//
	UpAndInPutOption UpAndInPutOption1(share2, 35., 2., 55.);
	UpAndOutPutOption UpAndOutPutOption1(share2, 35., 2., 55.);
	DownAndInPutOption DownAndInPutOption1(share2, 35., 2., 30.);
	DownAndOutPutOption DownAndOutPutOption1(share2, 35., 2., 30.);
	ArithmeticAsianPutOption ArithmeticAsianPutOption1(share2, 35., 2.);
	

	//create the pointer to Polymorphism
	Option*opt1 = &Call1;
	Option(*opt2) =&UpAndInCallOption1;
	Option(*opt3) = &UpAndOutCallOption1;
	Option(*opt4) = &AsianCall1;
	Option(*opt5) = &Call2;
	Option(*opt6) = &Put2;
	Option(*opt7) = &Put3;
	Option(*opt8) = &UpAndInPutOption1;
	Option(*opt9) = &UpAndOutPutOption1;
	Option(*opt10) = &DownAndInPutOption1;
	Option(*opt11) = &DownAndOutPutOption1;
	Option(*opt12) = &ArithmeticAsianPutOption1;
	vector < Option* > pointer = { opt1,opt2,opt3,opt4,opt5,opt6,opt7,opt8,opt9,opt10,opt11,opt12 };
;
	vector<int> OptionNumber = { 3,2,1,12,5,3,7,3,1,3,1,12 };
	vector<unsigned int> shareID1 = { 1,1,1,1,0,0,0,0,0,0,0,0 };
	vector<unsigned int> shareID2 = { 0,0,0,0,1,1,1,1,1,1,1,1 };


	vector<string> OptionName = { "Call1","Up and In Barrier Call1","Up and Out Barrier Call1","Asian Call1","Call2","Put1","Put2",
		"Up and In Barrier Put1","Up and Out Barrier Put1","Down and In Barrier Put1","Down and Out Barrier Put1" ,"Asian Put1"};
	for (int i = 0; i < 12; i++) {

		cout << "for option " << OptionName[i] << endl;
		cout <<"the price of monte carlo method : " <<pointer[i]->MonteCarloOption() << endl;
		cout << "the monte carlo option on delta is : " << pointer[i]->MonteCarloDelta() << endl;
		if (pointer[i]->PriceOptionAnalytical() != -1) {
			//for asian option,there is no analytical price,we return price is -1 to escape the analytical price and error calculation
			cout << "the analytic option price is : " << pointer[i]->PriceOptionAnalytical() << endl;
			cout << "the error is : " << abs(pointer[i]->MonteCarloOption() - pointer[i]->PriceOptionAnalytical()) << endl;
		}
		else {
			cout << "there is no analytical price for this option"<<endl;
		}
		
		
		cout << endl;
		
	}
	cout << endl;
	cout << "Price Portfoilo Of Options is:  " << PricePortfoiloOfOptions(pointer, OptionNumber)<<endl;
	cout << "Delta Of Options based on share1 is:  " << CalculatePortfoiloDeltaRisk(pointer, OptionNumber, shareID1) << endl;;
	
	cout << "Delta Of Options based on share1 is:  " << CalculatePortfoiloDeltaRisk(pointer, OptionNumber, shareID2) << endl;;
	cout << "the hedge of delta, the need number of share1 is  " << -CalculatePortfoiloDeltaRisk(pointer, OptionNumber, shareID1) << endl;
	cout << "the hedge of delta, the need number of share2 is  " << -CalculatePortfoiloDeltaRisk(pointer, OptionNumber, shareID2) << endl;
	cout << "after hedging the delta of the portfolio, the portfolio is  ";
	cout << PricePortfoiloOfOptions(pointer, OptionNumber) + (-CalculatePortfoiloDeltaRisk(pointer, OptionNumber, shareID1)*share1.GetSharePrice()) + ((-CalculatePortfoiloDeltaRisk(pointer, OptionNumber, shareID2))*share2.GetSharePrice());
	cout << endl;


	/*
	char str[200] = "C:\\Users\\CXJ885\\Desktop\\10000\\%d.txt";
	for (int i = 0; i < 12; i++) {
		sprintf_s(str, "C:\\Users\\CXJ885\\Desktop\\10000\\%d.txt",i+1);
		ofstream out(str);
		out.close();
		ofstream outfile(str, ios::in | ios::out | ios::binary);
		outfile << std::setprecision(10);
		//set the precision of the output,
		{
			for (int j = 0;j <int(pointer[i]->GetSimulation_Result().size());j++)
			{
				outfile << pointer[i]->GetSimulation_Result()[j] << " ";
			}
			outfile << "\r\n";//after write  b1 give a endl
		}
		outfile.close();

	}

	*/
 	return 0;

}
