#include <stdio.h>
// _getch()ŠÖ”‚ğg—p‚·‚é‚½‚ß‚ÌŠO•”ƒ‰ƒCƒuƒ‰ƒŠ
#include <conio.h>
// system()ŠÖ”‚ğg—p‚·‚é‚½‚ß‚Ì•W€ƒ‰ƒCƒuƒ‰ƒŠ
#include <windows.h>
// exit()ŠÖ”‚ğg—p‚·‚é‚½‚ß‚ÌŠO•”ƒ‰ƒCƒuƒ‰ƒŠ
#include <stdlib.h>

void keyboard_input(int, int, int *);
void display_transition(int);

// ä»–ãƒ•ã‚¡ã‚¤ãƒ«ã§ä½¿ç”¨ã—ã¦ã?ã‚‹é–¢æ•°ã®ãƒ—ãƒ­ãƒˆã‚¿ã‚¤ãƒ—å®£è¨€
#include "joint.h"

int main(void) {
    // Œ»İ‚Ì‘I‘ğ‰æ–Ê‚ğ”»•Ê‚·‚é‚½‚ß‚Ì¯•ÊƒR[ƒh
    int currentStateNum = 4;

    // ƒRƒ}ƒ“ƒhƒvƒƒ“ƒvƒg‚ÌƒRƒ}ƒ“ƒh“™‚Ì—š—ğ‚ğ‚·‚×‚ÄÁ‹‚·‚éƒVƒFƒ‹ƒRƒ}ƒ“ƒh
    // æ–?å­—ã‚³ãƒ¼ãƒ‰ã‚’utf8ã«å¤‰æ›´ã™ã‚‹ã‚·ã‚§ãƒ«ã‚³ãƒãƒ³ãƒ?
    system("chcp 65001");

    // ã‚³ãƒãƒ³ãƒ‰ã?—ãƒ­ãƒ³ãƒ—ãƒˆã®ã‚³ãƒãƒ³ãƒ‰ç­‰ã?®å±¥æ­´ã‚’ã™ã¹ã¦æ¶ˆå»ã™ã‚‹ã‚·ã‚§ãƒ«ã‚³ãƒãƒ³ãƒ?
    system("cls");

    display_transition(currentStateNum);

    while(1) {
        // “ü—Í‚µ‚½ƒL[ƒ{[ƒh‚Ì•¶š‚ğ”F¯‚·‚éŠÖ”‚Å16i”‚Å”F¯‚µ‚Ä‚¢‚éB
        int getOnceNum = _getch();
        /*
        –îˆóƒL[‚ª‰Ÿ‚³‚ê‚½‚ÉAˆê‰ñ–Ú‚É–îˆóƒL[©‘Ì‚ª‰Ÿ‚³‚ê‚½‚±‚Æ‚ğ”F¯‚µ‚½‚ ‚Æ‚É“ñ‰ñ–Ú‚Å‚Ç‚ÌŒü‚«‚Ì–îˆóƒL[‚ª‰Ÿ‚³‚ê‚½‚Ì‚©‚ğ
        ¯•Ê‚·‚é‚½‚ß“ñ‚Â‚Ì•Ï”‚ğ—p‚¢‚ÄŠi”[‚µ‚Ä‚¢‚éB
        */
        int getTwiceNum = _getch();
        keyboard_input(getOnceNum, getTwiceNum, &currentStateNum);
    }

    return 0;
}

void keyboard_input(int getNumOnce, int getNumTwice, int *currentStateNum) {
    switch(getNumOnce) {
        // –îˆóƒL[‚ª‰Ÿ‚³‚ê‚½ê‡
        case 0xe0:
            switch(getNumTwice) {
                // ªƒL[‚ª‰Ÿ‚³‚ê‚½
                case 0x48:
                    system("cls");
                    if(0<*currentStateNum && *currentStateNum<4) {
                        // ()‚ğ‚Â‚¯‚È‚¢‚Æ*‰‰Zq‚æ‚è‚àƒCƒ“ƒNƒŠƒƒ“ƒg‚ª—Dæ‚³‚êAƒAƒhƒŒƒX‚ğƒCƒ“ƒNƒŠƒƒ“ƒg‚·‚é‚±‚Æ‚É‚È‚Á‚Ä‚µ‚Ü‚¤‚½‚ßA()‚ğ•t‚¯‚éB
                        (*currentStateNum)++;
                    }
                    display_transition(*currentStateNum);
                    break;
                // «ƒL[‚ª‰Ÿ‚³‚ê‚½
                case 0x50:
                    system("cls");
                    if(1<*currentStateNum && *currentStateNum<5) {
                        (*currentStateNum)--;
                    }
                    display_transition(*currentStateNum);
                    break;
            }
            break;
        // EnterƒL[‚ª‰Ÿ‚³‚ê‚½
        case 0xd:
            system("cls");
            switch(*currentStateNum) {
                case 1:
                    // ‘–¼ƒ\[ƒg
                    break;
                case 2:
                    // ƒƒ_ƒ‹ƒ\[ƒg
                    break;
                case 3:
                    // ŒŸõ
                    search();
                    break;
                case 4:
                    // “ü—Í
                    break;
            }
            break;
        // EscƒL[‚ª‰Ÿ‚³‚ê‚½
        case 0x1b:
            system("cls");
            // ƒRƒ}ƒ“ƒhƒvƒƒ“ƒvƒ‚ğ‹­§I—¹‚·‚é
            exit(0);
            break;
    }
}

void display_transition(int currentStateNum) {
    char *selectInput = "? “ü—Í\n";
    char *input = "  “ü—Í\n";
    char *selectQuery = "? ŒŸõ\n";
    char *query = "  ŒŸõ\n";
    char *selectMedalList = "? ƒƒ_ƒ‹‘Šl“¾‡ˆê——\n";
    char *medalList = "  ƒƒ_ƒ‹‘Šl“¾‡ˆê——\n";
    char *selectCountryList = "? ‘–¼‡ˆê——\n";
    char *countryList = "  ‘–¼‡ˆê——\n";

    char *selectInputState[4] = {selectInput, query, medalList, countryList};
    char *selectQueryState[4] = {input, selectQuery, medalList, countryList};
    char *selectMedalState[4] = {input, query, selectMedalList, countryList};
    char *selectCountryState[4] = {input, query, medalList, selectCountryList};

    switch(currentStateNum) {
        case 1:
            for(int i=0; i<4; i++) {
                printf("%s", selectCountryState[i]);
            }
            break;
        case 2:
            for(int i=0; i<4; i++) {
                printf("%s", selectMedalState[i]);
            }
            break;
        case 3:
            for(int i=0; i<4; i++) {
                printf("%s", selectQueryState[i]);
            }
            break;
        case 4:
            for(int i=0; i<4; i++) {
                printf("%s", selectInputState[i]);
            }
            break;
    }
}



