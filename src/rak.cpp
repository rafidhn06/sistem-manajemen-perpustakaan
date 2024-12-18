#include "rak.h"
#include "macro.h"

bool isEmpty(listRak LR){
    return First(LR) == nullptr;
}

void createListRak(listRak& LR){
    First(LR) = nullptr;
    Last(LR) = nullptr;
}

adrRak newElementRak(infotypeRak r){
    adrRak P = new elmRak;
    Info(P) = r;
    Next(P) = nullptr;
    Prev(P) = nullptr;
    NextAnak(P) = nullptr;
    return P;
}

void insertFirstRak(listRak& LR, adrRak R){
    if (isEmpty(LR)){
        Last(LR) = R;
    } else {
        Next(R) = First(LR);
        Prev(First(LR)) = R;
    }
    First(LR) = R;
}

void insertLastRak(listRak& LR, adrRak R){
    if (isEmpty(LR)){
        First(LR) = R;
    } else {
        Next(Last(LR)) = R;
        Prev(R) = Last(LR);
    }
    Last(LR) = R;
}

void hubungkanRakBuku(listRak& LR, listBuku LB)
{
    if (First(LR) != nullptr) {
        adrRak R = First(LR);

        while (R != nullptr) {
            //std::cout << "Processing Rak ID: " << Info(R).id << std::endl;
            if (First(LB) != nullptr) {
                adrBuku B = First(LB);

                while (B != nullptr) {
                    //std::cout << "Processing Buku ID: " << Info(B).id << std::endl;
                    if (Info(B).idRak == Info(R).id) {
                        //std::cout << "Memasukkan Buku dengan ID: " << Info(B).id << " Ke Rak dengan ID: " << Info(R).id << std::endl;
                        adrBuku P = newElementBuku(Info(B));

                        adrBuku Q = NextAnak(R);
                        if (NextAnak(R) != nullptr) {
                            while (Next(Q) != nullptr) {
                                Q = Next(Q);
                            }

                            Next(Q) = P;
                        } else {
                            NextAnak(R) = P;
                        }
                    }
                    B = Next(B);
                }
            }
            R = Next(R);
        }
    }
}

adrRak searchRakById(listRak LR, std::string idrak)
{
    adrRak P = First(LR);
    if (First(LR) != nullptr) {
        while (P != nullptr) {
            std::string idP = Info(P).id;
            if (idP == idrak) {
                return P;
            }
            P = Next(P);
        }
    }
    return P;
}

adrRak searchRakByIdBuku(listRak LR, std::string idbuku)
{
    adrRak P = First(LR);
    if (First(LR) != nullptr) {
        while (P != nullptr) {
            if (NextAnak(P) != nullptr) {
                adrBuku Q = NextAnak(P);
                while (Q != nullptr) {
                    std::string idQ = Info(Q).id;
                    if (idQ == idbuku) {
                        return P;
                    }
                    Q = Next(Q);
                }
            }
            P = Next(P);
        }
    }
    return P;
}

void insertLastBukuByRak(adrRak& R, adrBuku B)
{
    if (NextAnak(R) != nullptr) {
        adrBuku P = NextAnak(R);
        while (Next(P) != nullptr) {
            P = Next(P);
        }
        Next(P) = B;
    } else {
        NextAnak(R) = B;
    }
}

void deleteFirstRak(listRak& LR, adrRak& R){
    R = First(LR);
    if (R != nullptr){
        if (First(LR) == Last(LR)){
            First(LR) = nullptr;
            Last(LR) = nullptr;
        } else {
            First(LR) = Next(First(LR));
            Prev(First(LR)) = nullptr;
        }
    }
}

void deleteLastRak(listRak& LR, adrRak& R){
    R = Last(LR);
    if(First(LR) == Last(LR)){
        First(LR) = nullptr;
        Last(LR) = nullptr;
    } else {
        Last(LR) = Prev(Last(LR));
        Next(Last(LR)) = nullptr;
    }
    Prev(R) = Last(LR);
}

void deleteAfterRak(listRak& LR, adrRak prec, adrRak& R){
    R = Next(prec);
    Next(prec) = Next(R);
    if (Next(R) == nullptr){
        Last(LR) = prec;
    } else {
        Prev(Next(R)) = prec;
    }
    Next(R) = nullptr;
    Prev(R) = nullptr;
}

void deleteRak(listRak& LR, adrRak R){
    if (R != nullptr) {
        if (R == First(LR)){
            deleteFirstRak(LR, R);
        } else if (R == Last(LR)){
            deleteLastRak(LR, R);
        } else {
            adrRak prec = Prev(R);
            deleteAfterRak(LR, prec, R);
        }
    }
    delete R;
}

