#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

bool get_console_size(struct winsize *w) {
    if (ioctl(STDIN_FILENO, TIOCGWINSZ, w)) {
        perror("Error getting console size");
        return false;
    }
    return true;
}

void print_frame(const struct winsize *w) {
    printf("\033[H\033[J");
    for (int i = 0; i < w->ws_row; ++i) {
        for (int j = 0; j < w->ws_col; ++j) {
            if (i == 0 || i == w->ws_row - 1 || j == 0 || j == w->ws_col - 1) {
                putchar('#');
            } else {
                putchar(' ');
            }
        }

        if (i < w->ws_row - 1) {
            putchar('\n');
        }
    }
}

void print_console_info(const struct winsize *w, const char* format, ...) {
    va_list args;
    va_start(args, format);

    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    int len = strlen(buffer);
    int row = w->ws_row / 2;
    int col = (w->ws_col - len) / 2;

    printf("\x1B[%d;%df%s", row, col, buffer);
}

int main() {
    struct winsize w;
    if (!get_console_size(&w)) {
        exit(EXIT_FAILURE);
    }

    print_frame(&w);
    print_console_info(&w, "ROWS: %d    COLS: %d", w.ws_row, w.ws_col);

    getchar();

    return EXIT_SUCCESS;
}
