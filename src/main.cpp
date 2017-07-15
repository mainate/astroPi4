// xterm -font -*-fixed-*-*-*-ja-*-*-*-*-*-*-*-* -geometry 30x40 -T $TITLE -e
//-font -*-fixed-*-*-*-ja-*-*-*-*-*-*-*-* -geometry 30x40 -T $TITLE -e ~/Projects/build/astroPi4/bin/Debug/astroPi4
//-font -*-fixed-*-*-*-ja-*-*-*-*-*-*-*-* -geometry 30x40 -T $TITLE -e /usr/local/bin/astroPi4

#include "../include/astrocurses.h"
#include <iostream>

#include <cstdlib>

using namespace std;

int main()
{
    // Initialisation configurationXML for getting conf and save it
    extern configurationXML* configXML;
    configXML = new configurationXML(CONFIGXMLFILE);

    // Init input function
    //xy_t screenResolution = initProg();
    initProg();
    // create the named pipe if ddoesn't exist
//    initPipe();
    // Start application itself
    extern xy_t ncursesResolution;
    ncursesResolution = initCurses();
    //initCurses();
    // Initialisation of the display
    initScreen();

/*  For débuging info Have to stop the main thread to be readable
extern textWindow* mainWin;

    char a[32], b[32];
    sprintf(a,"Nbr colonne : %d", ncursesResolution.x);
    sprintf(b,"Nbr ligne   : %d", ncursesResolution.y);
    mainWin->writeline(2,  a, 2);
    mainWin->writeline(3, 0, b, 2);

    sprintf(a,"Nbr colonne : %d", screenResolution.x);
    sprintf(b,"Nbr ligne   : %d", screenResolution.y);
    mainWin->writeline(6, a, 2);
    mainWin->writeline(7, 0, b, 2);

    sprintf(a,"Nbr pix/char hor  : %d", screenResolution.x / COLS);
    sprintf(b,"Nbr pix/char vert : %d", screenResolution.y / LINES);
    mainWin->writeline(10,  a, 2);
    mainWin->writeline(11, 0, b, 2);

    wrefresh(mainWin->get_winContentInfo());
*/

extern textWindow* ipWin;

    scrollok(ipWin->get_winContentInfo(), false);

// extern objWindow* portWin;


extern buttonWindow* bottomWin;

    bottomWin->addButton("STOP", CONTINUE, 0, "indi", "server", &callBtnWinIndiServer);
    bottomWin->addButton("BRIGHTNESS", CONTINUE, 1, "bright", "ness", &callBtnBrigthness);
    bottomWin->addButton("SCREENCONF", CONTINUE, 2, "screen", "config", &callBtnWinScreenConfig);
    bottomWin->addButton("END", CONTINUE, 3, "", "quit", &callBtnWinLeaveProgram);

    resp_e response = mainLoop();
    releaseCurses();
    if (response == QUIT)
        return 0;
    if (response == SHUTDOWN)
#ifdef LAPTOP
        return 1;
#else
        if (system("sudo shutdown -h now") == 0)
            return 0;
#endif
    if (response == REBOOT)
#ifdef LAPTOP
        return 2;
#else
        if (system("sudo reboot") == 0)
            return 0;
#endif
nodelay(stdscr, false);
getch();
}

