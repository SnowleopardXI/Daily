#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define MAX_COLS 1024

char buffer[MAX_LINES][MAX_COLS];
int lines = 0;
int modified = 0;

void save_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < lines; i++) {
            fprintf(file, "%s\n", buffer[i]);
        }
        fclose(file);
        modified = 0;
    }
}

void load_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        while (fgets(buffer[lines], MAX_COLS, file)) {
            buffer[lines][strcspn(buffer[lines], "\n")] = '\0';
            lines++;
        }
        fclose(file);
    }
}

void insert_char(int row, int col, char ch) {
    memmove(&buffer[row][col + 1], &buffer[row][col], strlen(&buffer[row][col]) + 1);
    buffer[row][col] = ch;
    modified = 1;
}

void delete_char(int row, int col) {
    memmove(&buffer[row][col], &buffer[row][col + 1], strlen(&buffer[row][col + 1]) + 1);
    modified = 1;
}

int main(int argc, char *argv[]) {
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);

    int row = 0, col = 0;
    int mode = 0; // 0: command mode, 1: insert mode

    if (argc > 1) {
        load_file(argv[1]);
    } else {
        lines = 1;
    }

    while (1) {
        clear();
        for (int i = 0; i < lines; i++) {
            mvprintw(i, 0, "%s", buffer[i]);
        }
        move(row, col);
        refresh();

        int ch = getch();

        if (mode == 1) { // insert mode
            switch (ch) {
                case 27: // ESC
                    mode = 0;
                    break;
                case KEY_BACKSPACE:
                case 127:
                    if (col > 0) {
                        delete_char(row, col - 1);
                        col--;
                    } else if (row > 0) {
                        col = strlen(buffer[row - 1]);
                        strcat(buffer[row - 1], buffer[row]);
                        for (int i = row; i < lines - 1; i++) {
                            strcpy(buffer[i], buffer[i + 1]);
                        }
                        lines--;
                        row--;
                    }
                    break;
                case KEY_DC:
                    delete_char(row, col);
                    break;
                case '\n':
                    if (lines < MAX_LINES - 1) {
                        for (int i = lines; i > row + 1; i--) {
                            strcpy(buffer[i], buffer[i - 1]);
                        }
                        buffer[row + 1][0] = '\0';
                        strcpy(buffer[row + 1], &buffer[row][col]);
                        buffer[row][col] = '\0';
                        lines++;
                        row++;
                        col = 0;
                    }
                    break;
                default:
                    insert_char(row, col, ch);
                    col++;
                    break;
            }
        } else { // command mode
            switch (ch) {
                case 'i':
                    mode = 1;
                    break;
                case KEY_UP:
                    if (row > 0) row--;
                    if (col > strlen(buffer[row])) col = strlen(buffer[row]);
                    break;
                case KEY_DOWN:
                    if (row < lines - 1) row++;
                    if (col > strlen(buffer[row])) col = strlen(buffer[row]);
                    break;
                case KEY_LEFT:
                    if (col > 0) col--;
                    break;
                case KEY_RIGHT:
                    if (col < strlen(buffer[row])) col++;
                    break;
                case ':':
                    echo();
                    char cmd[32];
                    mvprintw(LINES - 1, 0, ":");
                    getstr(cmd);
                    noecho();
                    if (strcmp(cmd, "q!") == 0) {
                        endwin();
                        return 0;
                    } else if (strcmp(cmd, "q") == 0) {
                        if (!modified) {
                            endwin();
                            return 0;
                        }
                    } else if (strcmp(cmd, "w") == 0) {
                        if (argc > 1) {
                            save_file(argv[1]);
                        }
                    } else if (strcmp(cmd, "wq") == 0) {
                        if (argc > 1) {
                            save_file(argv[1]);
                        }
                        endwin();
                        return 0;
                    }
                    break;
            }
        }
    }

    endwin();
    return 0;
}
