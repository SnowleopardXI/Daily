#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define CTRL_KEY(k) ((k) & 0x1f)
#define MAX_LINES 1000
#define MAX_COLS 80

char *lines[MAX_LINES];
int num_lines = 0;
int current_line = 0;
int current_col = 0;

void load_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return;
    }

    char buffer[MAX_COLS];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        lines[num_lines] = malloc(strlen(buffer) + 1);
        strcpy(lines[num_lines], buffer);
        num_lines++;
    }
    fclose(file);
}

void save_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return;
    }

    for (int i = 0; i < num_lines; i++) {
        fprintf(file, "%s\n", lines[i]);
    }
    fclose(file);
}

void editor_refresh_screen() {
    clear();
    for (int i = 0; i < num_lines; i++) {
        mvprintw(i, 0, "%s", lines[i]);
    }
    move(current_line, current_col);
    refresh();
}

void editor_process_keypress() {
    int c = getch();

    switch (c) {
        case CTRL_KEY('q'):
            endwin();
            exit(0);
            break;
        case CTRL_KEY('s'):
            save_file("output.txt");
            break;
        case KEY_UP:
            if (current_line > 0) {
                current_line--;
                if (current_col > strlen(lines[current_line])) {
                    current_col = strlen(lines[current_line]);
                }
            }
            break;
        case KEY_DOWN:
            if (current_line < num_lines - 1) {
                current_line++;
                if (current_col > strlen(lines[current_line])) {
                    current_col = strlen(lines[current_line]);
                }
            }
            break;
        case KEY_LEFT:
            if (current_col > 0) {
                current_col--;
            }
            break;
        case KEY_RIGHT:
            if (current_col < strlen(lines[current_line])) {
                current_col++;
            }
            break;
        default:
            if (c >= 32 && c <= 126) {
                int len = strlen(lines[current_line]);
                if (len < MAX_COLS - 1) {
                    memmove(&lines[current_line][current_col + 1], &lines[current_line][current_col], len - current_col + 1);
                    lines[current_line][current_col] = c;
                    current_col++;
                }
            }
            break;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    for (int i = 0; i < MAX_LINES; i++) {
        lines[i] = malloc(MAX_COLS);
        memset(lines[i], 0, MAX_COLS);
    }

    load_file(argv[1]);

    while (1) {
        editor_refresh_screen();
        editor_process_keypress();
    }

    endwin();
    return 0;
}

