#ifndef TABEL_H_INCLUDED
#define TABEL_H_INCLUDED

#include <iostream>
#include <vector>
#include <variant>

typedef std::variant<int, double, std::string> sel;
struct tabel {
    std::vector<std::string> atribut;
    std::vector<std::vector<sel>> record;
};

template <typename... Args>
void addAtribut(tabel& t, Args... args) {
    (t.atribut.push_back(args),...);
}

void addRecord(tabel& t, std::vector<std::vector<sel>> record) {
    for (size_t i = 0; i < record.size(); i++) {
        if (record[i].size() != t.atribut.size()) {
            throw std::invalid_argument("Panjang record tidak sesuai dengan banyak atribut");
        }
        t.record.push_back(record[i]);
    }
}

#endif // TABEL_H_INCLUDED
