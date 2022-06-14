#pragma once
#include <iostream>
#include <string>


using namespace std;

class man
{
public:
#pragma region SetReturn
	void set_Name()
	{
		cout << "Input name " << endl;
		string tmp;
		cin >> tmp;
		this->name = tmp;

	}
	void set_surename()
	{
		cout << "Input surename" << endl;
		string tmp;
		cin >> tmp;
		this->surename = tmp;
	}
	string ReturnName()
	{
		return name;
	}
	string ReturnSurename()
	{
		return surename;
	}
	void inputname(string tmp)
	{
		this->name = tmp;
	}
	void input_surename(string tmp)
	{
		this->surename = tmp;
	}
#pragma endregion
private:
	string name;
	string surename;
};

