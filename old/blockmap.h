typedef struct WORLD WORLD;
typedef struct CELL CELL;

struct CELL {
    char val;
    char *note;
    char *text;
    WORLD *other_world;
};

struct WORLD {
    int position, max_x, max_y;
    char **data;
};

/*-----------------*/

void init_screen();

void eval_input(char, WORLD *, WINDOW *);

void draw_map(WORLD *, WINDOW *);

