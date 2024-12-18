#include "title.h"

void setPosisiTitle(title& T, koordinat posisi) {
    T.posisi = posisi;
}

void addTeksTitle(title& T, std::vector<std::string> teks) {
    unsigned short maxlebar = 0;
    for (size_t i = 0; i < teks.size(); i++) {
        T.teks.push_back(teks[i]);
        maxlebar += teks[i].length();
        T.ukuran.baris++;  // Assuming T.ukuran.baris is the row count
    }
    if (maxlebar > T.ukuran.kolom) {
        T.ukuran.kolom = maxlebar;  // Update max width if necessary
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
    unsigned short i = 0;
    unsigned short nframe = 16;

    while (true) {
        std::string filename = "frames\\" + std::to_string(i) + ".txt";

        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "Error: Failed to open file " << filename << "\n";
            std::cin.get();
            break;
        }

        title T;
        std::string line;
        std::vector<std::string> teks;
        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            std::string temp;
            while (std::getline(iss, temp, '\n')) {
                teks.push_back(temp);
            }
        }

        addTeksTitle(T, teks);
        T.posisi = {MAXBARIS/2 - 26/2, MAXKOLOM/2 - 91/2};
        displayTitle(T);

        i = (i + 1) % nframe;

        if (_kbhit()) {
            ch = _getch();
            if (ch == ENTER) {
                break;
            }
        }
        inFile.close();
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
    printf("\033[?25h");
}

void displayTitleSerius()
{
    title T;
    addTeksTitle(T, {
                 " █▀▀ ▀█▀ █▀▀ ▀█▀ █▀▀ █▄█   █▄█ █▀█ █▀█ █▀█ ▀▀█ █▀▀ █▄█ █▀▀ █▀█ ",
                 " ▀▀█  █  ▀▀█  █  █▀▀ █ █   █ █ █▀█ █ █ █▀█   █ █▀▀ █ █ █▀▀ █ █ ",
                 " ▀▀▀ ▀▀▀ ▀▀▀  ▀  ▀▀▀ ▀ ▀   ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀▀  ▀▀▀ ▀ ▀ ▀▀▀ ▀ ▀ ",
                 "       █▀█ █▀▀ █▀▄ █▀█ █ █ █▀▀ ▀█▀ █▀█ █ █ █▀█ █▀█ █▀█         ",
                 "       █▀▀ █▀▀ █▀▄ █▀▀ █ █ ▀▀█  █  █▀█ █▀▄ █▀█ █▀█ █ █         ",
                 "       ▀   ▀▀▀ ▀ ▀ ▀   ▀▀▀ ▀▀▀  ▀  ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀         "
                 });
    setPosisiTitle(T, {5, 30});
    displayTitle(T);
}
