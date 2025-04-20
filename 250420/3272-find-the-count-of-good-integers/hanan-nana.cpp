#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
  
      vector<deque<int>> Pal;
      int factorial[11];
  
      long long getNumber(deque<int> cur) {
          long long answer = 0;
          while (!cur.empty()) {
              answer = answer*10 + cur.front();
              cur.pop_front();
          }
          return answer;
      }
  
      // k로 나눠지는 Pal을 모두 구한다.
      // input: 현재까지 값, 남은 숫자 수
      // base: n == 0이고 k로 나눠지면 벡터에 추가
      void getEveryPal(int n, int k, deque<int>& cur) {
          if (n == 0) {
              if (getNumber(cur) % k == 0 && cur[0] != 0)
                  Pal.push_back(cur);
              return;
          }
          if (n % 2 == 1) {
              for (int i = 0; i < 10; i++) {
                  cur.push_back(i);
                  getEveryPal(n-1, k, cur);
                  cur.pop_back();
              }
          } else {
              for (int i = 0; i < 10; i++) {
                  cur.push_back(i);
                  cur.push_front(i);
                  getEveryPal(n-2,k, cur);
                  cur.pop_back();
                  cur.pop_front();
              }
          }
      }
  
      long long getCount(deque<int> dq) {
          int counts[10] = {};
          for (auto& val: dq) {
              counts[val]++;
          }
  
          int totalCount = factorial[dq.size()];
          for (auto& val: counts) {
              totalCount /= factorial[val];
          }
  
          if (counts[0] > 0) {
              counts[0]--;
              int zeroCount = factorial[dq.size() - 1];
              for (auto& val: counts) {
                  zeroCount /= factorial[val];
              }
              totalCount -= zeroCount;
          }
  
          return totalCount;
      }
  
      long long getFactorial(int n) {
          long long result = 1;
          for (int i = 2; i <= n; i++)
              result *= i;
          return result;
      }
  
      long long countGoodIntegers(int n, int k) {
          long long answer = 0;
          deque<int> cur;
          deque<int> checked;
  
          for (int i = 0; i <= 10; i++) {
              factorial[i] = getFactorial(i);
          }
  
          getEveryPal(n, k, cur);
  
          // unique한 것들만 골리낸다. 
          for (auto& dq: Pal) {
              sort(dq.begin(), dq.end());
          }
          sort(Pal.begin(), Pal.end());
          Pal.erase(unique(Pal.begin(), Pal.end()), Pal.end());
  
          for (auto& dq: Pal) {
              answer += getCount(dq);
          }
  
  
          return answer;
      }
  };