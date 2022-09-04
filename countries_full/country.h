#pragma once
#include <string>
#include <vector>

//#define DEBUG

using namespace std;


class country
{
private:
	static int counter;
	int id;

	string name;
	string capital;
	int population;
	vector<string> politics;

public:
	country(const string& name, const string& capital, const int population, const vector<string> politics);

	country();

	string& Get_Name();
	void Set_Name(const string& name);

	string& Get_Capital();
	void Set_Capital(const string& capital);

	long Get_Population();
	void Set_Population(const int population);

	vector<string> Get_Politics();
	void Set_Politics(vector<string> arr);

	void Set_All(const string& name, const string& capital, const int population, const vector<string> politics);

	void Print();

	int GetId();

	void DecreaseId();

	static int GetCount();

	static void IncreaseCount();

	static void DecreaseCount();

	static void ResetCount();

#ifdef DEBUG
	~country();
#endif // DEBUG

};


