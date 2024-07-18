#include <cstdio>
#include <ncurses.h>
#include <string>

int main() {
    initscr();
    noecho();
    cbreak();
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);
    WINDOW *inputwin = newwin(5, x_max - 12, y_max - 8, 5);
    box(inputwin, 0, 0);
    refresh();
    wrefresh(inputwin);

    keypad(inputwin, true);
    std::string choices[3] = {"Walk", "Jog", "Run"};
    int choice, highlight = 0;
    while (1) {
        for (int i = 0; i < 3; i++) {
            if (i == highlight)
                wattron(inputwin, A_REVERSE);
            mvwprintw(inputwin, i + 1, 1, "%.10s", choices[i].c_str());
            wattroff(inputwin, A_REVERSE);
        }
        choice = wgetch(inputwin);
        switch (choice) {
            case KEY_UP: highlight = (highlight + 2) % 3; break;
            case KEY_DOWN: highlight = (highlight + 1) % 3; break;
        }
        if (choice == 10)
            break;
    }
    printw("Your choice was: %.10s", choices[highlight].c_str());
    refresh();
    std::getchar();
    delwin(inputwin);
    endwin();
    return 0;
}