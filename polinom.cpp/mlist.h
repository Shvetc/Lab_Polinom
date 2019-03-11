#ifndef _MLIST_H_
#define _MLIST_H_
#include "polinom.h"
#include<iostream>
using namespace std;

struct Mlink
{
	double value;
	int ind;
	Mlink *n;
	int powers(int&x, int&y,int&z)
	{
		int _ind = ind;
		z = _ind % 20;
		_ind = _ind / 20;
		y = _ind % 20;
		x = _ind / 20;
		//x = ind / 20;
		return (_ind % 20);
	
    }
};

class Mlist
{
	friend class Polinom;
	Mlink *h;
public:
	Mlist()
	{
		h = nullptr;
	}
	Mlist( const Mlist &b)
	{
		if (b.h == nullptr)
		{
			throw -1;
		}
		Mlink *k;
		k = b.h;
		while ( k != nullptr )
		{
			this ->insertf(k->value,k->ind);
			k = k->n;
		}
	}
	~Mlist()
	{
		while (h != nullptr )
		{
			deletef();
		}
	}
	void insertf( double value, int ind)
	{
		Mlink *k;
		k = new Mlink;
		k->value = value;
		k->ind = ind;
		k->n = h;
		h = k;
	}

	void show()
	{
		Mlink *k;
		k = h;
		int x,y,z;
		char c = '+';
		while (k != nullptr)
		{
			if(k->value == 0)
			{
				k = k->n;
				continue;
			}
			//std::cout << "\nind:" << k->ind <<"\n";
			k->powers(x,y,z);
			c = (k->value > 0) ? '+' : '-';
			cout << c << k->value <<"x^"<<x<<"y^"<<y<<"z^"<<z;
			k = k->n;
		}
		cout << "\n";
	}
	
	void deletef()
	{
		if (h == nullptr)
		{
			return ;
		}
		Mlink *k;
		k = h;
		h = h->n;
		delete k;
	}

	void insertl(double value, int ind)
	{
		Mlink *k = new Mlink;
		k->value = value;
		k->ind = ind;
		k->n = nullptr;
		Mlink *t;
		if ( h == nullptr)
		{
			h = k;
		}
		t = h;
		while ( t ->n != nullptr)
		{
			t = t->n;
		}
		t->n = k;
	}
	void deletl()
	{
		if ( h == nullptr)
		{
			return;
		}
		if (h ->n == nullptr)
		{
			delete h;
			return ;
		}
		Mlink*k;
		k = h;
		while (k->n->n == nullptr)
		{
			k = k->n;
		}
		delete k->n;
		k->n = nullptr;
	}

	double &operator[] (int index)
	{
		if (index < 0)
		{
			throw -1;
		}
		Mlink *k;
		k = h;
		int i = 0;
		while (k != nullptr && i <index)
		{
			k = k->n;
			i++;
		}
		if ( k == nullptr)
		{
			throw -1;
		}

		else
			 
		return k->value;
	}

	int getindex (Mlink &k)
	{
		return k.ind;
	}
	int getcoeff(Mlink &k)
	{
		return k.value;
	}
};

#endif _MLIST_H_