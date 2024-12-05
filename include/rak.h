#ifndef RAK_H_INCLUDED
#define RAK_H_INCLUDED

#include <iostream>
#include "macro.h"
#include "buku.h"

struct rak {
    std::string id;
    std::string nama;
};
typedef struct rak infotype;

typedef elmRak* adrRak;
struct elmRak {
    infotype info;
    adrBuku nextAnak;
    adrRak next;
};
struct listRak {
    adrRak first;
    adrRak last;
};

void createRak(listRak& LR);
adrRak newElementRak(std::string idRak, std::string namaRak, int jumlahB);
void insertFirstRak(listRak& LR, adrRak R);
void insertLastRak(listRak& LR, adrRak R);
void showRak(listRak LR);
adrRak searchRak(listRak LR, std::string namaRak);
void hubungkanRakBuku(adrRak R, adrBuku B);
void showRakBuku(listRak LR);
void deleteFirstRak(listRak& LR, adrRak& R);
void deleteLastRak(listRak& LR, adrRak& R);
void deleteAfterRak(listRak& LR, adrRak prec, adrRak& R);
void deleteRak(listRak& LR, std::string idRak, std::string namaRak);
int totalBuku(listRak LR);

#endif // RAK_H_INCLUDED
