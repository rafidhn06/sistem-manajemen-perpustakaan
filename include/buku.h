#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED

#include "macro.h"

struct buku {
    string id;
    string judul;
    int tahunTerbit;
    string penulis;
    string penerbit;
    string idRak;
};
typedef struct buku infotype;

typedef struct elmBuku* adrBuku;
struct elmBuku {
    infotype info;
    adrBuku next;
};
typedef adrBuku *elmBuku;
struct listBuku {
    adrBuku first;
};

void createBuku(listBuku LB);
adrBuku newElementBuku(string idBuku, string judulBuku, int tahunBuku, string penulisBuku, string penerbitBuku);
adrBuku searchBuku(listBuku& LB, string& judulBuku);
void insertLastBuku(listBuku& LB, adrBuku B);
void deleteFirstBuku(listBuku& LB, adrBuku& B);
void deleteLastBuku(listBuku& LB, adrBuku& B);
void deleteAfterBuku(listBuku& LB, adrBuku prec, adrBuku& B);
void deleteBuku(string idBuku, string judulBuku);

#endif // BUKU_H_INCLUDED
