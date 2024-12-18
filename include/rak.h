#ifndef RAK_H_INCLUDED
#define RAK_H_INCLUDED

#include "buku.h"
#include <iostream>
#include <vector>
#include <variant>

struct rak {
    std::string id;
    std::string nama;
};
typedef struct rak infotypeRak;

typedef struct elmRak* adrRak;

struct elmRak {
    infotypeRak info;
    adrBuku nextAnak;
    adrRak next;
    adrRak prev;
};
struct listRak {
    adrRak first;
    adrRak last;
};

bool isEmpty(listRak LR);
void createListRak(listRak& LR);
adrRak newElementRak(infotypeRak r);
void insertFirstRak(listRak& LR, adrRak R);
void insertLastRak(listRak& LR, adrRak R);
adrRak searchRakById(listRak LR, std::string idrak);
adrRak searchRakByIdBuku(listRak LR, std::string idbuku);
void insertLastBukuByRak(adrRak& R, adrBuku B);
void hubungkanRakBuku(listRak& LR, listBuku LB);
void deleteFirstRak(listRak& LR, adrRak& R);
void deleteLastRak(listRak& LR, adrRak& R);
void deleteAfterRak(listRak& LR, adrRak prec, adrRak& R);
void deleteRak(listRak& LR, adrRak R);
void deleteBukuByRak(adrRak& R, adrBuku B);
int totalBuku(adrRak R);
std::vector<std::vector<std::variant<std::string, int>>> getRecordRak(listRak LR, unsigned short x);
std::vector<std::vector<std::variant<std::string, int>>> getRecordBuku(listRak LR, unsigned short x);
std::vector<std::vector<std::variant<std::string, int>>> getRecordBukuByRak(adrRak P, unsigned short x);
adrBuku getElmBukuSebelum(adrRak R, adrBuku B);
void pindahBuku(listRak& LR, adrRak& P, adrBuku& Q, buku b);
unsigned short hitungRak(listRak LR);
unsigned short totalBukuAll(listRak LR);
void editIdRakPadaBuku(adrRak P);

#endif // RAK_H_INCLUDED
