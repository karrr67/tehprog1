#pragma once
#include "Base.h"

class Textbook : public Base {
private:
    string author;
    string institution;
    int year;
    int studyYear;
    int pages;
public:
    Textbook();
    Textbook(const Textbook& o);
    ~Textbook();

    string getAuthor() const { return author; }
    string getInstitution() const { return institution; }
    int getYear() const { return year; }
    int getStudyYear() const { return studyYear; }
    int getPages() const { return pages; }

    void setAuthor(const string& a) { author = a; }
    void setInstitution(const string& i) { institution = i; }
    void setYear(int y) { year = y; }
    void setStudyYear(int y) { studyYear = y; }
    void setPages(int p) { pages = p; }

    void input(istream& is) override;
    void print(ostream& os) const override;
    void save(ofstream& ofs) const override;
    void load(ifstream& ifs) override;
    int getType() const override { return 2; }
    Base* clone() const override { return new Textbook(*this); }
};