#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED
#define ESC 27
#define ENTER 13
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define MAXBARIS 30
#define MAXKOLOM 120
// ATASL \xDA
//BAWAHL \xC0
//ATASR \xBF
//BAWAHR \xD9
//VERT \xB3
//HORZ \xC4
//SPAC \xFF
#include <iostream>
#include <sstream>
#include <windows.h>

struct koordinat {
    unsigned short baris;
    unsigned short kolom;
};

void highlight(std::string teks);
void goToBarisKolom(unsigned short baris, unsigned short kolom);
koordinat getCenter();
koordinat alignCenter(koordinat ukuranOutput);
void clearScreen();
int inputInt();

#endif // TERMINAL_H_INCLUDED
