#pragma once
#include "Base.h"

class Keeper {
private:
    Base** items;
    int count;
    int cap;

    void reserve(int newCap);
public:
    Keeper();
    Keeper(const Keeper& o);
    ~Keeper();

    Keeper& operator=(const Keeper& o);

    int getCount() const { return count; }
    Base* getAt(int i) const;

    void add(Base* p);
    void remove(int i);
    void clear();

    void printAll(ostream& os) const;

    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};