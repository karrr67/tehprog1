#include "Textbook.h"

Textbook::Textbook()
    : Base(), author(""), institution(""), year(0), studyYear(0), pages(0) {
    cout << "[Textbook] конструктор по умолчанию\n";
}

Textbook::Textbook(const Textbook& o)
    : Base(o), author(o.author), institution(o.institution),
      year(o.year), studyYear(o.studyYear), pages(o.pages) {
    cout << "[Textbook] конструктор копирования\n";
}

Textbook::~Textbook() {
    cout << "[Textbook] деструктор\n";
}

void Textbook::input(istream& is) {
    cout << "  название: "; getline(is, name);
    cout << "  автор: "; getline(is, author);
    cout << "  год: ";  is >> year;   is.ignore();
    cout << "  заведение: "; getline(is, institution);
    cout << "  год обучения: "; is >> studyYear; is.ignore();
    cout << "  страниц: "; is >> pages;   is.ignore();
    cout << "  цена: "; is >> price;  is.ignore();
}

void Textbook::print(ostream& os) const {
    os << "Учебник: " << name << "\n"
       << "автор: " << author << "\n"
       << "год: " << year << "\n"
       << "заведение: " << institution << "\n"
       << "год обучения: " << studyYear << "\n"
       << "страниц: " << pages << "\n"
       << "цена: " << price << "\n";
}

void Textbook::save(ofstream& ofs) const {
    ofs << name << "\n"
        << price << "\n"
        << author << "\n"
        << year << "\n"
        << institution << "\n"
        << studyYear << "\n"
        << pages << "\n";
}

void Textbook::load(ifstream& ifs) {
    getline(ifs, name);
    ifs >> price; ifs.ignore();
    getline(ifs, author);
    ifs >> year; ifs.ignore();
    getline(ifs, institution);
    ifs >> studyYear; ifs.ignore();
    ifs >> pages; ifs.ignore();
}