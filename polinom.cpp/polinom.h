#ifndef _POLINOM_H_
#define _POLINOM_H_
#include "mlist.h"
#include <string>
using namespace std;

class Polinom
{
public:
	Polinom();
	Polinom(Mlist* ml);
	Polinom& operator+=(const Polinom& p);
	Polinom& operator-=(const Polinom& p);
	Polinom& operator*(const Polinom& p);
	void show();

private:
	Mlist* mList;
};
#endif _POLINOM_H_