class Solution:
    def isPalindrome(self, x: int) -> bool:
        """s=str(x)
        v=s[::-1]
        return s==v"""
        if x<0:
            return False
        l=[]
        while x>0:
            num=x%10
            l.append(num)
            x=x//10
        y=list(reversed(l))
        return l==y