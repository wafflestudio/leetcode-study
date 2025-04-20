class Solution(object):
    def countGoodNumbers(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 1 
        indice_count = n//2 
        mod = 10**9 + 7 
        if n % 2 == 0:
            count = self.pow(5, indice_count, mod) * self.pow(4, indice_count, mod)
        elif n % 2 == 1: 
            count = self.pow(5, indice_count+1, mod) * self.pow(4, indice_count, mod)
        return count % mod
    
    def pow(self, n, exp, mod):
        result = 1 
        n %= mod 
        while exp > 0:
            if exp & 1:
                result = (result * n) % mod 
            n = n * n % mod 
            exp >>= 1
        return result 