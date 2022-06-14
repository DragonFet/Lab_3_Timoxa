#pragma once
#include <iostream>
#include <string>
#include "man.h"
#include <utility>
using namespace std;
class student
{
public:
	student()
	{
		number = 0;
	}
#pragma region Basic
	int getValue()
	{
		while (true)
		{
			cout << "Please input VALLUE";
			cout << '\n';
			int a;
			cin >> a;
			cout << '\n';

			if (cin.fail())
			{
				cin.clear(); // 
				cin.ignore(32767, '\n');
			}
			else return a;

		}

	}
	double getValueD()
	{
		while (true)
		{
			cout << "Please input VALLUE";
			cout << '\n';
			double a;
			cin >> a;
			cout << '\n';

			if (cin.fail())
			{
				cin.clear(); // 
				cin.ignore(32767, '\n');
			}
			else return a;

		}

	}
	static int count;
	void Menu()
	{
		cout << "1-Add new student in base" << endl;
		cout << "2- Output all student " << endl;
		cout << "3-Find with faculti" << endl;
		cout << "4-Sorty with group" << endl;
		cout << "5- Exit from program" << endl;

	}
	void set_faculti()
	{
		string tmp;
		cout << "Input faculti " << endl;
		cin >> tmp;
		faculti = tmp;
	}
	void set_number()
	{
		int tmp = getValue();
		number = tmp;
	}
	string ReturnFaculti()
	{
		return faculti;
	}
	int Returnnumber()
	{
		return number;
	}
	void inputnumber(int numbers)
	{
		number = numbers;
	}
	void input_Faculti(string tmp)
	{
		faculti = tmp;
	}
	string RetName()
	{
		return person.ReturnName();
	}
	string RetSur()
	{
		return person.ReturnSurename();
	}
	void InputName(string Na)
	{
		person.inputname(Na);
	}
	void InputSurename(string SR)
	{
		person.input_surename(SR);
	}
	void add(student& date, int& N)
	{
		date.person.set_Name();
		date.person.set_surename();
		date.set_faculti();
		date.set_number();
		N++;
	}
	void Output_all(student* date, int N)
	{
		for (size_t i = 0; i < N; i++)
		{
			cout << "Name" << " " << date[i].RetName() << endl;
			cout << "Surename" << " " << date[i].RetSur() << endl;
			cout << "Faculti" << " " << date[i].ReturnFaculti() << endl;
			cout << "Number" << " " << date[i].Returnnumber() << endl;
			cout << endl;

		}
	}
#pragma endregion
#pragma region Multi
	friend void Find_Faculti(student* date, int N);
	friend void Sorty_with_number(student* date, int N);
#pragma endregion
	friend void save(student* data, int N);
	
	friend ostream& operator<<(ostream& os, const student& dt);
private:
	man person;
	string faculti;
	int number;
	
};

bool operator==(const man& lh, const student& rh);