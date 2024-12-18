#include "form.h"

void setPosisiForm(form& f, koordinat posisi)
{
    f.posisi = posisi;
}

void setFormTambahRak(form& f)
{
    f.ukuran.baris = 2;
    f.ukuran.kolom = 12;
    f.tambah = true;
}

void setFormEditRak(form& f, rak oldRak)
{
    f.ukuran.baris = 9;
    f.ukuran.kolom = 12;
    f.tambah = false;
    f.r = oldRak;
}

void setFormTambahBuku(form& f)
{
    f.ukuran.baris = 6;
    f.ukuran.kolom = 20;
    f.tambah = true;
}

void setFormEditBuku(form& f, buku oldBuku)
{
    f.ukuran.baris = 17;
    f.ukuran.kolom = 20;
    f.tambah = false;
    f.b = oldBuku;
}

rak displayFormRak(form& f)
{
    rak r;

    goToBarisKolom(f.posisi.baris, f.posisi.kolom);
    if (f.tambah == true) {
        printf("%-*s: ", 4, "ID");
        goToBarisKolom(f.posisi.baris + 1, f.posisi.kolom);
        printf("%-*s: ", 4, "Nama");

        goToBarisKolom(f.posisi.baris, f.posisi.kolom + 6);
        std::getline(std::cin, r.id);
        goToBarisKolom(f.posisi.baris + 1, f.posisi.kolom + 6);
        std::getline(std::cin, r.nama);
    } else {
        printf("Data Lama");
        goToBarisKolom(f.posisi.baris + 2, f.posisi.kolom);
        printf("%-*s: %s", 4, "ID", f.r.id.c_str());
        goToBarisKolom(f.posisi.baris + 3, f.posisi.kolom);
        printf("%-*s: %s", 4, "Nama", f.r.nama.c_str());
        goToBarisKolom(f.posisi.baris + 5, f.posisi.kolom);
        printf("Data Baru");
        goToBarisKolom(f.posisi.baris + 7, f.posisi.kolom);
        printf("%-*s: ", 4, "ID");
        goToBarisKolom(f.posisi.baris + 8, f.posisi.kolom);
        printf("%-*s: ", 4, "Nama");

        std::string inputStr = "";
        goToBarisKolom(f.posisi.baris + 7, f.posisi.kolom + 6);
        std::getline(std::cin, inputStr);
        r.id = inputStr;
        goToBarisKolom(f.posisi.baris + 8, f.posisi.kolom + 6);
        std::getline(std::cin, inputStr);
        r.nama = inputStr;
    }

    return r;
}

buku displayFormBuku(form& f)
{
    buku b;

    goToBarisKolom(f.posisi.baris, f.posisi.kolom);
    if (f.tambah == true) {
        printf("%-*s: ", 8, "ID");
        goToBarisKolom(f.posisi.baris + 1, f.posisi.kolom);
        printf("%-*s: ", 8, "Judul");
        goToBarisKolom(f.posisi.baris + 2, f.posisi.kolom);
        printf("%-*s: ", 8, "Tahun");
        goToBarisKolom(f.posisi.baris + 3, f.posisi.kolom);
        printf("%-*s: ", 8, "Penulis");
        goToBarisKolom(f.posisi.baris + 4, f.posisi.kolom);
        printf("%-*s: ", 8, "Penerbit");
        goToBarisKolom(f.posisi.baris + 5, f.posisi.kolom);
        printf("%-*s: ", 8, "ID Rak");

        goToBarisKolom(f.posisi.baris, f.posisi.kolom + 10);
        std::getline(std::cin, b.id);
        goToBarisKolom(f.posisi.baris + 1, f.posisi.kolom + 10);
        std::getline(std::cin, b.judul);
        goToBarisKolom(f.posisi.baris + 2, f.posisi.kolom + 10);
        b.tahun = inputInt();
        goToBarisKolom(f.posisi.baris + 3, f.posisi.kolom + 10);
        std::getline(std::cin, b.penulis);
        goToBarisKolom(f.posisi.baris + 4, f.posisi.kolom + 10);
        std::getline(std::cin, b.penerbit);
        goToBarisKolom(f.posisi.baris + 5, f.posisi.kolom + 10);
        std::getline(std::cin, b.idRak);

    } else {
        printf("Data Lama");
        goToBarisKolom(f.posisi.baris + 2, f.posisi.kolom);
        printf("%-*s: %s", 8, "ID", f.b.id.c_str());
        goToBarisKolom(f.posisi.baris + 3, f.posisi.kolom);
        printf("%-*s: %s", 8, "Judul", f.b.judul.c_str());
        goToBarisKolom(f.posisi.baris + 4, f.posisi.kolom);
        printf("%-*s: %d", 8, "Tahun", f.b.tahun);
        goToBarisKolom(f.posisi.baris + 5, f.posisi.kolom);
        printf("%-*s: %s", 8, "Penulis", f.b.penulis.c_str());
        goToBarisKolom(f.posisi.baris + 6, f.posisi.kolom);
        printf("%-*s: %s", 8, "Penerbit", f.b.penerbit.c_str());
        goToBarisKolom(f.posisi.baris + 7, f.posisi.kolom);
        printf("%-*s: %s", 8, "ID Rak", f.b.idRak.c_str());
        goToBarisKolom(f.posisi.baris + 9, f.posisi.kolom);
        printf("Data Baru");
        goToBarisKolom(f.posisi.baris + 11, f.posisi.kolom);
        printf("%-*s: ", 8, "ID");
        goToBarisKolom(f.posisi.baris + 12, f.posisi.kolom);
        printf("%-*s: ", 8, "Judul");
        goToBarisKolom(f.posisi.baris + 13, f.posisi.kolom);
        printf("%-*s: ", 8, "Tahun");
        goToBarisKolom(f.posisi.baris + 14, f.posisi.kolom);
        printf("%-*s: ", 8, "Penulis");
        goToBarisKolom(f.posisi.baris + 15, f.posisi.kolom);
        printf("%-*s: ", 8, "Penerbit");
        goToBarisKolom(f.posisi.baris + 16, f.posisi.kolom);
        printf("%-*s: ", 8, "ID Rak");

        std::string inputStr = "";
        int inputD = 0;

        goToBarisKolom(f.posisi.baris + 11, f.posisi.kolom + 10);
        std::getline(std::cin, inputStr);
        b.id = inputStr;
        goToBarisKolom(f.posisi.baris + 12, f.posisi.kolom + 10);
        std::getline(std::cin, inputStr);
        b.judul = inputStr;
        goToBarisKolom(f.posisi.baris + 13, f.posisi.kolom + 10);
        inputD = inputInt();
        b.tahun = inputD;
        goToBarisKolom(f.posisi.baris + 14, f.posisi.kolom + 10);
        std::getline(std::cin, inputStr);
        b.penulis = inputStr;
        goToBarisKolom(f.posisi.baris + 15, f.posisi.kolom + 10);
        std::getline(std::cin, inputStr);
        b.penerbit = inputStr;
        goToBarisKolom(f.posisi.baris + 16, f.posisi.kolom + 10);
        std::getline(std::cin, inputStr);
        b.idRak = inputStr;
    }

    return b;
}
