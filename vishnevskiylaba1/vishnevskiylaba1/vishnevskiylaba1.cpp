﻿// vishnevskiylaba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct pipe
{
    string name;
    int lenght;
    int diametr;
    bool repair;
};

struct CS
{
    string name;
    int countWS;
    int actWS;
    float eff;
};

void print_menu()
{
    system("cls");
    cout << "1. Добавить трубу\n";
    cout << "2. Добавить КС\n";
    cout << "3. Просмотр всех объектов\n";
    cout << "4. Редактировать трубу\n";
    cout << "5. Редактировать КС\n";
    cout << "6. Сохранить\n";
    cout << "7. Загрузить\n";
    cout << "0. Выход\n";
    cout << "\nВыберите действие - ";
}

int get_variant(int count)
{
    int variant;
    string s;
    getline(cin, s);
    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 0 || variant > count)
    {
        cout << "Некорректный ввод. Попробуйте снова: ";
        getline(cin, s);
    }
    return variant;
}

pipe AddPipe()
{
    pipe Obj;
    system("cls");
    cout << "Добавление трубы\n";
    cout << "Имя: ";
    cin >> Obj.name;
    cout << "Длинна (м): ";
    cin >> Obj.lenght;
    cout << "Диаметр (мм): ";
    cin >> Obj.diametr;
    cout << "Ремонт (0 или 1): ";
    //int rep = get_variant(1);
    //Obj.repair = rep;
    cin >> Obj.repair;
    return Obj;
}

CS AddCS()
{
    CS Obj;
    system("cls");
    cout << "Добавление КС\n";
    cout << "Имя: ";
    cin >> Obj.name;
    cout << "Кол-во цехов: ";
    cin >> Obj.countWS;
    cout << "Кол-во цехов в работе: ";
    cin >> Obj.actWS;
    cout << "Эффективность: ";
    cin >> Obj.eff;
    return Obj;
}

void ShowPipe(const pipe& Obj)
{
    cout << "Имя\t" << "Длинна\t" << "Диаметр\t" << "Ремонт\t" << endl;
    cout << "================================================" << endl;
    cout << Obj.name << '\t' << Obj.lenght << '\t' << Obj.diametr << '\t' << Obj.repair << endl;
}

void ShowCS(const CS& Obj)
{
    cout << "Имя\t" << "countWS\t" << "actWS\t" << "Эффективность\t" << endl;
    cout << "===========================================================================" << endl;
    cout << Obj.name << '\t' << Obj.countWS << '\t' << Obj.actWS << '\t' << Obj.eff << endl;
}

void EditPipe(pipe& Obj)
{
    system("cls");
    cout << "Что редактируем?\n" << "1. Имя\n" << "2. Длинна\n" << "3. Диаметр\n" << "4. Ремонт\n" << "0. Выход\n" << ">";
    int cursor = get_variant(4);
    switch (cursor) {
    case 1:
        cout << "Текущее имя: " << Obj.name << "\n";
        cout << "Новое имя: ";
        cin >> Obj.name;
        break;
    case 2:
        cout << "Текущая длинна: " << Obj.lenght << "\n";
        cout << "Новая длинна (м): ";
        cin >> Obj.lenght;
        break;
    case 3:
        cout << "Текущий диаметр: " << Obj.diametr << "\n";
        cout << "Новый диаметр (мм): ";
        cin >> Obj.diametr;
        break;
    case 4:
        cout << "Текущий Ремонт: " << Obj.repair << "\n";
        cout << "Ремонт (0 или 1): ";
        //int rep = get_variant(1);
        //Obj.repair = rep;
        cin >> Obj.repair;
        break;
    case 0:
        break;
    }
}

void EditCS(CS& Obj)
{
    system("cls");
    cout << "Что редактируем?\n" << "1. Имя\n" << "2. Кол-во цехов\n" << "3. Кол-во цехов в работе\n" << "4. Эффективность\n" << "0. Выход\n" << ">";
    int cursor = get_variant(4);
    switch (cursor) {
    case 1:
        cout << "Текущее имя: " << Obj.name << "\n";
        cout << "Новое имя: ";
        cin >> Obj.name;
        break;
    case 2:
        cout << "Текущее кол-во цехов: " << Obj.countWS << "\n";
        cout << "Новое кол-во цехов: ";
        cin >> Obj.countWS;
        break;
    case 3:
        cout << "Текущее кол-во цехов в работе: " << Obj.actWS << "\n";
        cout << "Новое кол-во цехов в работе: ";
        cin >> Obj.actWS;
        break;
    case 4:
        cout << "Текущая эффективность: " << Obj.eff << "\n";
        cout << "Новая эффективность: ";
        cin >> Obj.eff;
        break;
    case 0:
        break;
    }
}

void Save(const pipe& Obj1, const CS& Obj2)
{
    ofstream fout("C:\\Users\\iship\\OneDrive\\Документы\\GitHub\\CrossPlatform\\Shipov_Lab_1\\mas.txt");
    fout << Obj1.name << " " << Obj1.lenght << " " << Obj1.diametr << " " << Obj1.repair << endl;
    fout << Obj2.name << " " << Obj2.countWS << " " << Obj2.actWS << " " << Obj2.eff << endl;
    fout.close();
}

void Upload(pipe& Obj1, CS& Obj2)
{
    ifstream fin("C:\\Users\\iship\\OneDrive\\Документы\\GitHub\\CrossPlatform\\Shipov_Lab_1\\mas.txt");
    string buff;
    if (!fin.is_open()) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом
    else
    {
        fin >> Obj1.name;
        fin >> Obj1.lenght;
        fin >> Obj1.diametr;
        fin >> Obj1.repair;

        fin >> Obj2.name;
        fin >> Obj2.countWS;
        fin >> Obj2.actWS;
        fin >> Obj2.eff;

        fin.close(); // закрываем файл        
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int cursor;

    pipe p = { "0", 0, 0, 0 };
    CS CS = { "0", 0, 0, 0 };

    do
    {
        print_menu();
        cursor = get_variant(7);

        switch (cursor) {
        case 1:
        {
            //cout << "Действие: " << cursor << "\n";  
            p = AddPipe();
            break;
        }

        case 2:
        {
            //cout << "Действие: " << cursor << "\n"; 
            CS = AddCS();
            break;
        }

        case 3:
        {
            //cout << "Действие: " << cursor << "\n";   
            system("cls");
            cout << "Просмотр всех объектов\n\n";
            ShowPipe(p);
            cout << "\n";
            ShowCS(CS);
            break;
        }

        case 4:
        {
            //cout << "Действие: " << cursor << "\n";            
            EditPipe(p);
            break;
        }

        case 5:
        {
            //cout << "Действие: " << cursor << "\n";            
            EditCS(CS);
            break;
        }

        case 6:
        {
            //cout << "Действие: " << cursor << "\n";
            Save(p, CS);
            break;
        }

        case 7:
        {
            //cout << "Действие: " << cursor << "\n";
            Upload(p, CS);
            break;
        }
        }
        if (cursor != 0) system("pause");
    } while (cursor != 0);
    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
