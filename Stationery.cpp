#include "Stationery.h"

Stationery::Stationery() : Base(), color(""), purpose("") {
    cout << "[Stationery] конструктор по умолчанию\n";
}

Stationery::Stationery(const Stationery& o)
    : Base(o), color(o.color), purpose(o.purpose) {
    cout << "[Stationery] конструктор копирования\n";
}

Stationery::~Stationery() {
    cout << "[Stationery] деструктор\n";
}

void Stationery::input(istream& is) {
    cout << "  тип: "; getline(is, name);
    cout << "  цвет: "; getline(is, color);
    cout << "  назначение: "; getline(is, purpose);
    cout << "  цена: "; is >> price; is.ignore();
}

void Stationery::print(ostream& os) const {
    os << "Канцелярия: " << name << "\n"
       << "цвет: " << color << "\n"
       << "назначение: " << purpose << "\n"
       << "цена: " << price << "\n";
}

void Stationery::save(ofstream& ofs) const {
    ofs << name << "\n"
        << price << "\n"
        << color << "\n"
        << purpose << "\n";
}

void Stationery::load(ifstream& ifs) {
    getline(ifs, name);
    ifs >> price; ifs.ignore();
    getline(ifs, color);
    getline(ifs, purpose);
}