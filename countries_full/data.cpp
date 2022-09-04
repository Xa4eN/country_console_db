#include "data.h"
#include "country.h"

#include <vector>
#include <string>
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

//�������� ������� �������� ������:
vector<country> database;

void Set_Default_Data()
{
    //��������������� ������� ������� ��� ��������� �����:
    if (!database.empty()) database.clear();

    //������� ������ ��� ������������� ������� ��������� ��������
    vector<string> names = {"���������� ���������", "�������", "��������"};
    vector<string> capitals = { "������", "����", "�����" };
    vector<int> populations = { 144, 44, 9 };
    vector<string> forms = { "����������", "����������", "����������" };
    vector<string> administrative = { "������������", "���������", "���������" };
    vector<string> regime = { "���������������", "���������������", "���������������" };

    //������������� ������� ��������� ��������:
    for (int i = 0; i < 3; i++)
    {
        country obj;
        obj.Set_All(names[i], capitals[i], populations[i], {forms[i], administrative[i], regime[i]});
        database.push_back(obj);
    }
}

bool Print_Data()
{
    system("cls");

    //����� �� � ������ ������� �������� ������:
    if (!database.empty())
    {
        for (int i = 0; i < database.size(); i++) database[i].Print();
    }
    //����� �� � ������ ���������� �������� ������:
    else
    {
        cout << endl << "� ���� ������ ��� ��������." << endl << endl;
    }

    cout << endl << "��� �������� � ������� ���� ������� Escape.";

    //�������� ������� �� Escape:
    while (true)
    {
        if (_kbhit())
        {

            switch (_getch())
            {
            case 27: return true;  //Escape
            }
        }
    }
}

