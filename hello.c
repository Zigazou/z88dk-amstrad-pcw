#include <stdio.h>

#pragma output nostreams
#pragma output nofileio
#pragma output noprotectmsdos
#pragma output noredir
#pragma output nogfxglobals

char locate_buffer[]="\033Y__";
locate(char x, char y) {
    locate_buffer[2] = y+31;
    locate_buffer[3] = x+31;
    bdos(9, locate_buffer);
}

home() { bdos(9, "\033H"); }
clear_screen() { bdos(9, "\033H\033J"); }
delete_line() { bdos(9, "\033M"); }
insert_line() { bdos(9, "\033L"); }
clear_eol() { bdos(9, "\033K"); }
cursor_up() { bdos(9, "\033A"); }
cursor_down() { bdos(9, "\033B"); }
cursor_left() { bdos(9, "\033D"); }
cursor_right() { bdos(9, "\033C"); }

reverse_on() { bdos(9, "\033p"); }
reverse_off() { bdos(9, "\033q"); }

underline_on() { bdos(9, "\033r"); }
underline_off() { bdos(9, "\033u"); }

chain(char *string) {
    char *pointer;

    pointer = 0x80;
    while(*string != 0) {
        *pointer = *string;
        pointer++;
        string++;
    }
    *pointer = 0;

    bdos(47, 0);
}

main() {
    bdos(110, 0);

    clear_screen();
    
    locate(38, 16);
    reverse_on();
    bdos(9, "Hello, World!");
    reverse_off();

    locate(38, 18);
    underline_on();
    bdos(9, "Hello, World!");
    underline_off();

    locate(0, 30);

    return 0;
}

