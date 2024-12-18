#ifndef TITLE_H_INCLUDED
#define TITLE_H_INCLUDED
#include <vector>
#include <conio.h>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
#include "terminal.h"

struct title {
    koordinat posisi = {1, 1};
    koordinat ukuran = {0, 0};
    std::vector<std::string> teks;
};

void setPosisiTitle(title& T, koordinat posisi);
void addTeksTitle(title& T, std::vector<std::string> teks);
void displayTitle(title T);
void displayTitleKeren();
void displayTitleSerius();
#endif // TITLE_H_INCLUDED
