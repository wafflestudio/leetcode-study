#include <unordered_map>
#include <string>
using namespace std;

class Solution {
    public:
        int count = 0;
        unordered_map<char, int> summary;
        unordered_map<char, int> cur;
    
        bool isOver(char c) {
            return cur[c] > summary[c];
        }
    
        bool isInT(char c) {
            return summary.find(c) != summary.end();
        }
    
        string minWindow(string s, string t) {
            int min_len = INT_MAX;
            int max_i, min_i;
    
            for (auto c : t) {
                count++;
                summary[c]++;
            }
    
            int right_i = 0, left_i = 0;
            while (true) {
                // 모든 필요 문자를 포함할 때까지 오른쪽으로 이동
                while (count > 0) {
                    char c = s[right_i];
                    if (isInT(c)) {
                        cur[c]++;
                        if (!isOver(c)) count--;
                    }
                    right_i++;
                    if (right_i >= s.size()) break;
                }
                if (count > 0) break;
    
                // 왼쪽 끝을 최적화
                while (true) {
                    char c = s[left_i];
                    if (isInT(c)) {
                        if (!isOver(c)) break;
                        cur[c]--;
                    }
                    left_i++;
                }
    
                // 최적화된 상태 -> 계산
                if (right_i - left_i < min_len) {
                    min_len = right_i - left_i;
                    max_i = right_i;
                    min_i = left_i;
                }
    
                // 왼쪽 한칸 더 전진
                char c = s[left_i];
                cur[c]--;
                left_i++;
                count++;
            }
    
            if (min_len == INT_MAX) return "";
            else return s.substr(min_i, max_i-min_i);
        }
    };