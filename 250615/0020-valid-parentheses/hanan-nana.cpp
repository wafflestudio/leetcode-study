#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        vector<char> stack;
    
        bool isValid(string s) {
            stack.reserve(s.size());
            for (auto& c: s) {
                switch (c) {
                    case '{':
                    case '(':
                    case '[':
                        stack.push_back(c);
                        break;
                    case '}':
                        if (stack.size() > 0 && stack.back() == '{')
                            stack.pop_back();
                        else return false;
                        break;
                    case ']':
                        if (stack.size() > 0 && stack.back() == '[')
                            stack.pop_back();
                        else return false;
                        break;
                    case ')':
                        if (stack.size() > 0 && stack.back() == '(') {
                            stack.pop_back();
                        }
                        else return false;
                        break;
                }
            }
            return !stack.size();
        }
    };