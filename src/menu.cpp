#include "menu.h"

void addOpsi(menu& m, std::vector<std::string> teksOpsi)
{
    for (size_t i = 0; i < teksOpsi.size(); i++) {
        m.opsi.push_back(teksOpsi[i]);

        if (teksOpsi[i].size() > m.ukuran.kolom) {
            m.ukuran.kolom = teksOpsi[i].size();
        }
    }

    m.ukuran.baris = teksOpsi.size();
}

void setPosisiMenu(menu& m, koordinat posisi)
{
    m.posisi = posisi;
}

void highlightOpsi(menu m)
{
    goToBarisKolom(m.posisi.baris + m.opsiTerpilih, m.posisi.kolom);
    printf("\033[30;47m%-*s\033[0m", m.ukuran.kolom, m.opsi[m.opsiTerpilih].c_str());
}

void unhighlightOpsi(menu m) {
    goToBarisKolom(m.posisi.baris + m.opsiTerpilih, m.posisi.kolom);
    printf("%-*s", m.ukuran.kolom, m.opsi[m.opsiTerpilih].c_str());
}

void printMenu(menu m)
{
    for (size_t i = 0; i < m.opsi.size(); i++) {
        goToBarisKolom(m.posisi.baris + i, m.posisi.kolom);
        printf("%s", m.opsi[i].c_str());
    }
}

char displayMenu(menu& m) {
    char ch = 'x';
    if (m.opsi.size() != 0) {
        printMenu(m);

        highlightOpsi(m);

        size_t N = m.opsi.size();
        unsigned short i = 0;
        while (true) {
            if (_kbhit()) {
                ch = _getch();
                if (ch == ENTER || ch == ESC) {
                    break;
                } else if (ch == -32) {
                    ch = _getch();
                    switch (ch)
                    {
                        case DOWN: {
                            unhighlightOpsi(m);

                            i = (i + 1) % N;
                            m.opsiTerpilih = i;

                            highlightOpsi(m);
                            break;
                        }
                        case UP: {
                            unhighlightOpsi(m);

                            i = (i - 1 + N) % N;
                            m.opsiTerpilih = i;

                            highlightOpsi(m);
                            break;
                        }
                        case RIGHT: {
                            break;
                        }
                        case LEFT: {
                            break;
                        }
                    }
                }
            }
        }
    }
    return ch;
}
