impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let mut dp = vec![1; nums.len()];
        for i in 0..nums.len() {
            for j in 0..i {
                if nums[i] > nums[j] {
                    dp[i] = dp[i].max(dp[j] + 1);
                }
            }
        }
        *dp.iter().max().unwrap()
    }

    pub fn length_of_lis2(nums: Vec<i32>) -> i32 {
        let mut lis = vec![nums[0]];
        for num in nums {
            let res = lis.binary_search(&num);
            match res {
                Err(idx) => {
                    if idx == lis.len() {
                        lis.push(num);
                    } else {
                        lis[idx] = num;
                    }
                }
                _ => {}
            }
        }
        lis.len() as i32
    }
}
