typedef struct World World;
typedef struct Cell Cell;

struct Cell {
    char val;
    char *note;
    char *text;
    World *other_world;
};

struct World {
    int position, max_x, max_y;
    char **data;
};

/*-----------------*/

void init_screen();

void eval_input(char, World *, WINDOW *);

void draw_map(World *, WINDOW *);

