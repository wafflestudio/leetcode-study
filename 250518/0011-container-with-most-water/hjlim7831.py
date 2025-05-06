class Solution:
    def maxArea(self, height: List[int]) -> int:
        stack = [(0, len(height) - 1)]
        calculated = set()
        calculated.add((0, len(height) - 1))
        answer = 0
        while stack:
            li, ri = stack.pop()
            lh, rh = height[li], height[ri]
            answer = max(answer, (ri - li) * min(lh, rh))

            if rh >= lh:
                nli = li
                while nli < len(height) and height[nli] <= lh:
                    nli += 1
                if nli < ri and (nli, ri) not in calculated:
                    stack.append((nli, ri))
                    calculated.add((nli, ri))
            if rh <= lh:
                nri = ri
                while nri >= 0 and height[nri] <= rh:
                    nri -= 1
                if li < nri and (li, nri) not in calculated:
                    stack.append((li, nri))
                    calculated.add((li, nri))
        return answer