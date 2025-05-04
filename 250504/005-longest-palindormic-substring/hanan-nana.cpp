class Solution {
    int checkOddLength(string s, int i) {
        int l = 0;
        while (i-l-1 >= 0 && i+l+1 < s.size() && s[i-l-1] == s[i+l+1]) {
            l++;
        }
        return l; // i-l ~ i+l
    }
  
    int checkEvenLength(string s, int i) {
        int l = 1;
        while (i-l >= 0 && i+l+1 < s.size() && s[i-l] == s[i+l+1]) {
            l++;
        }
        return l;   // i-l+1 ~ i+l
    }
  
  public:
    string longestPalindrome(string s) {
        int max_length = 0;
        string max_str;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == s[i+1]) {
                int l = checkEvenLength(s, i);
                cout << l << endl;
                if (2 * l > max_length) {
                    max_str = s.substr(i-l+1, 2*l);
                    max_length = 2 * l;
                }
            }
            int l = checkOddLength(s, i);
            if (2 * l + 1 > max_length) {
                max_str = s.substr(i-l, 2 * l + 1);
                max_length = 2 * l + 1;
            }
        }
        return max_str;
    }
  };
  
  