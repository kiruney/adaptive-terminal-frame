#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

struct winsize get_console_size(struct winsize w) {
    if (ioctl(STDIN_FILENO, TIOCGWINSZ, &w)) {
        perror("Error getting console size");
    }
    return w;
}

void print_frame(struct winsize w) {
    system("clear");
    for (int i = 0; i < w.ws_row; i++) {
        for (int j = 0; j < w.ws_col; j++) {
            if (i == 0 || i == w.ws_row-1 || j == 0 || j == w.ws_col-1) {
                printf("#");
            } else {
                printf(" ");
            }
        }

        if (i < w.ws_row-1) {
            printf("\n");
        }
    }
}

void print_console_info(struct winsize w) {
    printf("\x1B[3;4f");
    printf("ROWS: %d", w.ws_row);
    printf("\x1B[4;4f");
    printf("COLS: %d", w.ws_col);
    printf("\x1B[5;4f");
}

int main() {
    struct winsize w = get_console_size(w);
    print_frame(w);
    print_console_info(w);
    getchar();
    return 0;
}
