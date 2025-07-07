struct Solution;

use std::mem;
use std::ptr;

impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len() as i32;
        let two_c = n - 1;
        let max_x = (n as f32 / 2.0).ceil() as i32;
        let max_y = ((n as f32 - 1.0) / 2.0).ceil() as i32;
        for x in 0..max_x {
            for y in 0..max_y {
                let mut old_value = matrix[x as usize][y as usize];
                let mut old_x = x;
                let mut old_y = y;
                for _ in 0..4 {
                    let new_x = old_y;
                    let new_y = two_c - old_x;
                    mem::swap(&mut old_value, &mut matrix[new_x as usize][new_y as usize]);
                    old_x = new_x;
                    old_y = new_y;
                }
            }
        }
    }

    pub fn rotate2(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();
        for i in 0..n {
            for j in i+1..n {
                unsafe { ptr::swap(&mut matrix[i][j] as *mut i32, &mut matrix[j][i] as *mut i32) }
            }
        }
        
        for i in 0..n {
            matrix[i].reverse();
        }
    }
}
