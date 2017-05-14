
use std::collections::VecDeque;
use std::collections::HashSet;
use std::collections::BTreeMap;

#[derive(Clone, Copy, PartialEq, Eq, Debug, Hash)]
pub enum Property {
    CanOccupy,
    DifficultTerrain,
    Damaging,
	Solid,
	Liquid,
	Gas,
}

/* Let items be modelled by Rust-ownership,
 * such that unique items has move-semantics and
 * non-unique items have copy semantics
 */
#[derive(PartialEq, Eq, Debug, Hash)]
pub enum Item {
    Creature,
    Text(String),
}

#[derive(Debug, PartialEq, Eq)]
pub struct Cell {
    representation: char,
	properties: HashSet<Property>,
	connections: HashSet<u32>, // u32s are Cell ids
	items: HashSet<Item>, // Cell should own Items
}

#[derive(Debug)]
pub struct Map {
	position: u32,
	max_x: u32,
	max_y: u32,
	cells: VecDeque<u32>,
}

#[derive(Debug)]
pub struct World {
	maps: VecDeque<Map>,
	cell_map: BTreeMap<u32, Cell>,
	item_map: BTreeMap<u32, Item>,
}

impl Cell {
    fn new_grass(&self) -> Self {
        Cell { representation: ',', properties: HashSet::new(), connections: HashSet::new(), items: HashSet::new() }
    }
}

impl Map {
    pub fn new(max_x: u32, max_y: u32) -> Self {
        Map { position: 0, max_x: max_x, max_y: max_y, cells: VecDeque::new() }
	}
}
