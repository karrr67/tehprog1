#include <iostream>
#include <limits>
#include <stdexcept>
#include "Keeper.h"
#include "Book.h"
#include "Textbook.h"
#include "Stationery.h"

using namespace std;

int readInt() {
    int x;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Некорректный ввод, повторите: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return x;
}

void printMenu() {
    cout << "\n===== МЕНЮ =====\n"
         << "1. Добавить книгу\n"
         << "2. Добавить учебник\n"
         << "3. Добавить канцелярию\n"
         << "4. Показать все\n"
         << "5. Удалить по номеру\n"
         << "6. Изменить по номеру\n"     
         << "7. Сохранить в файл\n"     
         << "8. Загрузить из файла\n" 
         << "9. Очистить\n"   
         << "0. Выход\n"
         << "Выбор: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    Keeper k;
    int choice = -1;

    while (choice != 0) {
        printMenu();
        choice = readInt();

        try {
            switch (choice) {
            case 1: {
                Book* b = new Book();
                b->input(cin);
                k.add(b);
                cout << "Книга добавлена.\n";
                break;
            }
            case 2: {
                Textbook* t = new Textbook();
                t->input(cin);
                k.add(t);
                cout << "Учебник добавлен.\n";
                break;
            }
            case 3: {
                Stationery* s = new Stationery();
                s->input(cin);
                k.add(s);
                cout << "Канцелярия добавлена.\n";
                break;
            }
            case 4:
                k.printAll(cout);
                break;
            case 5: {
                cout << "Индекс (0.." << k.getCount() - 1 << "): ";
                int i = readInt();
                k.remove(i);
                break;
            }
            case 6: {
                cout << "Индекс (0.." << k.getCount() - 1 << "): ";
                int i = readInt();
                Base* obj = k.getAt(i);   
                cout << "Введите новые данные:\n";
                obj->input(cin);
                cout << "Изменено.\n";
                break;
            }
            case 7: {                     
                cout << "Имя файла: ";
                string f;
                getline(cin, f);
                k.saveToFile(f);
                break;
            }
            case 8: {       
                cout << "Имя файла: ";
                string f;
                getline(cin, f);
                k.loadFromFile(f);
                break;
            }
            case 9:       
                k.clear();
                cout << "Контейнер очищен.\n";
                break;
            case 0:
                cout << "Выход.\n";
                break;
            default:
                cout << "Неверный пункт.\n";
                break;
            }
        }
        catch (const exception& e) {
            cout << "Ошибка: " << e.what() << "\n";
        }
    }
    return 0;
}