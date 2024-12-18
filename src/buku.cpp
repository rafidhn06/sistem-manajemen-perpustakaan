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
        if (Next(B) != nullptr) {
            adrBuku P = First(LB);
            while (Next(Next(P)) != nullptr) {
                P = Next(P);
            }
            B = Next(P);
        } else {
            B = First(LB);
        }
    }
}

void deleteAfterBuku(listBuku& LB, adrBuku prec, adrBuku& B)
{
    B = Next(prec);
    if (Next(B) != nullptr) {
        Next(prec) = Next(B);
    }
}

void deleteBuku(listBuku& LB, adrBuku B)
{
    adrBuku temp = nullptr;
    if (First(LB) != B) {
        adrBuku P = First(LB);
        while (Next(Next(P)) != nullptr && Next(P) != B) {
            P = Next(P);
        }
        if (Next(P) == B) {
            deleteAfterBuku(LB, P, temp);
        }
        if (Next(Next(P)) == nullptr) {
            deleteLastBuku(LB, temp);
        }
    } else {
        deleteFirstBuku(LB, temp);
    }
    delete temp;
}


