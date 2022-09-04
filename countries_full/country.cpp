#include "country.h"

#include <string>
#include <iostream>

//#define DEBUG

using namespace std;

//перегрузка конструктора для инициализации всех параметров:
country::country(const string& name, const string& capital, const int population, const vector<string> politics)
{
#ifdef DEBUG
	cout << "Вызвался конструктор" << endl;
#endif // DEBUG


	counter++;
	id = counter;

	this->name = name;
	this->capital = capital;
	this->population = population;
	
	for (int i = 0; i < 3; i++) this->politics.push_back(politics[i]);
}

//перегрузка конструктора без инициализации параметров:
country::country()
{
	counter++;
	id = counter;

	population = 0;
}

//геттеры и сеттеры для обычных свойств
string& country::Get_Name()
{
	return name;
}

void country::Set_Name(const string& name)
{
	this->name = name;
}

string& country::Get_Capital()
{
	return capital;
}

void country::Set_Capital(const string& capital)
{
	this->capital = capital;
}

long country::Get_Population()
{
	return population;
}

void country::Set_Population(const int population)
{
	this->population = population;
}

vector<string> country::Get_Politics()
{
	return politics;
}

void country::Set_Politics(vector<string> arr)
{
	for (int i = 0; i < 3; i++) politics[i] = arr[i];
}

void country::Set_All(const string& name, const string& capital, const int population, const vector<string> politics)
{
	this->name = name;
	this->capital = capital;
	this->population = population;

	for (int i = 0; i < 3; i++) this->politics.push_back(politics[i]);
}

//метод вывода свойств в консоль:
void country::Print()
{
	cout << "**************************************************************************************" << endl;
	cout << "Порядковый номер в базе данных: " << id << endl << endl;
	cout << "Название страны: " << name << "\t\t" << "Столица: " << capital << endl;
	cout << "Численность населения: " << population << " млн. человек" << endl;
	cout << "Государственный строй:" << endl;
	cout << " -> Форма правления - " << politics[0] << endl;
	cout << " -> Административно-территориальное устройство - " << politics[1] << endl;
	cout << " -> Политический режим - " << politics[2] << endl;
	cout << "**************************************************************************************" << endl << endl;
}

//методы управления статическими и идентификационными свойствами:
int country::GetId()
{
	return id;
}

void country::DecreaseId()
{
	id--;
}

int country::GetCount()
{
	return counter;
}

void country::IncreaseCount()
{
	counter++;
}

void country::DecreaseCount()
{
	counter--;
}

void country::ResetCount()
{
	counter = 0;
}

//тест деструктора для изменения static counter при удалении стран из БД
#ifdef DEBUG
country::~country()
{
	cout << "Вызвался деструктор" << endl;
	counter--;
}
#endif // DEBUG деструктор


int country::counter = 0;

