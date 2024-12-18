#include "tabel.h"

void addAtribut(tabel& t, std::vector<std::string> namaAtribut) {
    for (size_t i = 0; i < namaAtribut.size(); i++) {
        t.kolom.push_back(kol{namaAtribut[i], {}, 0});

        if (namaAtribut[i].length() > t.kolom[i].lebar) {
            t.kolom[i].lebar = namaAtribut[i].length();
        }

        t.ukuran.kolom += (namaAtribut[i].length() + 3);
    }
    t.ukuran.kolom++;

    if (t.ukuran.baris == 0) {
        t.ukuran.baris = 3;
    }
}

void addRecord(tabel& t, std::vector<std::vector<std::variant<std::string, int>>> record) {
    unsigned short totalLebar = 0;
    for (size_t i = 0; i < record.size(); i++) {
        for (size_t j = 0; j < record[i].size() && j < t.kolom.size(); j++) {
            t.kolom[j].data.push_back(record[i][j]);

            unsigned short lebar;
            if (std::holds_alternative<std::string>(record[i][j])) {
                lebar = std::get<std::string>(record[i][j]).length();
            } else if (std::holds_alternative<int>(record[i][j])) {
                lebar = std::to_string(std::get<int>(record[i][j])).length();
            }

            t.kolom[j].lebar = std::max(lebar, t.kolom[j].lebar);
        }
        t.totalRecord++;

        t.ukuran.baris++;
    }
    t.ukuran.baris++;

    for (size_t i = 0; i < t.kolom.size(); i++) {
        totalLebar += (t.kolom[i].lebar + 3);
    }
    totalLebar++;
    t.ukuran.kolom = totalLebar;
}

void setPosisiTabel(tabel& t, koordinat posisi)
{
    t.posisi = posisi;
}

void printTabel(tabel t)
{
    koordinat currentPos = t.posisi;

    goToBarisKolom(currentPos.baris, currentPos.kolom);
    printf("\xDA");
    for (size_t i = 0; i < t.kolom.size(); i++) {
        for (unsigned short j = 0; j < t.kolom[i].lebar + 2; j++) {
            printf("\xC4");
        }
        if (i < t.kolom.size() - 1) {
            printf("\xC2");
        }
    }
    printf("\xBF");

    goToBarisKolom(currentPos.baris + 1, currentPos.kolom);
    printf("\xB3");
    for (size_t i = 0; i < t.kolom.size(); i++) {
        printf(" %-*s \xB3", t.kolom[i].lebar, t.kolom[i].namaAtribut.c_str());
    }
    printf("\n");

    goToBarisKolom(currentPos.baris + 2, currentPos.kolom);
    printf("\xC3");
    for (size_t i = 0; i < t.kolom.size(); i++) {
        for (unsigned short j = 0; j < t.kolom[i].lebar + 2; j++) {
            printf("\xC4");
        }
        if (i < t.kolom.size() - 1) {
            printf("\xC5");
        }
    }
    printf("\xB4");

    for (size_t i = 0; i < t.totalRecord; i++) {
        goToBarisKolom(currentPos.baris + 3 + i, currentPos.kolom);
        printf("\xB3");
        for (size_t j = 0; j < t.kolom.size(); j++) {
            std::string cellData = "";
            if (i < t.kolom[j].data.size()) {
                if (std::holds_alternative<std::string>(t.kolom[j].data[i])) {
                    cellData = std::get<std::string>(t.kolom[j].data[i]);
                } else if (std::holds_alternative<int>(t.kolom[j].data[i])) {
                    cellData = std::to_string(std::get<int>(t.kolom[j].data[i]));
                }
            }
            printf(" %-*s \xB3", t.kolom[j].lebar, cellData.c_str());
        }
    }

    goToBarisKolom(currentPos.baris + 3 + t.totalRecord, currentPos.kolom);
    printf("\xC0");
    for (size_t i = 0; i < t.kolom.size(); i++) {
        for (unsigned short j = 0; j < t.kolom[i].lebar + 2; j++) {
            printf("\xC4");
        }
        if (i < t.kolom.size() - 1) {
            printf("\xC1");
        }
    }
    printf("\xD9");
}

void highlightRecord(tabel t)
{
    goToBarisKolom(t.posisi.baris + 3 + t.recordTerpilih, t.posisi.kolom);
    printf("\033[30;47m");
    printf("\xB3");
    for (size_t i = 0; i < t.kolom.size(); i++) {
        std::string cellData = "";
        if (t.recordTerpilih < t.kolom[i].data.size()) {
            if (std::holds_alternative<std::string>(t.kolom[i].data[t.recordTerpilih])) {
                cellData = std::get<std::string>(t.kolom[i].data[t.recordTerpilih]);
            } else if (std::holds_alternative<int>(t.kolom[i].data[t.recordTerpilih])) {
                cellData = std::to_string(std::get<int>(t.kolom[i].data[t.recordTerpilih]));
            }
        }
        printf(" %-*s \xB3", t.kolom[i].lebar, cellData.c_str());
    }
    printf("\033[0m");
}

void unhighlightRecord(tabel t)
{
    goToBarisKolom(t.posisi.baris + 3 + t.recordTerpilih, t.posisi.kolom);
    printf("\xB3");
    for (size_t i = 0; i < t.kolom.size(); i++) {
        std::string cellData = "";
        if (t.recordTerpilih < t.kolom[i].data.size()) {
            if (std::holds_alternative<std::string>(t.kolom[i].data[t.recordTerpilih])) {
                cellData = std::get<std::string>(t.kolom[i].data[t.recordTerpilih]);
            } else if (std::holds_alternative<int>(t.kolom[i].data[t.recordTerpilih])) {
                cellData = std::to_string(std::get<int>(t.kolom[i].data[t.recordTerpilih]));
            }
        }
        printf(" %-*s \xB3", t.kolom[i].lebar, cellData.c_str());
    }
}

char displayTabel(tabel& t)
{
    char ch = 'x';
    if (t.totalRecord != 0) {
        printTabel(t);

        highlightRecord(t);

        size_t N = t.totalRecord;
        unsigned short i = 0;
        while (true) {
            if (_kbhit()){
                ch = _getch();
                if (ch == ESC || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == ENTER) {
                    return ch;
                } else if (ch == -32) {
                    ch = _getch();

                    switch (ch)
                    {
                        case DOWN: {
                            if (i < N - 1) {
                                unhighlightRecord(t);

                                i++;
                                t.recordTerpilih = i;

                                highlightRecord(t);
                            }
                            break;
                        }
                        case UP: {
                            if (i > 0) {  // Allow UP only if i is greater than 0
                                unhighlightRecord(t);

                                i--;
                                t.recordTerpilih = i;

                                highlightRecord(t);
                            }
                            break;
                        }
                        case RIGHT: {
                            return ch;
                        }
                        case LEFT: {
                            return ch;
                        }
                    }
                }
            }
        }
    } else {
        printTabel(t);
        while (true) {
            if (_kbhit()){
                ch = _getch();
                if (ch == ESC || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5') {
                    return ch;
                }
                switch (ch)
                {
                    case RIGHT: {
                        return ch;
                    }
                    case LEFT: {
                        return ch;
                    }
                }
            }
        }
    }
    return ch;
}

