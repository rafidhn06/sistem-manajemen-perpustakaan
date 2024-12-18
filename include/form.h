#ifndef FORM_H_INCLUDED
#define FORM_H_INCLUDED
#include "terminal.h"
#include "rak.h"
#include "buku.h"
#include <conio.h>
#include <iostream>

struct form {
    koordinat posisi = {1, 1};
    koordinat ukuran = {0, 0};
    bool tambah;
    rak r;
    buku b;
};

void setPosisiForm(form& f, koordinat posisi);
void setFormTambahRak(form& f);
void setFormEditRak(form& f, rak oldRak);
void setFormTambahBuku(form& f);
void setFormEditBuku(form& f, buku oldBuku);
rak displayFormRak(form& f);
buku displayFormBuku(form& f);


#endif // FORM_H_INCLUDED
