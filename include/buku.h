#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED

#include <iostream>
#include "macro.h"

struct buku {
    std::string id;
    std::string judul;
    int tahunTerbit;
    std::string penulis;
    std::string penerbit;
    std::string idRak;
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
adrBuku newElementBuku(std::string idBuku, std::string judulBuku, int tahunBuku, std::string penulisBuku, std::string penerbitBuku);
adrBuku searchBuku(listBuku& LB, std::string& judulBuku);
void insertLastBuku(listBuku& LB, adrBuku B);
void deleteFirstBuku(listBuku& LB, adrBuku& B);
void deleteLastBuku(listBuku& LB, adrBuku& B);
void deleteAfterBuku(listBuku& LB, adrBuku prec, adrBuku& B);
void deleteBuku(std::string idBuku, std::string judulBuku);

#endif // BUKU_H_INCLUDED
