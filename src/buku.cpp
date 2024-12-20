#include "buku.h"
#include "macro.h"

void createListBuku(listBuku LB)
{
    First(LB) = nullptr;
}

adrBuku newElementBuku(buku b)
{
    adrBuku P = new elmBuku;
    Info(P) = b;
    Next(P) = nullptr;

    return P;
}

adrBuku searchBuku(listBuku LB, std::string idBuku)
{
    adrBuku P = First(LB);
    while (P != nullptr) {
        std::string id = Info(P).id;
        if (id == idBuku) {
            break;
        }
        P = Next(P);
    }
    return P;
}

void insertLastBuku(listBuku& LB, adrBuku B)
{
    if (First(LB) != nullptr) {
        adrBuku P = First(LB);
        while (Next(P) != nullptr) {
            P = Next(P);
        }
        Next(P) = B;
    } else {
        First(LB) = B;
    }
}

void deleteFirstBuku(listBuku& LB, adrBuku& B)
{
    B = First(LB);
    if (First(LB) != nullptr) {
        if (Next(B) != nullptr) {
            First(LB) = Next(B);
        } else {
            First(LB) = nullptr;
        }
    }
}

void deleteLastBuku(listBuku& LB, adrBuku& B)
{
    if (First(LB) != nullptr) {
        if (Next(First(LB)) != nullptr) {
            adrBuku P = First(LB);
            while (Next(Next(P)) != nullptr) {
                P = Next(P);
            }
            B = Next(P);
            Next(P) = nullptr;
        } else {
            B = First(LB);
        }
    }
}

void deleteAfterBuku(listBuku& LB, adrBuku prec, adrBuku& B)
{
    B = Next(prec);
    Next(prec) = Next(B);
}

void deleteBuku(listBuku& LB, adrBuku B)
{
    adrBuku temp = nullptr;
    if (First(LB) != B) {
        adrBuku P = searchBuku(LB, Info(B).id);
        if (P != nullptr) {
            if (Next(P) != nullptr) {
                deleteAfterBuku(LB, getElmBukuSebelum(LB, P), temp);
            } else {
                deleteLastBuku(LB, temp);
            }
        }
    } else {
        deleteFirstBuku(LB, temp);
    }
    delete temp;
}

int totalBuku(listBuku LB){
    adrBuku P = First(LB);
    int total = 0;

    if (P == nullptr){
        return total = 0;
    } else {
        while (P != nullptr){
            total++;
            P = Next(P);
        }
    }
    return total;
}

std::vector<std::vector<std::variant<std::string, int>>> getRecordBukuInRak(listBuku LB, unsigned short x)
{
    std::vector<std::vector<std::variant<std::string, int>>> record;

    unsigned short start = (x - 1) * 20;
    unsigned short end = x * 20;

    unsigned short i = 0;
    adrBuku Q = First(LB);
    while (Q != nullptr) {
        if (i >= start && i < end) {
            std::vector<std::variant<std::string, int>> nodeRecord = {
                Info(Q).id,
                Info(Q).judul,
                Info(Q).tahun,
                Info(Q).penulis,
                Info(Q).penerbit,
                Info(Q).idRak
            };

            record.push_back(nodeRecord);
        }

        if (i >= end) {
            break;
        }

        Q = Next(Q);
        i++;
    }

    return record;
}

adrBuku getElmBukuSebelum(listBuku LB, adrBuku B)
{
    adrBuku P = First(LB);
    while (P != nullptr) {
        if (Next(P) == B) {
            break;
        }
        P = Next(P);
    }
    return P;
}


