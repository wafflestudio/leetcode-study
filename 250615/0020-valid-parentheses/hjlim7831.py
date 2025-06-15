class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        bracket_dict = {}
        bracket_dict[")"] = "("
        bracket_dict["}"] = "{"
        bracket_dict["]"] = "["
        for bracket in s:
            if not stack:
                stack.append(bracket)
                continue
            if bracket == "(" or bracket == "{" or bracket == "[":
                stack.append(bracket)
                continue
            if stack[-1] == bracket_dict[bracket]:
                stack.pop()
            else:
                stack.append(bracket)
        
        return len(stack) == 0            


        