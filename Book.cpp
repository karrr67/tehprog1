#include "Book.h"

Book::Book() : Base(), author(""), annotation(""), genre(""), year(0), pages(0) {
    cout << "[Book] конструктор по умолчанию\n";
}

Book::Book(const Book& o)
    : Base(o), author(o.author), annotation(o.annotation),
      genre(o.genre), year(o.year), pages(o.pages) {
    cout << "[Book] конструктор копирования\n";
}

Book::~Book() {
    cout << "[Book] деструктор\n";
}

void Book::input(istream& is) {
    cout << "  название: "; getline(is, name);
    cout << "  автор: "; getline(is, author);
    cout << "  год: ";  is >> year;   is.ignore();
    cout << "  аннотация: "; getline(is, annotation);
    cout << "  жанр: "; getline(is, genre);
    cout << "  страниц: "; is >> pages;  is.ignore();
    cout << "  цена: "; is >> price;  is.ignore();
}

void Book::print(ostream& os) const {
    os << "Книга: " << name << "\n"
       << "автор: " << author << "\n"
       << "год: " << year << "\n"
       << "жанр: " << genre << "\n"
       << "страниц: " << pages << "\n"
       << "цена: " << price << "\n"
       << "аннотация: " << annotation << "\n";
}

void Book::save(ofstream& ofs) const {
    ofs << name << "\n"
        << price << "\n"
        << author << "\n"
        << year << "\n"
        << annotation << "\n"
        << genre << "\n"
        << pages << "\n";
}

void Book::load(ifstream& ifs) {
    getline(ifs, name);
    ifs >> price; ifs.ignore();
    getline(ifs, author);
    ifs >> year; ifs.ignore();
    getline(ifs, annotation);
    getline(ifs, genre);
    ifs >> pages; ifs.ignore();
}