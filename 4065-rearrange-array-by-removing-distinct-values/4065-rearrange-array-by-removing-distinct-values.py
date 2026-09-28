from collections import Counter
class Solution:
    def rearrangeArray(self, nums: list[int]) -> list[int]:
        f=Counter(nums)
        ans=[]

        while len(f):
            lt=sorted(list(f.keys()))
            for i in lt:
                ans.append(i)
                f[i]-=1
                if f[i]==0:
                    del f[i]
        return ans
        
        