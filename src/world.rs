
use std::collections::VecDeque;

#[derive(Debug)]
pub struct World {
	position: u32,
	max_x: u32,
	max_y: u32,
	data: VecDeque<char>,
}

impl World {
    pub fn new(max_x: u32, max_y: u32) -> Self {
        World { position: 0, max_x: max_x, max_y: max_y, data: VecDeque::new() }
	}
}
