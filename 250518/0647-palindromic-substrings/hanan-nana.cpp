#include <string>
using namespace std;

class Solution {
    private:
        string stringWithSharp(string s) {
            string r;
            r.reserve(s.size() * 2);
            for (auto c : s) {
                r += c;
                r += '#';
            }
            r.pop_back();
            return r;
        }
    
    public:
        int countSubstrings(string s) {
            int count = 0;
    
            string r = stringWithSharp(s);
            for (int i = 0; i < r.length(); i++) {
                int gap = r[i] == '#' ? 1 : 0;
                while (i-gap >= 0 && i+gap < r.length() && r[i-gap] == r[i+gap]) {
                    count++;
                    gap += 2;
                }
            }
    
            return count;
        }
    };