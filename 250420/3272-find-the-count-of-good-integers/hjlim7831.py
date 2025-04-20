import math

class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        digit = math.ceil(n / 2)
        pal_set = set()
        for i in range(10**(digit-1), 10**digit):
            # [1] palindrome 만들기
            if n == 1:
                pal = i
            elif n % 2 == 0:
                pal = int(str(i) + str(i)[::-1])
            else:
                pal = int(str(i) + str(i)[digit-2::-1])
            
            # [2] divisible 찾아보기
            if pal % k != 0:
                continue
            
            # [3] key 값 만들기 (중복 제거)
            cnt_key = self.get_cnt_key(pal)
            if cnt_key in pal_set:
                continue
            pal_set.add(cnt_key)
        
        base_p = math.factorial(n)

        answer = 0
        for pal in pal_set:
            cnt = base_p
            for num in pal:
                if num == 'a':
                    p = 10
                else:
                    p = int(num)
                cnt //= math.factorial(p)

            if pal[0] != '0':
                zn = int(pal[0])
                zero_cnt = math.factorial(n-1)

                for num in pal[1:]:
                    if num == 'a':
                        p = 10
                    else:
                        p = int(num)
                    zero_cnt //= math.factorial(p)
                zero_cnt //= math.factorial(zn-1)
                cnt -= zero_cnt
            answer += cnt
        return answer
                




    def get_cnt_key(self, pal: int) -> str:
        cnt_arr = [0] * 10
        while pal > 0:
            num = pal % 10
            cnt_arr[num] += 1
            pal = pal // 10
        
        key = ""
        for i in cnt_arr:
            if i == 10:
                key += "a"
            else:
                key += str(i)
        
        return key
    
        


