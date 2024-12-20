#include "filestream.h"
#include "macro.h"

void saveDataRak(listRak LR, std::string filename)
{
    std::ofstream outFile(filename);
    if (!outFile) {
        return;
    }

    adrRak P = First(LR);
    while (P != nullptr) {
        outFile
        << Info(P).id << ","
        << Info(P).nama << "\n";

        P = Next(P);
    }

    outFile.close();
}

void loadDataRak(listRak& LR, std::string filename)
{
    std::ifstream inFile(filename);
    if (!inFile) {
        return;
    }

    First(LR) = nullptr;
    std::string line;

    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        infotypeRak r;

        std::getline(iss, r.id, ',');
        std::getline(iss, r.nama, ',');

        adrRak P = newElementRak(r);
        insertLastRak(LR, P);
    }

    inFile.close();
}

void saveDataBuku(listRak LR, std::string filename)
{
    std::ofstream outFile(filename);
    if (!outFile) {
        return;
    }

    adrRak P = First(LR);
    while (P != nullptr) {
        adrBuku Q = First(listB(P));
        while (Q != nullptr) {
            outFile
            << Info(Q).id << ","
            << Info(Q).judul << ","
            << Info(Q).tahun << ","
            << Info(Q).penulis << ","
            << Info(Q).penerbit << ","
            << Info(Q).idRak << "\n";

            Q = Next(Q);
        }
        P = Next(P);
    }

    outFile.close();
}

void loadDataBuku(listBuku& LB, std::string filename)
{
    std::ifstream inFile(filename);
    if (!inFile) {
        return;
    }

    First(LB) = nullptr;
    std::string line;

    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        infotypeBuku b;

        std::getline(iss, b.id, ',');
        std::getline(iss, b.judul, ',');
        std::string tahunStr;
        std::getline(iss, tahunStr, ',');
        b.tahun = std::stoi(tahunStr);
        std::getline(iss, b.penulis, ',');
        std::getline(iss, b.penerbit, ',');
        std::getline(iss, b.idRak, ',');

        adrBuku P = newElementBuku(b);
        insertLastBuku(LB, P);
    }

    inFile.close();
}

