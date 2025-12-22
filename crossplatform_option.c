#include <ncurses.h>
#include <string.h>

void get_console_size(int* row, int* col) {
    getmaxyx(stdscr, *row, *col);
}

void draw_frame(int row, int col) {
    for (int x = 0; x < col; x++) {
        mvaddch(0, x, '#');
        mvaddch(row - 1, x, '#');
    }
    for (int y = 1; y < row - 1; y++) {
        mvaddch(y, 0, '#');
        mvaddch(y, col - 1, '#');
    }
}

void print_info(int row, int col, const char* str) {
    int center_row = row / 2;
    int center_col = (col - strlen(str)) / 2;

    char buffer[256];
    sprintf(buffer, "ROWS: %d   COLS: %d", row, col);
    int center_inf_col = (col - strlen(buffer)) / 2;
    
    mvprintw(center_row, center_col, "%s", str);
    mvprintw(center_row + 1, center_inf_col, "%s", buffer);
}

int main() {
    initscr();
    noecho();
    curs_set(0);
    
    int row, col;
    get_console_size(&row, &col);
    
    clear();
    
    draw_frame(row, col);
    print_info(row, col, "Crossplatform option with ncurses.");
    
    refresh();
    
    getch();
    
    endwin();
    return 0;
}