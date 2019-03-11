#include <iostream>
#include <string>
#include "transform.h"
#include "polinom.h"
int main()
{
	/*Mlist k;
	k.insertf(2.0,20);
	k.insertf(3,21);
	k.insertf(4,21);
	cout<<k[0];*/

	std::string firstPolinom;
	std::string secondPolinom;

	std::cin >> firstPolinom;
	std::cin >> secondPolinom;

	Pars pars1(firstPolinom);
	Pars pars2(secondPolinom);
	Polinom* p1 = pars1.getPolinom();
	Polinom* p2 = pars2.getPolinom();
	std::cout << "\np1:\n";
	p1->show();
	std::cout << "\np2:\n";
	p2->show();
	
	(*p1)+=(*p2);
	std::cout << "\nresult\n";
	p1->show();
	//std::cout<< "\n"<<endl;
	/*p1->print(*p1);*/
	
	
	return 0;
}