class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        si=sorted(s)
        ti=sorted(t)
        return si==ti