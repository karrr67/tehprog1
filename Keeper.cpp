#include "Keeper.h"
#include "Book.h"
#include "Textbook.h"
#include "Stationery.h"

Keeper::Keeper() : items(nullptr), count(0), cap(0) {
    cout << "[Keeper] конструктор по умолчанию\n";
}

Keeper::Keeper(const Keeper& o) : items(nullptr), count(0), cap(0) {
    cout << "[Keeper] конструктор копирования\n";
    if (o.count > 0) {
        cap = o.count;
        items = new Base*[cap];
        for (int i = 0; i < o.count; ++i)
            items[count++] = o.items[i]->clone();
    }
}

Keeper::~Keeper() {
    cout << "[Keeper] деструктор\n";
    clear();
    delete[] items;
}

Keeper& Keeper::operator=(const Keeper& o) {
    if (this == &o) return *this;
    clear();
    delete[] items;
    items = nullptr; count = 0; cap = 0;
    if (o.count > 0) {
        cap = o.count;
        items = new Base*[cap];
        for (int i = 0; i < o.count; ++i)
            items[count++] = o.items[i]->clone();
    }
    return *this;
}

void Keeper::reserve(int newCap) {
    if (newCap <= cap) return;
    Base** tmp = new Base*[newCap];
    for (int i = 0; i < count; ++i) tmp[i] = items[i];
    delete[] items;
    items = tmp;
    cap = newCap;
}

Base* Keeper::getAt(int i) const {
    if (i < 0 || i >= count)
        throw out_of_range("Keeper::getAt — индекс " + to_string(i) + " вне диапазона");
    return items[i];
}

void Keeper::add(Base* p) {
    if (!p)
        throw invalid_argument("Keeper::add — попытка добавить nullptr");
    if (count == cap) reserve(cap == 0 ? 4 : cap * 2);
    items[count++] = p;
}

void Keeper::remove(int i) {
    if (i < 0 || i >= count)
        throw out_of_range("Keeper::remove — индекс " + to_string(i) + " вне диапазона");
    delete items[i];
    for (int j = i; j < count - 1; ++j) items[j] = items[j + 1];
    --count;
}

void Keeper::clear() {
    for (int i = 0; i < count; ++i) delete items[i];
    count = 0;
}

void Keeper::printAll(ostream& os) const {
    if (count == 0) { os << "Контейнер пуст.\n"; return; }
    for (int i = 0; i < count; ++i) {
        os << i << ": ";
        items[i]->print(os);
    }
}

void Keeper::saveToFile(const string& filename) const {
    ofstream f(filename);
    if (!f)
        throw runtime_error("Keeper::saveToFile — не удалось открыть файл: " + filename);
    f << count << "\n";
    for (int i = 0; i < count; ++i) {
        f << items[i]->getType() << "\n";
        items[i]->save(f);
    }
    f.close();
    cout << "Сохранено объектов: " << count << "\n";
}

void Keeper::loadFromFile(const string& filename) {
    ifstream f(filename);
    if (!f) { cout << "Ошибка: не удалось открыть файл " << filename << "\n"; return; }

    int n = 0;
    f >> n;
    f.ignore();
    if (n < 0) { cout << "Ошибка: некорректный файл\n"; return; }

    clear();

    for (int i = 0; i < n; ++i) {
        int t = 0;
        f >> t;
        f.ignore();

        Base* obj = nullptr;
        if (t == 1) 
            obj = new Book();
        else if (t == 2) 
            obj = new Textbook();
        else if (t == 3) 
            obj = new Stationery();
        else { cout << "Ошибка: неизвестный тип в файле\n"; return; }

        obj->load(f);
        add(obj);
    }
    cout << "Загружено объектов: " << count << "\n";
}