#include "buku.h"
#include "rak.h"
#include "tabel.h"
#include "menu.h"
#include "form.h"
#include "filestream.h"
#include "macro.h"
#include "title.h"
#include <iostream>

void setMenuUtama(menu& m)
{
    addOpsi(m, {"1. Data Rak", "2. Data Buku", "3. Simpan", "4. Keluar"});
    setPosisiMenu(m, alignCenter(m.ukuran));
}

void setTabelRak(tabel& t, listRak LR, unsigned short x)
{
    addAtribut(t, {"ID", "Nama", "Jumlah Buku"});
    addRecord(t, getRecordRak(LR, x));
    setPosisiTabel(t, alignCenter(t.ukuran));
    printf("\033[%u;%uH%s\033[1B\033[%uG%s\033[1B\033[%uG%s\033[1B\033[%uG%s\033[1B\033[%uG%s\033[1B\033[%uG%s\033[1B\033[%uG%s", t.posisi.baris + 3, t.posisi.kolom + t.ukuran.kolom + 5,
                            "1. Insert First", t.posisi.kolom + t.ukuran.kolom + 5,
                            "2. Insert Last", t.posisi.kolom + t.ukuran.kolom + 5,
                            "3. Edit", t.posisi.kolom + t.ukuran.kolom + 5,
                            "4. Delete\n", t.posisi.kolom + t.ukuran.kolom + 5,
                            "Enter Lihat Buku", t.posisi.kolom + t.ukuran.kolom + 5,
                            "->    Next",  t.posisi.kolom + t.ukuran.kolom + 5,
                            "<-    Previous");
}

void setTabelBuku(tabel& t, listRak LR, unsigned short x)
{
    addAtribut(t, {"ID","Judul","Tahun","Penulis","Penerbit","ID Rak"});
    addRecord(t, getRecordBuku(LR, x));
    setPosisiTabel(t, alignCenter(t.ukuran));
    printf("\033[%u;%uH%-15s%-15s%-15s%-15s%-15s", t.posisi.baris + t.ukuran.baris + 1, t.posisi.kolom + 1,
            "1. Insert",
            "2. Edit",
            "3. Delete",
            "-> Next",
            "<- Previous");
}

void setTabelBukuInRak(tabel& t, adrRak R, unsigned short x)
{
    addAtribut(t, {"ID","Judul","Tahun","Penulis","Penerbit","ID Rak"});
    addRecord(t, getRecordBukuInRak(listB(R), x));
    setPosisiTabel(t, alignCenter(t.ukuran));
    printf("\033[%u;%uH%-15s%-15s%-15s%-15s%-15s", t.posisi.baris + t.ukuran.baris + 1, t.posisi.kolom + 1,
            "1. Insert",
            "2. Edit",
            "3. Delete",
            "-> Next",
            "<- Previous");
}

void sFormTambahBuku(form& f)
{
    setFormTambahBuku(f);
    setPosisiForm(f, alignCenter(f.ukuran));
}

adrBuku searchBukuInRakByRecordTerpilih(adrRak R, tabel t)
{
    short unsigned counter = 0;
    adrBuku P = First(listB(R));
    while (P != nullptr) {
        if (counter == t.recordTerpilih) {
            break;
        }
        P = Next(P);
        counter++;
    }
    return P;
}

void sFormEditBuku(form& f, adrBuku B)
{
    setFormEditBuku(f, Info(B));
    setPosisiForm(f, alignCenter(f.ukuran));
}

void sFormTambahRak(form& f)
{
    setFormTambahRak(f);
    setPosisiForm(f, alignCenter(f.ukuran));
}

adrRak searchRakByRecordTerpilih(listRak LR, tabel t)
{
    short unsigned counter = 0;
    adrRak P = First(LR);
    while (P != nullptr) {
        if (counter == t.recordTerpilih) {
            break;
        }
        P = Next(P);
        counter++;
    }
    return P;
}

void sFormEditRak(form& f, adrRak R)
{
    setFormEditRak(f, Info(R));
    setPosisiForm(f, alignCenter(f.ukuran));
}

adrBuku searchBukuByRecordTerpilih(listRak LR, tabel t)
{
    unsigned short counter = 0;
    adrRak P = First(LR);
    adrBuku Q = nullptr;
    while (P != nullptr) {
        Q = First(listB(P));
        while (Q != nullptr) {
            if (counter == t.recordTerpilih) {
                return Q;
            }
            Q = Next(Q);
            counter++;
        }
        P = Next(P);
    }
    return Q;
}

