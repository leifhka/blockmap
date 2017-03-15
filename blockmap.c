#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

#include "blockmap.h"

/*-----------------*/

void init_screen()
{
    initscr();
    noecho();
    cbreak();
    refresh();
}

void eval_input(char c, WORLD *m, WINDOW *w)
{
    if (c == 'l') {
	(m->position)++;
    } else if (c == 'k') {
        m->position -= m->max_x;
    } else if (c == 'j') {
        m->position += m->max_x;
    } else if (c == 'h') {
        (m->position)--;
    } else if (c == 'p') {
	(*(m->data))[m->position] = getch();
    }
}

void draw_map(WORLD *world, WINDOW *win)
{
    wmove(win, 0, 0);
    int world_size = world->max_x * world->max_y;
    for (int i = 0; i < world_size; i++) {
        if (i == world->position)
            waddch(win, '@');
        else
	    waddch(win, (*(world->data))[i]);
    }

    wrefresh(win);
}
    
int main()
{
    init_screen();
    int row, col;
    getmaxyx(stdscr, row, col);
    int row_map = row-1;
    WINDOW *map_win = newwin(row_map, col, 0, 0);
    wrefresh(map_win);

    WORLD *world = malloc(sizeof(WORLD));
    world->position = 0;
    world->max_x = col;
    world->max_y = row_map;
    char *map_data = malloc(sizeof(char)*col*row_map);
    for (int i = 0; i < col*row_map; i++) map_data[i] = ' ';
    world->data = &map_data;

    draw_map(world, map_win);

    char c;
    while ('q' != (c = getch())) {
        eval_input(c, world, map_win);
        draw_map(world, map_win);
    }

    endwin();

    return 0;
}