void deleteBukuByRak(adrRak& R, adrBuku B)
{
    adrBuku temp = nullptr;
    if (NextAnak(R) != B) {
        adrBuku P = NextAnak(R);
        while (Next(Next(P)) != nullptr && Next(P) != B) {
            P = Next(P);
        }
        if (Next(P) == B) {
            temp = Next(P);
            if (Next(temp) != nullptr) {
                Next(P) = Next(temp);
            } else {
                Next(P) = nullptr;
            }
        }
    } else {
        temp = NextAnak(R);
        if (Next(temp) != nullptr) {
            NextAnak(R) = Next(temp);
        } else {
            NextAnak(R) = nullptr;
        }
    }
    delete temp;
}

int totalBuku(adrRak R){
    adrBuku P = NextAnak(R);
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

unsigned short totalBukuAll(listRak LR)
{
    adrRak P = First(LR);
    unsigned short total = 0;

    if (P == nullptr){
        return total;
    } else {
        while (P != nullptr){
            adrBuku Q = NextAnak(P);
            while (Q != nullptr) {
                total++;
                Q = Next(Q);
            }
            P = Next(P);
        }
    }
    return total;
}

unsigned short hitungRak(listRak LR)
{
    adrRak P = First(LR);
    unsigned short total = 0;

    if (P == nullptr){
        return total;
    } else {
        while (P != nullptr){
            total++;
            P = Next(P);
        }
    }
    return total;
}

std::vector<std::vector<std::variant<std::string, int>>> getRecordRak(listRak LR, unsigned short x)
{
    std::vector<std::vector<std::variant<std::string, int>>> record;
    adrRak P = First(LR);

    unsigned short start = (x - 1) * 20;
    unsigned short end = x * 20;

    unsigned short i = 0;
    while (P != nullptr) {
        if (i >= start && i < end) {
            std::vector<std::variant<std::string, int>> nodeRecord = {
                Info(P).id,
                Info(P).nama,
                totalBuku(P)
            };

            record.push_back(nodeRecord);
        }

        if (i >= end) {
            break;
        }

        P = Next(P);
        i++;
    }

    return record;
}


std::vector<std::vector<std::variant<std::string, int>>> getRecordBuku(listRak LR, unsigned short x)
{
    std::vector<std::vector<std::variant<std::string, int>>> record;

    unsigned short i = 0;
    unsigned short start = (x - 1) * 20;
    unsigned short end = x * 20;

    adrRak P = First(LR);
    while (P != nullptr) {
        adrBuku Q = NextAnak(P);
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
            i++;

            if (i >= end) {
                return record;
            }

            Q = Next(Q);
        }
        P = Next(P);
    }

    return record;
}


std::vector<std::vector<std::variant<std::string, int>>> getRecordBukuByRak(adrRak P, unsigned short x)
{
    std::vector<std::vector<std::variant<std::string, int>>> record;

    unsigned short start = (x - 1) * 20;
    unsigned short end = x * 20;

    unsigned short i = 0;
    adrBuku Q = NextAnak(P);
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

adrBuku getElmBukuSebelum(adrRak R, adrBuku B)
{
    adrBuku P = NextAnak(R);
    while (P != nullptr) {
        if (Next(P) == B) {
            break;
        }
        P = Next(P);
    }
    return P;
}

void pindahBuku(listRak& LR, adrRak& P, adrBuku& Q, buku b)
{
    std::string idRakLama = Info(Q).idRak;
    if (P != nullptr) {
        if (NextAnak(P) != Q) {
            adrBuku R = getElmBukuSebelum(P, Q);
            if (R != nullptr) {
                if (Next(Q) != nullptr) {
                    Next(R) = Next(Q);
                } else {
                    Next(R) = nullptr;
                }
            }
        } else {
            if (Next(Q) != nullptr) {
                NextAnak(P) = Next(Q);
            } else {
                NextAnak(P) = nullptr;
            }
        }
    }

    Next(Q) = nullptr;

    adrRak S = searchRakById(LR, b.idRak);
    if (S == nullptr) {
        S = newElementRak({b.idRak, "Rak " + b.idRak});
        insertLastRak(LR, S);
    }

    insertLastBukuByRak(S, Q);

    Info(Q) = b;
}

void editIdRakPadaBuku(adrRak R) {
    adrBuku P = NextAnak(R);
    while (P != nullptr) {
        Info(P).idRak = Info(R).id;
        P = Next(P);
    }
}

