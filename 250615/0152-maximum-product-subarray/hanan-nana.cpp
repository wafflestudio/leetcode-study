#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        struct Block {
            vector<int> parts;
            int minus_count = 0;
            int original_length = 0;
        };
    
        int maxProduct(vector<int>& nums) {
            vector<Block> blocks;
            int max_val = -INT_MAX;
    
            Block b;
            b.parts.push_back(1);
            for (auto n: nums) {
                if (n == 0) {
                    blocks.push_back(b);
                    b = Block();
                    b.parts.push_back(1);
                    max_val = 0;
                } else if (n < 0) {
                    b.parts.push_back(n);
                    b.parts.push_back(1);
                    b.minus_count++;
                    b.original_length++;
                } else {
                    b.parts.back() *= n;
                    b.original_length++;
                }
            }
            blocks.push_back(b);
    
            for (auto b : blocks) {
                int block_max = 1;
                for (auto n: b.parts) block_max *= n;
    
                if (b.original_length == 0) continue;
                if (b.minus_count % 2 == 0) {
                    max_val = max(max_val, block_max);
                } else if (b.original_length == 1) {
                    max_val = max(max_val, b.parts[1]);
                } else {
                    int b_size = b.parts.size();
                    max_val = max(max_val, block_max / (b.parts[b_size-1] * b.parts[b_size-2]));
                    max_val = max(max_val, block_max / (b.parts[0] * b.parts[1]));
                }
            }
    
            return max_val;
        }
    };