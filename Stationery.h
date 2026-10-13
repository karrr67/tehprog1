#pragma once
#include "Base.h"

class Stationery : public Base {
private:
    string color;
    string purpose;
public:
    Stationery();
    Stationery(const Stationery& o);
    ~Stationery();

    string getColor() const { return color; }
    string getPurpose() const { return purpose; }

    void setColor(const string& c) { color = c; }
    void setPurpose(const string& p) { purpose = p; }

    void input(istream& is) override;
    void print(ostream& os) const override;
    void save(ofstream& ofs) const override;
    void load(ifstream& ifs) override;
    int getType() const override { return 3; }
    Base* clone() const override { return new Stationery(*this); }
};