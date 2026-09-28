from collections import Counter

class Solution:
    def rearrangeString(self, s: str, x: str, y: str) -> str:
        f = Counter(s)
        ans = y * f[y]                
        for k, v in f.items():
            if k != x and k != y:
                ans += k * v           
        ans += x * f[x]                
        return ans