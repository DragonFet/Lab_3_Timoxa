
#include <iostream>
#include <string>
#include "man.h"
#include "student.h"
#include <set>
#include <fstream>
#include <sstream>
using namespace std;
string path = "data.txt";
int count_line = 0;
int N = 0;
void save(student* data, int N)
{
	fstream datainput;
	datainput.open(path, ios::out);
	for (int i = 0; i < N; i++)
	{
		string name, surenamess,faculti;
		int number;
		name = data[i].RetName();
		surenamess = data[i].RetSur();
		faculti = data[i].ReturnFaculti();
		number = data[i].Returnnumber();
		datainput << name <<endl <<surenamess<<endl<<faculti<<endl<<number<<endl;
		cout << endl;
	}
	datainput.close();
}
void Value_N(int& N) {
	fstream read;
	read.open(path, ios::in);
	int count = 1;
	string per;
	while (read.peek() != EOF) {
		getline(read, per);
		++count;
		if (count % 4 == 0)
		{
			++N;
		}
	}
	count_line = count;
}
int string_to_int(string str)
{
	int result;
	istringstream iss(str, istringstream::in);
	iss >> result;
	return result;
}
double string_to_double(string str)
{
	double result;
	istringstream iss(str, istringstream::in);
	iss >> result;
	return result;
}
void load_from_file(student*data)
{
	int index = 0;
	fstream datainput;
	datainput.open(path, ios::in);
	for (int j = 0; j < count_line - 1;)
	{
		j = j + 4;
		for (int i = 0; i < 4; i++)
		{
			switch (i)
			{
			case 0:
			{
				string line;
				getline(datainput, line);
				data[index].InputName(line);
				break;
			}
			case 1:
			{
				string line;
				getline(datainput, line);
				data[index].InputSurename(line);
				break;
			}
			case 2:
			{
				string line;
				getline(datainput, line);
				data[index].input_Faculti(line);
				break;
			}
			case 3:
			{
				string line;
				getline(datainput, line);
				int c = string_to_int(line);
				data[index].inputnumber(c);
				break;
			}
			

			}
		}
		index++;
	}
	datainput.close();
}
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

int main()
{
	Value_N(N);
	student* data = new student[10000];
	load_from_file(data);
	int solution = 99;
	while (solution!=5)
	{
		data->Menu();
		cout << "Input";
		solution = getValue();
		switch (solution)
		{
			case 1:
			{
				data->add(data[N], N);
				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				data->Output_all(data, N);
				system("pause");
				system("cls");
				break;
			}
			case 3:
			{
				Find_Faculti(data, N);
				system("pause");
				system("cls");
				break;
			}
			case 4:
			{
				Sorty_with_number(data, N);
				system("pause");
				system("cls");
				break;
			}
			case 5:
			{
				int a = 0;
				cout << "Exit" << endl;
				for (size_t i = 0; i < 1000000000; i++)
				{
					if (a==10000000)
					{
						cout << ".";
						a = 0;
					}
					a++;
				}
				save(data, N);
				cout << "Complete" << endl;
				return 0;
			}
		}
	}

}