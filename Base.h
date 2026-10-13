#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Base{
protected:
    string name;
    double price;
public:
    Base();
    Base(const string& name, double price);
    Base(const Base& other);
    virtual ~Base();

    string getName() const { return name; }
    double getPrice() const { return price; }
    void setName(const string& n);
    void setPrice(double p);

    virtual void input(istream& is) = 0;              
    virtual void print(ostream& os) const = 0;       
    virtual void save(ofstream& ofs) const = 0;       
    virtual void load(ifstream& ifs) = 0;           
    virtual int  getType() const = 0;                
    virtual Base* clone() const = 0;               

    Base& operator=(const Base& other);
};

ostream& operator<<(ostream& os, const Base& o);
istream& operator>>(istream& is, Base& o);