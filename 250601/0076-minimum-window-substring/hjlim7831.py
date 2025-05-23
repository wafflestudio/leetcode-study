class Solution:
    def minWindow(self, s: str, t: str) -> str:
        self.check_dict = {}
        for alp in t:
            if alp not in self.check_dict.keys():
                self.check_dict[alp] = 0
            self.check_dict[alp] -= 1
        st, ed = 0, 0
        answer = ""
        while st < len(s) and ed <= len(s):
            if self.contains():
                if answer == "" or len(answer) > ed - st:
                    answer = s[st:ed]
                if st < ed + 1 or ed == len(s):
                    self.calculate(s[st], True)
                    st += 1
                else:
                    self.calculate(s[ed], False)
                    ed += 1
            else:
                if ed == len(s):
                    break
                self.calculate(s[ed], False)
                ed += 1
        return answer

    def contains(self) -> bool:
        for key in self.check_dict.keys():
            if self.check_dict[key] < 0:
                return False
        else:
            return True
    
    def calculate(self, val: str, minus):
        if val in self.check_dict.keys():
            if minus:
                self.check_dict[val] -= 1
            else:
                self.check_dict[val] += 1



        

        