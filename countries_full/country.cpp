#include "country.h"

#include <string>
#include <iostream>

//#define DEBUG

using namespace std;

//���������� ������������ ��� ������������� ���� ����������:
country::country(const string& name, const string& capital, const int population, const vector<string> politics)
{
#ifdef DEBUG
	cout << "�������� �����������" << endl;
#endif // DEBUG


	counter++;
	id = counter;

	this->name = name;
	this->capital = capital;
	this->population = population;
	
	for (int i = 0; i < 3; i++) this->politics.push_back(politics[i]);
}

//���������� ������������ ��� ������������� ����������:
country::country()
{
	counter++;
	id = counter;

	population = 0;
}

//������� � ������� ��� ������� �������
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

//����� ������ ������� � �������:
void country::Print()
{
	cout << "**************************************************************************************" << endl;
	cout << "���������� ����� � ���� ������: " << id << endl << endl;
	cout << "�������� ������: " << name << "\t\t" << "�������: " << capital << endl;
	cout << "����������� ���������: " << population << " ���. �������" << endl;
	cout << "��������������� �����:" << endl;
	cout << " -> ����� ��������� - " << politics[0] << endl;
	cout << " -> ���������������-��������������� ���������� - " << politics[1] << endl;
	cout << " -> ������������ ����� - " << politics[2] << endl;
	cout << "**************************************************************************************" << endl << endl;
}

//������ ���������� ������������ � ������������������ ����������:
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

//���� ����������� ��� ��������� static counter ��� �������� ����� �� ��
#ifdef DEBUG
country::~country()
{
	cout << "�������� ����������" << endl;
	counter--;
}
#endif // DEBUG ����������


int country::counter = 0;

