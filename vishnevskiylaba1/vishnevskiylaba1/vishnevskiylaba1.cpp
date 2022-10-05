#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct truba
{   int lenght;
    int diametr;
    bool repair;
};

struct kaes
{
    string name;
    int countWS;
    int actWS;
    float eff;
};

void vivod_menu()
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

int Get_Int(int b)
{
    int n;
    cin >> n;
    while ((cin.fail()) || (n < 0) || (n > b) || (cin.get() != '\n')) {
        cin.clear();
        cin.ignore(1000000, '\n');
        cout << "Введите корректное число: ";
        cin >> n;
    }
    return n;
}

float Get_Float(float b)
{
    float n;
    cin >> n;
    while ((cin.fail()) || (n < 0) || (n > b) || (cin.get() != '\n')) {
        cin.clear();
        cin.ignore(1000000, '\n');
        cout << "Введите корректное число: ";
        cin >> n;
    }
    return n;
}

truba dobavittrubu()
{
    truba Obj;
    system("cls");
    cout << "Добавление трубы\n";
    cout << "Длина (км): "; 
    Obj.lenght = Get_Int(1000000);
    while (Obj.lenght <= 0) {
        cout << "Длинна должна быть больше 0!" << endl;
        Obj.lenght = Get_Int(1000000);
    }
    cout << "Диаметр (см): ";
   
    Obj.diametr = Get_Int(1000000);
    while (Obj.diametr <= 0) {
        cout << "Диаметр должен быть больше 0!" << endl;
        Obj.diametr = Get_Int(1000000);
    }
    cout << "Ремонт (0 - Нет или 1 - Да): ";
   
    Obj.repair = Get_Int(1);
    return Obj;
}

kaes dobavitkaes()
{
    kaes Obj;
    system("cls");
    cout << "Добавление КС\n";
    cout << "Имя: ";
  
    getline(cin, Obj.name);
    cout << "Кол-во цехов: ";
    
    Obj.countWS = Get_Int(1000000);
    while (Obj.countWS <= 0) {
        cout << "Кол-во цехов должно быть больше 0!" << endl;
        Obj.countWS = Get_Int(1000000);
    }
    cout << "Кол-во цехов в работе: ";
   
    Obj.actWS = Get_Int(1000000);
    while (Obj.countWS < Obj.actWS) {
        cout << "Количество цехов в работе должно быть меньше либо равно общему количеству цехов!" << endl;
        Obj.actWS = Get_Int(1000000);
    }
    cout << "Эффективность (От 0 до 1): ";
   
    Obj.eff = Get_Float(1);
    return Obj;
}

void pokaztruba(const truba& Obj)
{
    if (Obj.diametr != 0) {
        cout << "Длинна\t" << "Диаметр\t" << "Ремонт\t" << endl;
        cout << "================================================" << endl;
        cout << Obj.lenght << '\t' << Obj.diametr << '\t' << Obj.repair << endl;

    }
}

void pokazkaes(const kaes& Obj)
{
    if (Obj.countWS != 0)
    {
        cout << "Имя\t" << "Кол-во цехов\t" << "Кол-во цехов в работе\t" << "Эффективность\t" << endl;
        cout << "===========================================================================" << endl;
        cout << Obj.name << '\t' << Obj.countWS << '\t' << Obj.actWS << '\t' << Obj.eff << endl;
    }
}

void redaktruba(truba& Obj)
{
    system("cls");
    cout << "4. Ремонт\n" << "0. Выход\n" << ">";
    int cursor = Get_Int(4);
    switch (cursor) {
    case 4:
        cout << "Текущий Ремонт: " << Obj.repair << "\n";
        cout << "Ремонт (0 - Нет или 1 - Да): ";
        
        Obj.repair = Get_Int(1);
        break;
    case 0:
        break;
    }
}

void redakkaes(kaes& Obj)
{
    system("cls");
    cout << "3. Кол-во цехов в работе\n" << "0. Выход\n" << ">";
    int cursor = Get_Int(4);
    switch (cursor) {
    case 3:
        cout << "Текущее кол-во цехов в работе: " << Obj.actWS << "\n";
        cout << "Новое кол-во цехов в работе: ";
        
        Obj.actWS = Get_Int(1000000);
        while (Obj.countWS < Obj.actWS) {
            cout << "Количество цехов в работе должно быть меньше либо равно общему количеству цехов!" << endl;
            Obj.actWS = Get_Int(1000000);
        }
        break;
    case 0:
        break;
    }
}

void sahranit(const truba& Obj1, const kaes& Obj2)
{
    ofstream fout("C:\\vishnevskiylaba1\\vishnevskiylaba1\\txt.txt");
    if (Obj1.diametr != 0)
    {
     fout << 0 << " / " << Obj1.lenght << " / " << Obj1.diametr << " / " << Obj1.repair << endl;
    }
    if (Obj2.countWS != 0)
    {
     fout << 1 << " / " << Obj2.name << "/" << Obj2.countWS << " / " << Obj2.actWS << " / " << Obj2.eff << endl;
    }
    
    fout.close();
}

void zagruzit(truba& Obj1, kaes& Obj2)
{
    ifstream fin("C:\\vishnevskiylaba1\\vishnevskiylaba1\\txt.txt");
    string buff;
    if (!fin.is_open()) 
        cout << "Файл не может быть открыт!\n"; 
    else
    {
        int i = 0;
        int q;
        while (i <= 1)
            fin >> q;
        if (q == 0)
        {
            fin >> ws;
            fin >> Obj1.lenght;
            fin >> Obj1.diametr;
            fin >> Obj1.repair;
        }
        else if (q == 1)
        {
            fin >> ws;
            std::getline(fin, Obj2.name);
            fin >> Obj2.countWS;
            fin >> Obj2.actWS;
            fin >> Obj2.eff;
        }
        i++;
    }
        fin.close();   
        return;
    
}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int cursor;

    truba p = { 0, 0, 0 };
    kaes CS = { "0", 0, 0, 0 };

    do
    {
        vivod_menu();
        cursor = Get_Int(7);

        switch (cursor) {
        case 1:
        {
            
            p = dobavittrubu();
            break;
        }

        case 2:
        { 
            CS = dobavitkaes();
            break;
        }

        case 3:
        {
            
            system("cls");
            cout << "Просмотр всех объектов\n\n";
            pokaztruba(p);
            cout << "\n";
            pokazkaes(CS);
            break;
        }

        case 4:
        {
                      
            redaktruba(p);
            break;
        }

        case 5:
        {
                        
            redakkaes(CS);
            break;
        }

        case 6:
        {
            
            sahranit(p, CS);
            break;
        }

        case 7:
        {
            
            zagruzit(p, CS);
            break;
        }
        }
        if (cursor != 0) system("pause");
    } while (cursor != 0);
    return 0;
}