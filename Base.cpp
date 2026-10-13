#include "Base.h"

Base::Base(): name(""), price(0){
    cout << "[Base] конструктор по умолчанию\n";
}

Base::Base(const string& n, double p) : name(n), price(p) {
    cout << "[Base] конструктор с параметрами\n";
}

Base::Base(const Base& o) : name(o.name), price(o.price) {
    cout << "[Base] конструктор копирования\n";
}

Base::~Base() {
    cout << "[Base] деструктор\n";
}

void Base::setName(const string& n) {
    name = n;
}

void Base::setPrice(double p) {
    price = p;
}

Base& Base::operator=(const Base& o) {
    if (this != &o) {
        name = o.name;
        price = o.price;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Base& o) {
    o.print(os);
    return os;
}

istream& operator>>(istream& is, Base& o) {
    o.input(is);
    return is;
}