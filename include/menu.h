#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <vector>
#include <conio.h>
#include "terminal.h"

struct menu {
    std::vector<std::string> opsi;
    koordinat posisi = {1, 1};
    koordinat ukuran = {0, 0};
    unsigned short opsiTerpilih = 0;
};

void addOpsi(menu& m, std::vector<std::string> teksOpsi);
void setPosisiMenu(menu& m, koordinat);
void highlightOpsi(menu m);
void unhighlightOpsi(menu m);
void printMenu(menu m);
char displayMenu(menu& m);

#endif // MENU_H_INCLUDED
