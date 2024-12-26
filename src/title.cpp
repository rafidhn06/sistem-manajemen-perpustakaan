#include "title.h"

void setPosisiTitle(title& T, koordinat posisi) {
    T.posisi = posisi;
}

void addTeksTitle(title& T, std::vector<std::string> teks) {
    unsigned short maxbaris = 0;
    unsigned short maxkolom = 0;
    for (size_t i = 0; i < teks.size(); i++) {
        T.teks.push_back(teks[i]);
        maxkolom = teks[i].length();
        maxbaris = teks.size();
    }
    if (maxkolom > T.ukuran.kolom) {
        T.ukuran.kolom = maxkolom;
    }
    if (maxbaris > T.ukuran.baris) {
        T.ukuran.baris = maxbaris;
    }
}

void displayTitle(title T) {
    for (size_t i = 0; i < T.teks.size(); i++) {
        goToBarisKolom(T.posisi.baris + i, T.posisi.kolom);
        printf("%s", T.teks[i].c_str());
    }
}

void displayTitleKeren() {
    printf("\033[?25l");
    char ch = 'x';
    unsigned short initial = 0;
    unsigned short nframe = 16;
    std::vector<std::vector<std::string>> teksAll;
    for (unsigned short i = initial; i < nframe; i++) {
        std::string filename = "frames\\" + std::to_string(i) + ".txt";

        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "Error: Failed to open file " << filename << "\n";
            std::cin.get();
            break;
        }

        std::string line;
        std::vector<std::string> teks;
        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            std::string temp;
            while (std::getline(iss, temp, '\n')) {
                teks.push_back(temp);
            }
        }
        teksAll.push_back(teks);
        inFile.close();
    }

    unsigned short i = 0;
    while (true) {
        title T;
        addTeksTitle(T, teksAll[i]);
        T.posisi = alignCenter(T.ukuran);
        displayTitle(T);

        i = (i + 1) % nframe;

        if (_kbhit()) {
            ch = _getch();
            if (ch == ENTER) {
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
    printf("\033[?25h");
}
