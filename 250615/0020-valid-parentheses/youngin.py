class Solution:
    def isValid(self, s: str) -> bool:
        def findMatchingBrackets(open_bracket):
            if open_bracket == "(": return ")"
            elif open_bracket == "{": return "}"
            elif open_bracket == "[": return "]"
            return None

        stack = []
        for bracket in s:
            if bracket in {"(", "{", "["}:
                stack.append(bracket)
            elif bracket in {")", "]", "}"}:
                if len(stack) == 0: return False
                last_bracket = stack.pop()
                if findMatchingBrackets(last_bracket) != bracket:
                    return False

        return len(stack) == 0