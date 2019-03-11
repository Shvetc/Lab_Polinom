#include "transform.h"
#include <math.h>
void Pars::pars()
{
	int power = 0;
	int tempPower = 0;
	
	double coeff = 0;
	int i = 0;
	int size = sourceString.size();
	std::string sCoeffOrPower = "";
	char s = 0;
	bool isPower = false;
	int x_y_z = 0;
	while(i < size)
	{
		s = sourceString[i];
		//std::cout << sourceString[i];
		if(( s == '+' || s == '-'))
		{
			if(i != 0)
			{
				if(isPower)
				{
					tempPower = std::atof(sCoeffOrPower.c_str());
					power += pow(20, double(x_y_z)) * tempPower;
					sCoeffOrPower = "";
					std::cout << "power:" << power << "\n";
				}
				isPower = false;
				mList->insertf(coeff,power);
			}
			sCoeffOrPower = s;
			coeff = 0;
			power = 0;
			isPower = false;
		}

		if(((s != 'x' && s != 'y' && s != 'z' && s != '^') && (s >= '0' && s <= '9')) || s == '.' )
		{
			sCoeffOrPower += s;
		}
		if(s == 'x' || s == 'y' || s == 'z')
		{
			if(isPower)
			{
				isPower = false;
				tempPower = std::atof(sCoeffOrPower.c_str());
				power += pow(20, double(x_y_z)) * tempPower;
				sCoeffOrPower = "";
				std::cout << "power:" << power << "\n";
				//mList->insertf(coeff,power);
			}
			else
			{
				coeff = std::atof(sCoeffOrPower.c_str());
				std::cout << "coeff:" << coeff << "\n";
				sCoeffOrPower = "";
			}
		}
		if(s == '^')
		{
			sCoeffOrPower = "";
			isPower = true;
			if(sourceString[i-1] == 'x')
				x_y_z = 2;
			if(sourceString[i-1] == 'y')
				x_y_z = 1;
			if(sourceString[i-1] == 'z')
				x_y_z = 0;	
		}
		i++;
	}
	if(sCoeffOrPower != "")
	{
		isPower = false;
		tempPower = std::atof(sCoeffOrPower.c_str());
		power += pow(20, double(x_y_z)) * tempPower;
		sCoeffOrPower = "";
		std::cout << "power:" << power << "\n";
		mList->insertf(coeff,power);
	}
	//mList->show();
}
