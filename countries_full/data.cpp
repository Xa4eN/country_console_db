#include "data.h"
#include "country.h"

#include <vector>
#include <string>
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

//создание массива объектов класса:
vector<country> database;

void Set_Default_Data()
{
    //предварительная очистка массива для избежания багов:
    if (!database.empty()) database.clear();

    //массивы данных для инициализации свойств дефолтных объектов
    vector<string> names = {"Российская Федерация", "Украина", "Беларусь"};
    vector<string> capitals = { "Москва", "Киев", "Минск" };
    vector<int> populations = { 144, 44, 9 };
    vector<string> forms = { "республика", "республика", "республика" };
    vector<string> administrative = { "федеративное", "унитарное", "унитарное" };
    vector<string> regime = { "демократический", "демократический", "демократический" };

    //инициализация свойств дефолтных объектов:
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

    //вывод БД в случае наличия объектов класса:
    if (!database.empty())
    {
        for (int i = 0; i < database.size(); i++) database[i].Print();
    }
    //вывод БД в случае отсутствия объектов класса:
    else
    {
        cout << endl << "В базе данных нет сведений." << endl << endl;
    }

    cout << endl << "Для возврата в главное меню нажмите Escape.";

    //ожидание нажатия на Escape:
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

    //очистка массива объектов класса и обнуление счётчика:
    database.clear();
    country::ResetCount();

    cout << endl;
    cout << "База данных успешно очищена!" << endl << endl;
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

    //сохранение полученных от пользователя свойств объекта:
    cout << endl << "Введите название страны: ";
    getline(cin, name);
    cout << endl;

    cout << "Введите название столицы: ";
    getline(cin, capital);
    cout << endl;

    cout << "Введите численность населения (млн): ";
    getline(cin, population);
    cout << endl;

    cout << "Выберите форму правления в стране:" << endl;
    cout << "1) Республика" << endl;
    cout << "2) Монархия" << endl;
    cout << endl;

    while (worked)
    {
        if (_kbhit())
        {

            switch (_getch())
            {
            case '1': form = "республика"; worked = false; break;
            case '2': form = "монархия"; worked = false; break;
            }
        }
    }

    worked = true;

    cout << "Выберите административно-территориальное устройство страны:" << endl;
    cout << "1) Унитарное" << endl;
    cout << "2) Федеративное" << endl;
    cout << "3) Конфедеративное" << endl;
    cout << endl;

    while (worked)
    {
        if (_kbhit())
        {

            switch (_getch())
            {
            case '1': adm = "унитарное"; worked = false; break;
            case '2': adm = "федеративное"; worked = false; break;
            case '3': adm = "конфедеративное"; worked = false; break;
            }
        }
    }

    worked = true;

    cout << "Выберите политический режим в стране:" << endl;
    cout << "1) Демократический" << endl;
    cout << "2) Авторитарный" << endl;
    cout << "3) Тоталитарный" << endl;
    cout << endl;

    while (worked)
    {
        if (_kbhit())
        {

            switch (_getch())
            {
            case '1': regime = "демократический"; worked = false; break;
            case '2': regime = "авторитарный"; worked = false; break;
            case '3': regime = "тоталитарный"; worked = false; break;
            }
        }
    }

    country obj;

    //попытка инициализации полученных от пользователя свойств (обработка исключения связанного с некорректным вводом численности населения):
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

    //метка старт используется для возврата пользователя в меню изменения:
    start:

    system("cls");

    cout << endl;
    cout << "Выберите поле, которое хотите изменить:" << endl;
    cout << endl;
    cout << "1) Название страны" << endl;
    cout << "2) Название столицы" << endl;
    cout << "3) Численность населения" << endl;
    cout << "4) Государственный строй" << endl << endl;
    cout << "После завершения изменений нажмите Escape для возврата в главное меню." << endl;
    
    //ожидание нажатия на клавишу (выбор пункта из меню изменения):
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
                    cout << "Введите новое название страны и нажмите Enter: ";

                    getline(cin, value);

                    database[id].Set_Name(value);

                    cout << endl;
                    cout << "Название страны успешно изменено!" << endl << endl;
                    cout << "Для возврата в меню изменения нажмите Escape.";

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
                    cout << "Введите новое название столицы и нажмите Enter: ";

                    getline(cin, value);

                    database[id].Set_Capital(value);

                    cout << endl;
                    cout << "Название столицы успешно изменено!" << endl << endl;
                    cout << "Для возврата в меню изменения нажмите Escape.";

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
                    cout << "Введите новую численность населения страны и нажмите Enter: ";

                    getline(cin, value);

                    try
                    {
                        database[id].Set_Population(stoi(value));
                    }
                    catch (const exception& ex)
                    {
                        cout << endl;
                        cout << "Введено некорректное значение!" << endl << endl;
                        cout << "Для возврата в меню изменения нажмите Escape.";
                        goto exit_1;
                    }

                    cout << endl;
                    cout << "Численность населения страны успешно изменена!" << endl << endl;
                    cout << "Для возврата в меню изменения нажмите Escape.";

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
                    cout << "Выберите новую форму правления в стране:" << endl;
                    cout << "1) Республика" << endl;
                    cout << "2) Монархия" << endl;
                    cout << endl;

                    while (worked_inside)
                    {
                        if (_kbhit())
                        {

                            switch (_getch())
                            {
                            case '1': form = "республика"; worked_inside = false; break;
                            case '2': form = "монархия"; worked_inside = false; break;
                            }
                        }
                    }

                    worked_inside = true;

                    cout << "Выберите новое административно-территориальное устройство страны:" << endl;
                    cout << "1) Унитарное" << endl;
                    cout << "2) Федеративное" << endl;
                    cout << "3) Конфедеративное" << endl;
                    cout << endl;

                    while (worked_inside)
                    {
                        if (_kbhit())
                        {

                            switch (_getch())
                            {
                            case '1': adm = "унитарное"; worked_inside = false; break;
                            case '2': adm = "федеративное"; worked_inside = false; break;
                            case '3': adm = "конфедеративное"; worked_inside = false; break;
                            }
                        }
                    }

                    worked_inside = true;

                    cout << "Выберите новый политический режим в стране:" << endl;
                    cout << "1) Демократический" << endl;
                    cout << "2) Авторитарный" << endl;
                    cout << "3) Тоталитарный" << endl;
                    cout << endl;

                    while (worked_inside)
                    {
                        if (_kbhit())
                        {

                            switch (_getch())
                            {
                            case '1': regime = "демократический"; worked_inside = false; break;
                            case '2': regime = "авторитарный"; worked_inside = false; break;
                            case '3': regime = "тоталитарный"; worked_inside = false; break;
                            }
                        }
                    }

                    worked_inside = true;

                    database[id].Set_Politics({ form, adm, regime });

                    cout << endl;
                    cout << "Параметры государственного строя страны успешно изменены!" << endl << endl;
                    cout << "Для возврата в меню изменения нажмите Escape.";

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

    //удаление экземпляра в случае наличия единственного экземпляра (чтобы избежать багов out of range):
    if (database.size() == 1)
    {
        database.clear();
        country::ResetCount();
    }
    //удаление экземпляра в случае наличия нескольких экземпляров:
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
    cout << "Страна успешно удалена из базы данных!" << endl << endl;
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