void Clear_Data()
{
    bool worked = true;

    system("cls");

    //������� ������� �������� ������ � ��������� ��������:
    database.clear();
    country::ResetCount();

    cout << endl;
    cout << "���� ������ ������� �������!" << endl << endl;
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

void Add_Data_Member()
{
    system("cls");

    string name;
    string capital;
    string population;
    string form;
    string adm;
    string regime;

    bool worked = true;

    //���������� ���������� �� ������������ ������� �������:
    cout << endl << "������� �������� ������: ";
    getline(cin, name);
    cout << endl;

    cout << "������� �������� �������: ";
    getline(cin, capital);
    cout << endl;

    cout << "������� ����������� ��������� (���): ";
    getline(cin, population);
    cout << endl;

    cout << "�������� ����� ��������� � ������:" << endl;
    cout << "1) ����������" << endl;
    cout << "2) ��������" << endl;
    cout << endl;

    while (worked)
    {
        if (_kbhit())
        {

            switch (_getch())
            {
            case '1': form = "����������"; worked = false; break;
            case '2': form = "��������"; worked = false; break;
            }
        }
    }

    worked = true;

    cout << "�������� ���������������-��������������� ���������� ������:" << endl;
    cout << "1) ���������" << endl;
    cout << "2) ������������" << endl;
    cout << "3) ���������������" << endl;
    cout << endl;

    while (worked)
    {
        if (_kbhit())
        {

            switch (_getch())
            {
            case '1': adm = "���������"; worked = false; break;
            case '2': adm = "������������"; worked = false; break;
            case '3': adm = "���������������"; worked = false; break;
            }
        }
    }

    worked = true;

    cout << "�������� ������������ ����� � ������:" << endl;
    cout << "1) ���������������" << endl;
    cout << "2) ������������" << endl;
    cout << "3) ������������" << endl;
    cout << endl;

    while (worked)
    {
        if (_kbhit())
        {

            switch (_getch())
            {
            case '1': regime = "���������������"; worked = false; break;
            case '2': regime = "������������"; worked = false; break;
            case '3': regime = "������������"; worked = false; break;
            }
        }
    }

    country obj;

    //������� ������������� ���������� �� ������������ ������� (��������� ���������� ���������� � ������������ ������ ����������� ���������):
    try
    {
        obj.Set_All(name, capital, stoi(population), { form, adm, regime });
    }
    catch(const exception& ex)
    {
        obj.Set_All(name, capital, 0, { form, adm, regime });
    }

    database.push_back(obj);
}

void Change_Data(int id)
{
    id--;
    bool worked = true;

    //����� ����� ������������ ��� �������� ������������ � ���� ���������:
    start:

    system("cls");

    cout << endl;
    cout << "�������� ����, ������� ������ ��������:" << endl;
    cout << endl;
    cout << "1) �������� ������" << endl;
    cout << "2) �������� �������" << endl;
    cout << "3) ����������� ���������" << endl;
    cout << "4) ��������������� �����" << endl << endl;
    cout << "����� ���������� ��������� ������� Escape ��� �������� � ������� ����." << endl;
    
    //�������� ������� �� ������� (����� ������ �� ���� ���������):
    while (worked)
    {
        if (_kbhit())
        {

            switch (_getch())
            {
                case '1': 
                {
                    string value;
                    bool worked_inside = true;

                    system("cls");

                    cout << endl;
                    cout << "������� ����� �������� ������ � ������� Enter: ";

                    getline(cin, value);

                    database[id].Set_Name(value);

                    cout << endl;
                    cout << "�������� ������ ������� ��������!" << endl << endl;
                    cout << "��� �������� � ���� ��������� ������� Escape.";

                    while (worked_inside)
                    {
                        if (_kbhit())
                        {

                            switch (_getch())
                            {
                            case 27: worked_inside = false; break;
                            }
                        }
                    }
                    goto start;
                }

                case '2': 
                {
                    string value;
                    bool worked_inside = true;

                    system("cls");

                    cout << endl;
                    cout << "������� ����� �������� ������� � ������� Enter: ";

                    getline(cin, value);

                    database[id].Set_Capital(value);

                    cout << endl;
                    cout << "�������� ������� ������� ��������!" << endl << endl;
                    cout << "��� �������� � ���� ��������� ������� Escape.";

                    while (worked_inside)
                    {
                        if (_kbhit())
                        {

                            switch (_getch())
                            {
                            case 27: worked_inside = false; break;
                            }
                        }
                    }
                    goto start;
                }

                case '3': 
                {
                    string value;
                    bool worked_inside = true;

                    system("cls");

                    cout << endl;
                    cout << "������� ����� ����������� ��������� ������ � ������� Enter: ";

                    getline(cin, value);

                    try
                    {
                        database[id].Set_Population(stoi(value));
                    }
                    catch (const exception& ex)
                    {
                        cout << endl;
                        cout << "������� ������������ ��������!" << endl << endl;
                        cout << "��� �������� � ���� ��������� ������� Escape.";
                        goto exit_1;
                    }

                    cout << endl;
                    cout << "����������� ��������� ������ ������� ��������!" << endl << endl;
                    cout << "��� �������� � ���� ��������� ������� Escape.";

                    exit_1:
                    while (worked_inside)
                    {
                        if (_kbhit())
                        {

                            switch (_getch())
                            {
                            case 27: worked_inside = false; break;
                            }
                        }
                    }
                    goto start;
                }

                case '4':
                {
                    bool worked_inside = true;
                    string form, adm, regime;

                    system("cls");

                    cout << endl;
                    cout << "�������� ����� ����� ��������� � ������:" << endl;
                    cout << "1) ����������" << endl;
                    cout << "2) ��������" << endl;
                    cout << endl;

                    while (worked_inside)
                    {
                        if (_kbhit())
                        {

                            switch (_getch())
                            {
                            case '1': form = "����������"; worked_inside = false; break;
                            case '2': form = "��������"; worked_inside = false; break;
                            }
                        }
                    }

                    worked_inside = true;

                    cout << "�������� ����� ���������������-��������������� ���������� ������:" << endl;
                    cout << "1) ���������" << endl;
                    cout << "2) ������������" << endl;
                    cout << "3) ���������������" << endl;
                    cout << endl;

                    while (worked_inside)
                    {
                        if (_kbhit())
                        {

                            switch (_getch())
                            {
                            case '1': adm = "���������"; worked_inside = false; break;
                            case '2': adm = "������������"; worked_inside = false; break;
                            case '3': adm = "���������������"; worked_inside = false; break;
                            }
                        }
                    }

                    worked_inside = true;

                    cout << "�������� ����� ������������ ����� � ������:" << endl;
                    cout << "1) ���������������" << endl;
                    cout << "2) ������������" << endl;
                    cout << "3) ������������" << endl;
                    cout << endl;

                    while (worked_inside)
                    {
                        if (_kbhit())
                        {

                            switch (_getch())
                            {
                            case '1': regime = "���������������"; worked_inside = false; break;
                            case '2': regime = "������������"; worked_inside = false; break;
                            case '3': regime = "������������"; worked_inside = false; break;
                            }
                        }
                    }

                    worked_inside = true;

                    database[id].Set_Politics({ form, adm, regime });

                    cout << endl;
                    cout << "��������� ���������������� ����� ������ ������� ��������!" << endl << endl;
                    cout << "��� �������� � ���� ��������� ������� Escape.";

                    while (worked_inside)
                    {
                        if (_kbhit())
                        {

                            switch (_getch())
                            {
                            case 27: worked_inside = false; break;
                            }
                        }
                    }
                    goto start;
                }

                case 27:
                {
                    worked = false;
                    break;
                }
            }
        }
    }
}

void Delete_Data(int id)
{
    bool worked = true;

    id--;

    system("cls");

    //�������� ���������� � ������ ������� ������������� ���������� (����� �������� ����� out of range):
    if (database.size() == 1)
    {
        database.clear();
        country::ResetCount();
    }
    //�������� ���������� � ������ ������� ���������� �����������:
    else
    {
        for (int i = id + 1; i < database.size(); i++)
        {
            database[i].DecreaseId();
        }

        country::DecreaseCount();

        database.erase(database.begin() + id);
    }

    cout << endl;
    cout << "������ ������� ������� �� ���� ������!" << endl << endl;
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
