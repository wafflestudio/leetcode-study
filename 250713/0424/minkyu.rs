struct Solution {}

impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let mut left = 0;
        let mut right = 0;
        let mut count_of = vec![0; 128];
        let mut max_count = 0;
        let s_byts = s.as_bytes();
        for r_char in s.chars() {
            let r_char_count: &mut i32 = &mut count_of[r_char as usize];
            *r_char_count += 1;
            max_count = max_count.max(*r_char_count);
            right += 1;
            if max_count + k < right - left {
                let l_char = s_byts[left as usize];
                count_of[l_char as usize] -= 1;
                left += 1;
            }
        }
        right - left
    }
}

fn main() {
    println!("{}", Solution::character_replacement("AABABBA".to_string(), 1));
}
