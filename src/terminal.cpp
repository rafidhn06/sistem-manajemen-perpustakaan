#include "terminal.h"

void highlight(std::string teks)
{
    printf("\033[30;47m%s\033[0m", teks.c_str());
}

void goToBarisKolom(unsigned short baris, unsigned short kolom)
{
    printf("\033[%u;%uH", baris, kolom);
}

koordinat getCenter()
{
    koordinat koord;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        koord.kolom = (csbi.srWindow.Right - csbi.srWindow.Left + 1) / 2;
        koord.baris = (csbi.srWindow.Bottom - csbi.srWindow.Top + 1) / 2;
    }

    return koord;
}

koordinat alignCenter(koordinat ukuranOutput)
{
    koordinat center = getCenter();

    koordinat align = {0, 0};
    align.baris = center.baris - ukuranOutput.baris / 2;
    align.kolom = center.kolom - ukuranOutput.kolom / 2;

    return align;
}

void clearScreen()
{
    system("cls");
}

int inputInt()
{
    int a;
    std::string line;
    std::istringstream tmp( line );
    tmp >> a >> std::ws;


    return a;
}
