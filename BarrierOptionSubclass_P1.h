//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem1
//	Filename:	BarrierOptionSubclass.h
//	Version:	v1 (29 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	declare the sub class BarrierOption the whole file is used to define the specific barrier option
//all option has similar structure.
//1.the constructor of the option 
//2.GetSubClassInorOut if the option is knock-in option return 1,out return 0  
//3 GetSubClassCallorPut  if the option is Call option return 1,put return 0
//4 GetSubClassUporDown if the option is Up option return 1,Down return0
//because these sub-class is simple, I declare and define in the header file
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#include"BarrierOption_P1.h"


//define in and out
class BarrierUpandInOption :public BarrierUpOption {
public:
	BarrierUpandInOption::BarrierUpandInOption(Share & Option_underlying0, double Option_strike0, double  Option_expiry0, double Barrier0)
		:BarrierUpOption(Option_underlying0, Option_strike0, Option_expiry0, Barrier0) {}
	~BarrierUpandInOption() {}
	int GetSubClassInorOut() {
		return 1;
	}


};

class BarrierUpandOutOption :public BarrierUpOption {
public:
	BarrierUpandOutOption::BarrierUpandOutOption(Share & Option_underlying0, double Option_strike0, double  Option_expiry0, double Barrier0)
		:BarrierUpOption(Option_underlying0, Option_strike0, Option_expiry0, Barrier0) {}
	~BarrierUpandOutOption() {}
	int GetSubClassInorOut() {
		return 0;
	}
};

class BarrierDownandInOption :public BarrierDownOption {
public:
	BarrierDownandInOption::BarrierDownandInOption(Share & Option_underlying0, double Option_strike0, double  Option_expiry0, double Barrier0)
		:BarrierDownOption(Option_underlying0, Option_strike0, Option_expiry0, Barrier0) {}
	~BarrierDownandInOption() {}
	int GetSubClassInorOut() {
		return 1;
	}
};

class BarrierDownandOutOption :public BarrierDownOption {
public:
	BarrierDownandOutOption::BarrierDownandOutOption(Share & Option_underlying0, double Option_strike0, double  Option_expiry0, double Barrier0)
		:BarrierDownOption(Option_underlying0, Option_strike0, Option_expiry0, Barrier0) {}
	~BarrierDownandOutOption() {}
	int GetSubClassInorOut() {
		return 0;
	}
};


//define In
class UpAndInCallOption : public BarrierUpandInOption {
public:
	UpAndInCallOption::UpAndInCallOption(Share & Option_underlying0, double Option_strike0, double  Option_expiry0, double Barrier0)
		:BarrierUpandInOption(Option_underlying0, Option_strike0, Option_expiry0, Barrier0) {}
	~UpAndInCallOption() {}
	int GetSubClassCallorPut() {
		return 1;
	}



};

class UpAndInPutOption : public BarrierUpandInOption {
public:
	UpAndInPutOption::UpAndInPutOption(Share & Option_underlying0, double Option_strike0, double  Option_expiry0, double Barrier0)
		:BarrierUpandInOption(Option_underlying0, Option_strike0, Option_expiry0, Barrier0) {}
	~UpAndInPutOption(){}
	int GetSubClassCallorPut() {
		return 0;
	}


};

class DownAndInCallOption : public BarrierDownandInOption {
public:
	DownAndInCallOption::DownAndInCallOption(Share & Option_underlying0, double Option_strike0, double  Option_expiry0, double Barrier0)
		:BarrierDownandInOption(Option_underlying0, Option_strike0, Option_expiry0, Barrier0) {}
	~DownAndInCallOption(){}
	int GetSubClassCallorPut() {
		return 1;
	}





};
class DownAndInPutOption : public BarrierDownandInOption {
public:
	DownAndInPutOption::DownAndInPutOption(Share & Option_underlying0, double Option_strike0, double  Option_expiry0, double Barrier0)
		:BarrierDownandInOption(Option_underlying0, Option_strike0, Option_expiry0, Barrier0) {}
	~DownAndInPutOption() {}
	int GetSubClassCallorPut() {
		return 0;
	}

};
//define Out
class UpAndOutCallOption : public BarrierUpandOutOption {
public:
	UpAndOutCallOption::UpAndOutCallOption(Share & Option_underlying0, double Option_strike0, double  Option_expiry0, double Barrier0)
		:BarrierUpandOutOption(Option_underlying0, Option_strike0, Option_expiry0, Barrier0) {}
	~UpAndOutCallOption() {}
	int GetSubClassCallorPut() {
		return 1;
	}


};

class UpAndOutPutOption : public BarrierUpandOutOption {
public:
	UpAndOutPutOption::UpAndOutPutOption(Share & Option_underlying0, double Option_strike0, double  Option_expiry0, double Barrier0)
		:BarrierUpandOutOption(Option_underlying0, Option_strike0, Option_expiry0, Barrier0) {}
	~UpAndOutPutOption() {}
	int GetSubClassCallorPut() {
		return 0;
	}

};

class DownAndOutCallOption : public BarrierDownandOutOption {
public:
	DownAndOutCallOption::DownAndOutCallOption(Share & Option_underlying0, double Option_strike0, double  Option_expiry0, double Barrier0)
		:BarrierDownandOutOption(Option_underlying0, Option_strike0, Option_expiry0, Barrier0) {}
	~DownAndOutCallOption() {}
	int GetSubClassCallorPut() {
		return 1;
	}



};

class DownAndOutPutOption : public BarrierDownandOutOption {
public:
	DownAndOutPutOption::DownAndOutPutOption(Share & Option_underlying0, double Option_strike0, double  Option_expiry0, double Barrier0)
		:BarrierDownandOutOption(Option_underlying0, Option_strike0, Option_expiry0, Barrier0) {}
	~DownAndOutPutOption() { }
	int GetSubClassCallorPut() {
		return 0;
	}

};