int main()
{
    clearScreen();
    displayTitleKeren();

    listRak LR;
    createListRak(LR);
    listBuku LB;
    createListBuku(LB);

    loadDataRak(LR, "dataRak.txt");
    loadDataBuku(LB, "dataBuku.txt");

    hubungkanRakBuku(LR, LB);

    char inputKeyboard1 = 'x';
    while (true) {
        clearScreen();

        menu m;
        setMenuUtama(m);
        inputKeyboard1 = displayMenu(m);

        if (inputKeyboard1 == ESC || m.opsiTerpilih == 3) {
            break;
        }
        switch (m.opsiTerpilih)
        {
            case 0: {
                char inputKeyboard2 = 'x';
                unsigned short i = 1;
                while (true) {
                    clearScreen();
                    tabel t;
                    setTabelRak(t, LR, i);
                    inputKeyboard2 = displayTabel(t);
                    t.recordTerpilih = (i - 1) * 20 + t.recordTerpilih;

                    if (inputKeyboard2 == ESC) {
                        break;
                    }

                    switch (inputKeyboard2)
                    {
                        case '1': {
                            clearScreen();
                            form f;
                            sFormTambahRak(f);
                            rak r = displayFormRak(f);

                            adrRak P = newElementRak(r);
                            insertFirstRak(LR, P);
                            break;
                        }
                        case '2': {
                            clearScreen();
                            form f;
                            sFormTambahRak(f);
                            rak r = displayFormRak(f);

                            adrRak P = newElementRak(r);
                            insertLastRak(LR, P);
                            break;
                        }
                        case '3': {
                            clearScreen();
                            form f;
                            adrRak P = searchRakByRecordTerpilih(LR, t);
                            sFormEditRak(f, P);
                            rak r = displayFormRak(f);

                            std::string idRakLama = Info(P).id;
                            Info(P) = r;
                            if (r.id != idRakLama) {
                                editIdRakPadaBuku(P);
                            }
                            break;
                        }
                        case '4': {
                            if (t.totalRecord == 0) {
                                break;
                            }
                            clearScreen();
                            adrRak P = searchRakByRecordTerpilih(LR, t);

                            deleteRak(LR, P);
                            break;
                        }
                        case ENTER: {
                            char inputKeyboard3 = 'x';
                            unsigned short j = 1;
                            while (true) {
                                clearScreen();

                                tabel tBuku;
                                adrRak P = searchRakByRecordTerpilih(LR, t);
                                setTabelBukuInRak(tBuku, P, j);
                                inputKeyboard3 = displayTabel(tBuku);

                                if (inputKeyboard3 == ESC) {
                                    break;
                                }

                                tBuku.recordTerpilih = (j - 1) * 20 + tBuku.recordTerpilih;

                                switch (inputKeyboard3)
                                {
                                    case '1': {
                                        clearScreen();
                                        form f;
                                        sFormTambahBuku(f);
                                        buku b = displayFormBuku(f);

                                        adrRak Q = searchRakById(LR, b.idRak);
                                        adrBuku S = newElementBuku(b);
                                        if (Q == nullptr) {
                                            adrRak R = newElementRak({b.idRak, "Rak " + b.idRak});
                                            insertLastRak(LR, R);
                                            insertLastBuku(listB(R), S);
                                        } else {
                                            insertLastBuku(listB(Q), S);
                                        }
                                        break;
                                    }
                                    case '2': {
                                        if (First(listB(P)) == nullptr) {
                                            break;
                                        }

                                        clearScreen();

                                        form f;
                                        adrBuku Q = searchBukuInRakByRecordTerpilih(P, tBuku);
                                        sFormEditBuku(f, Q);
                                        buku b = displayFormBuku(f);

                                        pindahBuku(LR, P, Q, b);
                                        break;
                                    }
                                    case '3': {
                                        if (tBuku.totalRecord == 0) {
                                            break;
                                        }

                                        adrBuku Q = searchBukuInRakByRecordTerpilih(P, tBuku);
                                        adrRak R = searchRakById(LR, Info(Q).idRak);

                                        deleteBuku(listB(R), Q);
                                        break;
                                    }
                                    case LEFT: {
                                        if (j > 1) {
                                            j--;
                                        }
                                        break;
                                    }
                                    case RIGHT: {
                                        if (j <= (totalBuku(listB(P)) - 1) / 20) {
                                            j++;
                                        }
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case LEFT: {
                            if (i > 1) {
                                i--;
                            }
                            break;
                        }
                        case RIGHT: {
                            if (i <= (hitungRak(LR) - 1) / 20) {
                                i++;
                            }
                            break;
                        }

                    }
                }
                break;
            }
            case 1: {
                char inputKeyboard2 = 'x';
                unsigned short i = 1;
                while (true) {
                    clearScreen();
                    tabel t;
                    setTabelBuku(t, LR, i);
                    inputKeyboard2 = displayTabel(t);

                    if (inputKeyboard2 == ESC) {
                        break;
                    }

                    t.recordTerpilih = (i - 1) * 20 + t.recordTerpilih;

                    switch (inputKeyboard2)
                    {
                        case '1': {
                            clearScreen();
                            form f;
                            sFormTambahBuku(f);
                            buku b = displayFormBuku(f);

                            adrRak P = searchRakById(LR, b.idRak);
                            adrBuku Q = newElementBuku(b);
                            if (P == nullptr) {
                                adrRak R = newElementRak({b.idRak, "Rak " + b.idRak});
                                insertLastRak(LR, R);
                                First(listB(R)) = Q;
                            } else {
                                insertLastBuku(listB(P), Q);
                            }
                            break;
                        }
                        case '2': {
                            clearScreen();

                            form f;
                            adrBuku P = searchBukuByRecordTerpilih(LR, t);
                            sFormEditBuku(f, P);
                            buku b = displayFormBuku(f);

                            std::string idRakLama = Info(P).idRak;
                            adrRak R = searchRakById(LR, idRakLama);
                            pindahBuku(LR, R, P, b);
                            break;
                        }
                        case '3': {
                            if (t.totalRecord == 0) {
                                break;
                            }

                            adrBuku P = searchBukuByRecordTerpilih(LR, t);
                            adrRak Q = searchRakById(LR, Info(P).idRak);

                            deleteBuku(listB(Q), P);
                            break;
                        }
                        case LEFT: {
                            if (i > 1) {
                                i--;
                            }
                            break;
                        }
                        case RIGHT: {
                            if (i <= (totalBukuAll(LR) - 1) / 20) {
                                i++;
                            }
                            break;
                        }
                    }
                }
                break;
            }
            case 2: {
                saveDataRak(LR, "dataRak.txt");
                saveDataBuku(LR, "dataBuku.txt");
                break;
            }
        }
    }
    clearScreen();
}
