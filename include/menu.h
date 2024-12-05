#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <vector>

struct menu {
    std::vector<std::string> opsi;
};

void printMenu(menu m);

void addOpsi(menu &m, std::string teksOpsi) {
    m.opsi.push_back(teksOpsi);
}

template<typename... T>
void addOpsi(menu& m, std::string teksOpsi, T... t) {
    m.opsi.push_back(teksOpsi);

    addOpsi(m, t...);
}

#endif // MENU_H_INCLUDED
