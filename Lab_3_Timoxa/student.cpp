#pragma once
#include <iostream>
#include <string>
#include "man.h"
#include "student.h"
#include <set>
#include <fstream>
#include <sstream>q
using namespace std;

void Find_Faculti(student* date, int N)
{
	string tmp;
	cout << "Input faculti" << endl;
	cin >> tmp;
	for (size_t i = 0; i < N; i++)
	{
		if (date[i].ReturnFaculti()==tmp)
		{
			cout << "Name" << " " << date[i].RetName() << endl;
			cout << "Surename" << " " << date[i].RetSur() << endl;
			cout << "Faculti" << " " << date[i].ReturnFaculti() << endl;
			cout << "Number" << " " << date[i].Returnnumber() << endl;
			cout << endl;
		}
	}
}

void Sorty_with_number(student* date, int N)
{
	set<int>numbers;
	for (size_t i = 0; i < N; i++)
	{
		numbers.insert(date[i].Returnnumber());
	}
	for (auto item:numbers)
	{
		for (size_t i = 0; i < N; i++)
		{
			if (item==date[i].Returnnumber())
			{
				cout << "Name" << " " << date[i].RetName() << endl;
				cout << "Surename" << " " << date[i].RetSur() << endl;
				cout << "Faculti" << " " << date[i].ReturnFaculti() << endl;
				cout << "Number" << " " << date[i].Returnnumber() << endl;
				cout << endl;
			}
		}
	}
}

std::ostream& operator<<(std::ostream& strm, student& data)
{
	strm << data.RetName() << " " << data.RetSur() << " " << data.ReturnFaculti()<< " "<<data.Returnnumber();
	return strm;
}