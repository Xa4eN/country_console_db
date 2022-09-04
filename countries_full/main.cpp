#include <iostream>
#include <vector>
#include <Windows.h>

#include "country.h"
#include "main_menu.h"
#include "data.h"

//#define DEBUG

using namespace std;


int main()  //организация логики переходов между разделами
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");

    bool worked = true;

#ifdef DEBUG
    vector<country> database;
    for (int i = 0; i < 5; i++)
    {
        country x("x", "x", 12, { "f", "s", "f" });
        database.push_back(x);
    }

    for (int i = 0; i < 5; i++)
    {
        database[i].Print();
    }
#endif // DEBUG создание + вывод экземпляров

    Set_Default_Data();

    while (worked)
    {
        //функция start() возвращает значение, соответвующее выбранному пользователем разделу:
        switch (Start())    
        {
            //переход в раздел очистки БД:
            case 0:     
            {
                if (ClearWarning()) Clear_Data();
                break;
            }
            //переход в раздел просмотра БД:
            case 1:     
            { 
                Print_Data(); 
                break; 
            }
            //переход в раздел добавления экземпляра в БД:
            case 2:     
            {
                Add_Data_Member();
                AddCompletedBanner();
                break;
            }
            //переход в раздел удаления экземпляра из БД:
            case 3:
            {
                int id;
                extern vector<country> database;

                if (!database.empty())
                {
                    id = DeleteSelector();
                    if (id == 0)
                    {
                        DeleteError();
                        break;
                    }
                    else
                    {
                        if (DeleteWarning(id)) Delete_Data(id);
                        break;
                    }
                }
                else
                {
                    EmptyError();
                    break;
                }
            }
            //переход в раздел изменения экземпляра в БД:
            case 4:
            {
                int id;
                extern vector<country> database;

                if (!database.empty())
                {
                    id = ChangeSelector();
                    if (id == 0)
                    {
                        ChangeError();
                        break;
                    }
                    else
                    {
                        Change_Data(id);
                        break;
                    }
                }
                else
                {
                    EmptyError();
                    break;
                }
            }
            //выход из программы:
            case 27: worked = false;
        }
    }
    
    return 0;
}

