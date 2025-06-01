#include <unordered_set>
#include <string>
using namespace std;

class Solution {
    private:
        unordered_set<string> unavailable;
    
        static bool sortByLength(string a, string b) {
            return a.size() > b.size();
        }
    
        bool findMatch(string s1, string s2) {
            int i = 0;
            for (auto c: s2) {
                if (s1[i] != c) return false;
                i++;
            }
            return true;
        }
    
        bool nextWord(string s, vector<string>& wordDict) {
            if (unavailable.find(s) != unavailable.end()) return false;
            if (s == "") {
                return true;
            }
    
            for (auto word: wordDict) {
                if (findMatch(s, word)) {
                    bool result = nextWord(s.substr(word.size()), wordDict);
                    if (result) return true;
                }
            }
    
            unavailable.insert(s);
            return false;
        }
    
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            sort(wordDict.begin(), wordDict.end(), sortByLength);
    
            return nextWord(s, wordDict);
        }
    };