#include<string>
#include <iostream>
#include "polinom.h"
using namespace std;
class Pars
{
public:
	Pars(string& s)
	{	
		sourceString = s;
		mList = new Mlist;
	
		//std::cout << sourceString;
	}
	Polinom* getPolinom()
	{
		pars();
		polinom = new Polinom(mList);
		return polinom;
	}
	
private:
	string sourceString;
	Polinom* polinom;
	Mlist* mList;
	void pars();
};