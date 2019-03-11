#include "polinom.h"
#include <iostream>
using namespace std;
Polinom::Polinom ()
{
	mList = nullptr;
}
Polinom::Polinom(Mlist* ml)
{
	mList = ml;
}
/*
Polinom& Polinom::operator+=(const Polinom& p)
{  Mlink* pMl = p.mList->h;
		Mlink* ml = mList->h;
		Mlink* ml_last;
		bool noPower = false;
		while(pMl != nullptr)
		{
			while(ml != nullptr)
			{
				if(pMl->ind == ml->ind)
				{
					ml->value += pMl->value;
					noPower = false;
					break;
				}
				else
				{
					noPower = true;
				}
				ml_last = ml;
				ml = ml->n;
			}
			if(noPower)
			{
				ml_last->n = new Mlink;
				ml_last->n->ind = pMl->ind;
				ml_last->n->value = pMl->value;/* priority */
/*				ml_last->n->n = nullptr;
			}
			pMl = pMl->n;
			ml = mList->h;
		}
		return *this;
}
*/
Polinom& Polinom::operator+=(const Polinom& p)
{  
		Mlink* pMl = p.mList->h;
		Mlink* ml = mList->h;
		Mlink* ml_before = ml;
		bool noPower = false;
		while((pMl != nullptr) && (ml != nullptr))
		{
			if((pMl->ind) > (ml->ind))
			{
				if((ml == ml_before) && (ml == mList->h))
				{
					mList->h = new Mlink;
					ml_before = mList->h; 
					ml_before->ind = pMl->ind;
					ml_before->value = pMl->value;
					ml_before->n = ml;
					pMl = pMl->n;
				}
				else
				{
					ml_before->n = new Mlink;
					ml_before->n->ind = pMl->ind;
					ml_before->n->value = pMl->value;
					ml_before->n->n = ml;
					ml_before = ml_before->n;
					pMl = pMl->n;
				}
				continue;
			}
			if((pMl->ind) < (ml->ind))
			{
				ml_before = ml;
				ml = ml->n;
				continue;
			}
			if((pMl->ind) == (ml->ind))
			{
				//std::cout << "\n___ind: " << ml->ind << "\n";
				//std::cout << "\n___pind: " << pMl->ind << "\n";

				ml->value += pMl->value;
				pMl = pMl->n;
				ml_before = ml;
				ml = ml->n;
				continue;
			}
		}
		if((pMl != nullptr) && (ml == nullptr))
		{
			while(pMl != nullptr)
			{
				ml_before->n = new Mlink;
				ml_before->n->ind = pMl->ind;
				ml_before->n->value = pMl->value;
				ml_before->n->n = nullptr;
				ml_before = ml_before->n;
				pMl = pMl->n;
			}
		}

		return *this;
}
Polinom& Polinom::operator-=(const Polinom& p)
{
	Mlink* pMl = p.mList->h;
	Mlink* ml = mList->h;
	Mlink* ml_before = ml;
	bool noPower = false;
	while((pMl != nullptr) && (ml != nullptr))
	{
		if((pMl->ind) > (ml->ind))
		{
			if((ml == ml_before) && (ml == mList->h))
			{
				mList->h = new Mlink;
				ml_before = mList->h; 
				ml_before->ind = pMl->ind;
				ml_before->value = pMl->value;
				ml_before->n = ml;
				pMl = pMl->n;
			}
			else
			{
				ml_before->n = new Mlink;
				ml_before->n->ind = pMl->ind;
				ml_before->n->value = pMl->value;
				ml_before->n->n = ml;
				ml_before = ml_before->n;
				pMl = pMl->n;
			}
			continue;
		}
		if((pMl->ind) < (ml->ind))
		{
			ml_before = ml;
			ml = ml->n;
			continue;
		}
		if((pMl->ind) == (ml->ind))
		{
			ml->value -= pMl->value;
			pMl = pMl->n;
			ml_before = ml;
			ml = ml->n;
			continue;
		}
	}

	if((pMl != nullptr) && (ml == nullptr))
	{
		while(pMl != nullptr)
		{
			ml_before->n = new Mlink;
			ml_before->n->ind = pMl->ind;
			ml_before->n->value = pMl->value;
			ml_before->n->n = nullptr;
			ml_before = ml_before->n;
			pMl = pMl->n;
		}
	}
	return *this;
}
Polinom& Polinom:: operator*(const Polinom& p)
{
	Mlink* pMl = p.mList->h;
	Mlink* ml = mList ->h;
	Mlink* ml_current;
	while ((pMl != nullptr) && (ml !=nullptr))
	{
		while ((pMl != nullptr) && (ml !=nullptr))
		{
		ml->value = ml->value *  pMl->value;
		ml->ind += pMl->ind;
		pMl = pMl->n;
		}
		ml = ml->n;
	}
	while ((pMl != nullptr) && (ml == nullptr))
	{
		ml_current->n = new Mlink;
		ml_current->n->ind = pMl->ind;
		ml_current->n->value = pMl->value;
		ml_current->n->n = nullptr;
		ml_current = ml_current->n;
		pMl = pMl->n;
	}
	return *this;
}
void Polinom::show()
{
	mList->show();
	/*devision by 20*/
}
