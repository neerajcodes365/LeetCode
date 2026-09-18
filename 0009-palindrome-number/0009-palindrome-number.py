class Solution:
    def isPalindrome(self, x: int) -> bool:
        s=str(x)
        v=s[::-1]
        return s==v
