#ifndef TABEL_H_INCLUDED
#define TABEL_H_INCLUDED

#include "terminal.h"
#include <variant>
#include <vector>
#include <conio.h>

struct kol {
    std::string namaAtribut;
    std::vector<std::variant<std::string, int>> data;
    unsigned short lebar = 0;
};

struct tabel {
    std::vector<kol> kolom;
    koordinat posisi = {1, 1};
    koordinat ukuran = {0, 0};
    size_t totalRecord = 0;
    unsigned short recordTerpilih = 0;
};

void addAtribut(tabel& t, std::vector<std::string> namaAtribut);
void addRecord(tabel& t, std::vector<std::vector<std::variant<std::string, int>>> record);
void setPosisiTabel(tabel& t, koordinat posisi);
void highlightRecord(tabel t);
void unhighlightRecord(tabel t);
void printTabel(tabel t);
char displayTabel(tabel& t);

#endif // TABEL_H_INCLUDED
