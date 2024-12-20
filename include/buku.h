#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED

#include <iostream>
#include <vector>
#include <variant>

struct buku {
    std::string id;
    std::string judul;
    int tahun;
    std::string penulis;
    std::string penerbit;
    std::string idRak;
};
typedef struct buku infotypeBuku;

typedef struct elmBuku* adrBuku;
struct elmBuku {
    infotypeBuku info;
    adrBuku next;
};
struct listBuku {
    adrBuku first;
};

void createListBuku(listBuku LB);
adrBuku newElementBuku(buku b);
adrBuku searchBuku(listBuku LB, std::string idBuku);
void insertLastBuku(listBuku& LB, adrBuku B);
void deleteFirstBuku(listBuku& LB, adrBuku& B);
void deleteLastBuku(listBuku& LB, adrBuku& B);
void deleteAfterBuku(listBuku& LB, adrBuku prec, adrBuku& B);
void deleteBuku(listBuku& LB, adrBuku B);
int totalBuku(listBuku LB);
std::vector<std::vector<std::variant<std::string, int>>> getRecordBukuInRak(listBuku LB, unsigned short x);
adrBuku getElmBukuSebelum(listBuku LB, adrBuku B);
#endif // BUKU_H_INCLUDED
