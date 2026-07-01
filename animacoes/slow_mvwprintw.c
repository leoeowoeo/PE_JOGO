#include <ncurses.h>
#include <string.h>

#define DELAY_MS 25

static int is_enter(int ch)
{
    return ch == '\n' || ch == '\r' || ch == KEY_ENTER;
}

static int is_skip_key(int ch)
{
    return ch == 'K' || ch == 'k';
}

static void exibir_comandos_confirmacao(WINDOW *win)
{
    int max_y, max_x;
    getmaxyx(win, max_y, max_x);

    const char *prompt = "[Enter] avançar [K] pular diálogo";
    int len = (int)strlen(prompt);
    int start_x = max_x - len;
    if (start_x < 0)
        start_x = 0;

    mvwhline(win, max_y - 1, 0, ' ', max_x);
    wattron(win, A_BOLD);
    mvwprintw(win, max_y - 1, start_x, "%s", prompt);
    wattroff(win, A_BOLD);
    wrefresh(win);
}

int slow_mvwprintw(WINDOW *win, char *fala, const int y, const int x, int *skipado)
{
    if (win == NULL || fala == NULL || skipado == NULL)
        return -1;

    if (*skipado) {
        mvwprintw(win, y, x, "%s", fala);
        wrefresh(win);
        return 1;
    }

    size_t len = strlen(fala);

    nodelay(win, TRUE);

    for (size_t i = 0; i < len; ++i) {
        mvwaddch(win, y, x + (int)i, fala[i]);
        wrefresh(win);
        napms(DELAY_MS);

        int ch = wgetch(win);
        if (ch == ERR)
            continue;

        if (is_enter(ch)) {
            mvwprintw(win, y, x + (int)i + 1, "%s", fala + i + 1);
            wrefresh(win);
            break;
        }

        if (is_skip_key(ch)) {
            *skipado = 1;
            nodelay(win, FALSE);
            return 1;
        }
    }

    nodelay(win, FALSE);

    exibir_comandos_confirmacao(win);

    while (1) {
        int ch = wgetch(win);
        if (ch == ERR)
            continue;

        if (is_enter(ch))
            return 0;

        if (is_skip_key(ch)) {
            *skipado = 1;
            return 1;
        }
    }
}

#ifdef SLOW_MVWPRINTW_DEMO
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int skipado = 0;
    int ret = slow_mvwprintw(stdscr,
                             "Ola! Esta e uma mensagem de teste para o efeito typewriter.",
                             3, 3, &skipado);

    mvprintw(10, 3, "Resultado: %s", ret ? "pulado" : "continuado");
    refresh();
    getch();

    endwin();
    return 0;
}
#endif