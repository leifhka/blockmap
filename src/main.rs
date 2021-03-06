extern crate ncurses;

mod world;

use ncurses::*;
//use std::collections::VecDeque;
use world::*;

fn main() {
    init_screen();

	//let vecd = VecDeque::new();
	let map = Map::new(10, 10); // {position: 0, max_x: 10, max_y: 10, data: vecd};
    printw(format!("{:?}", map).as_str());

    refresh();
    getch();

    endwin();
}

fn init_screen() {
    initscr();
    noecho();
    cbreak();
    refresh();
}
