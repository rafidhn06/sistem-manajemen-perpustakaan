#ifndef FILESTREAM_H_INCLUDED
#define FILESTREAM_H_INCLUDED
#include "rak.h"
#include "buku.h"
#include <iostream>
#include <fstream>
#include <sstream>

void saveDataRak(listRak LR, std::string filename);
void loadDataRak(listRak& LR, std::string filename);
void saveDataBuku(listRak LR, std::string filename);
void loadDataBuku(listBuku& LB, std::string filename);

#endif // FILESTREAM_H_INCLUDED
