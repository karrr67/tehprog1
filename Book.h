#pragma once
#include "Base.h"

class Book : public Base {
private:
    string author;
    string annotation;
    string genre;
    int year;
    int pages;
public:
    Book();
    Book(const Book& o);
    ~Book();

    string getAuthor() const { return author; }
    string getAnnotation() const { return annotation; }
    string getGenre() const { return genre; }
    int getYear() const { return year; }
    int getPages() const { return pages; }

    void setAuthor(const string& a) { author = a; }
    void setAnnotation(const string& a) { annotation = a; }
    void setGenre(const string& g) { genre = g; }
    void setYear(int y) { year = y; }
    void setPages(int p) { pages = p; }

    void input(istream& is) override;
    void print(ostream& os) const override;
    void save(ofstream& ofs) const override;
    void load(ifstream& ifs) override;
    int getType() const override { return 1; }
    Base* clone() const override { return new Book(*this); }
};