#include <stdio.h>

#pragma output nostreams
#pragma output nofileio
#pragma output noprotectmsdos
#pragma output noredir
#pragma output nogfxglobals

char characters_buffer[]="0 1 2 3 4 5 6 7 8 9 A B C D E F\r\n\r\n";
show_characters() {
    unsigned char start;
    unsigned char i;

    for(start = 32; start != 0; start += 16) {
        for(i = 0; i < 16; i++) {
            characters_buffer[i+i] = start + i;
        }
        bdos(9, characters_buffer);
    }
}

main() {
    bdos(110, 0);
    show_characters();
    return 0;
}

