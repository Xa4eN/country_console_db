#include "main_menu.h"
#include "data.h"
#include "country.h"

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>


//#define DEBUG

using namespace std;


int Start()
{
	system("cls");

	cout << "���� ������ � ����� ������:" << endl << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "1) ���������� ������ �����" << endl;
	cout << "2) �������� ������ � ������" << endl;
	cout << "3) ������� ������ �� ������" << endl;
	cout << "4) �������� ������������ � ������ ������" << endl;
	cout << "0) �������� ���� ������" << endl;
	cout << "-------------------------------------------------" << endl << endl;
	cout << "�������� �������� � ������� �� ��������������� ������ �� ����������..." << endl << endl;
	cout << "��� ������ �� ��������� ������� Escape." << endl << endl;

    while (true)
    {
        //�������� ������� �� �������:
        if (_kbhit()) // ��������� ������� �� �������
        {

            switch (_getch()) // ��� ������� �� ������� � ����������� � �����
            {
            case '0': return 0;
            case '1': return 1;
            case '2': return 2;
            case '3': return 3;
            case '4': return 4;
            case 27: return 27;    //Escape
            }
        }
    }
}


bool ClearWarning()
{   
    system("cls");

    extern vector<country> database;
    if (!database.empty())
    {
        cout << endl << "�� �������, ��� ������ �������� ���� ������?" << endl << endl << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "��������! ����� ���������� ������� �������� �������� ����� ����������." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

        cout << "��� ������������� ������� ������� Enter." << endl << endl;
        cout << "��� ������ � �������� � ������� ���� ������� Escape.";

        //�������� ������� �� �������:
        while (true)
        {
            if (_kbhit())
            {

                switch (_getch())
                {
                case 13: return true;   //Enter
                case 27: return false;  //Escape
                }
            }
        }
    }
    else
    {
        cout << endl << "���� ������ ��� �������." << endl << endl;
        cout << "��� �������� � ������� ���� ������� Escape.";

        //�������� ������� �� �������:
        while (true)
        {
            if (_kbhit())
            {

                switch (_getch())
                {
                case 27: return false;  //Escape
                }
            }
        }
    }
}

void AddCompletedBanner()
{
    bool worked = true;

    cout << endl << "������ ������� ���������!" << endl << endl;
    cout << "��� �������� �� ������� �������� ������� Escape.";

    //�������� ������� �� �������:
    while (worked)
    {
        if (_kbhit())
        {

            switch (_getch())
            {
            case 27: worked = false; break;
            }
        }
    }
}

int DeleteSelector()
{
    extern vector<country> database;

    string IdNumber;

    system("cls");

    cout << endl;
    cout << "�������� ������, ������� ������ ������� �� ���� ������:" << endl << endl;

    //����� ������ ������������ � �� �����
    for (int i = 0; i < country::GetCount(); i++)
    {
        cout << i + 1 << ") " << database[i].Get_Name() << endl;
    }

    cout << endl;
    cout << "������� ���������� ����� ������ � ������� Enter: ";
    getline(cin, IdNumber);

    //�������� �� ������������ �����:
    try
    {
        if (stoi(IdNumber) <= country::GetCount() && stoi(IdNumber) > 0)
        {
            return stoi(IdNumber);
        }
        else return 0;
    }
    catch (const exception& ex)
    {
        return 0;
    }
}

void DeleteError()
{
    bool worked = true;

    system("cls");

    cout << endl;
    cout << "������ ������������ ���������� �����!" << endl << endl;
    cout << "��� �������� � ������� ���� ������� Escape.";

    //�������� ������� �� ������� Escape
    while (worked)
    {
        if (_kbhit())
        {

            switch (_getch())
            {
            case 27: worked = false; break;
            }
        }
    }
}

int ChangeSelector()
{
    extern vector<country> database;
    
    string IdNumber;

    system("cls");

    cout << endl;
    cout << "�������� ������, ���������� � ������� ������ ��������:" << endl << endl;

    //����� ������ ������������ � �� �����
    for (int i = 0; i < country::GetCount(); i++)
    {
        cout << i + 1 << ") " << database[i].Get_Name() << endl;
    }

    cout << endl;
    cout << "������� ���������� ����� ������ � ������� Enter: ";
    getline(cin, IdNumber);

    //�������� �� ������������ �����:
    try
    {
        if (stoi(IdNumber) - 1 < country::GetCount() && stoi(IdNumber) > 0)
        {
            return stoi(IdNumber);
        }
        else return 0;
    }
    catch(const exception& ex)
    {
        return 0;
    }
}

void ChangeError()
{
    bool worked = true;

    system("cls");

    cout << endl;
    cout << "������ ������������ ���������� �����!" << endl << endl;
    cout << "��� �������� � ������� ���� ������� Escape.";

    //�������� ������� �� ������� Escape:
    while (worked)
    {
        if (_kbhit())
        {

            switch (_getch())
            {
            case 27: worked = false; break;
            }
        }
    }
}

void EmptyError()
{
    bool worked = true;

    system("cls");

    cout << endl;
    cout << "���������� ��������� ��������: ���� ������ �����!" << endl << endl;
    cout << "��� �������� � ������� ���� ������� Escape." << endl;

    //�������� ������� �� ������� Escape:
    while (worked)
    {
        if (_kbhit())
        {

            switch (_getch())
            {
            case 27: worked = false; break;
            }
        }
    }
}

bool DeleteWarning(int id)
{
    id--;

    extern vector<country> database;

    system("cls");

    cout << endl << "�� �������, ��� ������ ������� ������ <<" << database[id].Get_Name() << ">>?" << endl << endl << endl;

    cout << "��� ������������� �������� ������� Enter." << endl << endl;
    cout << "��� ������ � �������� � ������� ���� ������� Escape.";

    //�������� ������� �� �������:
    while (true)
    {
        if (_kbhit())
        {

            switch (_getch())
            {
            case 13: return true;   //Enter
            case 27: return false;  //Escape
            }
        }
    }
}
