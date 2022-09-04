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

	cout << "Меню работы с базой данных:" << endl << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "1) Посмотреть список стран" << endl;
	cout << "2) Добавить страну в список" << endl;
	cout << "3) Удалить страну из списка" << endl;
	cout << "4) Изменить существующую в списке страну" << endl;
	cout << "0) Очистить базу данных" << endl;
	cout << "-------------------------------------------------" << endl << endl;
	cout << "Выберите действие и нажмите на соответствующую кнопку на клавиатуре..." << endl << endl;
	cout << "Для выхода из программы нажмите Escape." << endl << endl;

    while (true)
    {
        //ожидание нажатия на клавишу:
        if (_kbhit()) // слушатель нажатия на клавишу
        {

            switch (_getch()) // ждёт нажатия на клавишу с сохранением в буфер
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
        cout << endl << "Вы уверены, что хотите очистить базу данных?" << endl << endl << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Внимание! После выполнения очистки отменить действие будет невозможно." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

        cout << "Для подтверждения очистки нажмите Enter." << endl << endl;
        cout << "Для отмены и возврата в главное меню нажмите Escape.";

        //ожидание нажатия на клавишу:
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
        cout << endl << "База данных уже очищена." << endl << endl;
        cout << "Для возврата в главное меню нажмите Escape.";

        //ожидание нажатия на клавишу:
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

    cout << endl << "Данные успешно добавлены!" << endl << endl;
    cout << "Для возврата на главную страницу нажмите Escape.";

    //ожидание нажатия на клавишу:
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
    cout << "Выберите страну, которую хотите удалить из базы данных:" << endl << endl;

    //вывод списка существующих в БД стран
    for (int i = 0; i < country::GetCount(); i++)
    {
        cout << i + 1 << ") " << database[i].Get_Name() << endl;
    }

    cout << endl;
    cout << "Введите порядковый номер страны и нажмите Enter: ";
    getline(cin, IdNumber);

    //проверка на корректность ввода:
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
    cout << "Выбран некорректный порядковый номер!" << endl << endl;
    cout << "Для возврата в главное меню нажмите Escape.";

    //ожидание нажатия на клавишу Escape
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
    cout << "Выберите страну, информацию о которой хотите изменить:" << endl << endl;

    //вывод списка существующих в БД стран
    for (int i = 0; i < country::GetCount(); i++)
    {
        cout << i + 1 << ") " << database[i].Get_Name() << endl;
    }

    cout << endl;
    cout << "Введите порядковый номер страны и нажмите Enter: ";
    getline(cin, IdNumber);

    //проверка на корректность ввода:
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
    cout << "Выбран некорректный порядковый номер!" << endl << endl;
    cout << "Для возврата в главное меню нажмите Escape.";

    //ожидание нажатия на клавишу Escape:
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
    cout << "Невозможно выполнить действие: база данных пуста!" << endl << endl;
    cout << "Для возврата в главное меню нажмите Escape." << endl;

    //ожидание нажатия на клавишу Escape:
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

    cout << endl << "Вы уверены, что хотите удалить страну <<" << database[id].Get_Name() << ">>?" << endl << endl << endl;

    cout << "Для подтверждения удаления нажмите Enter." << endl << endl;
    cout << "Для отмены и возврата в главное меню нажмите Escape.";

    //ожидание нажатия на клавишу:
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
