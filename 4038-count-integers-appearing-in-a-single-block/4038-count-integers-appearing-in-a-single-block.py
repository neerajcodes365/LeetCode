from collections import defaultdict
class Solution:
    def countSpecialIntegers(self, nums: list[int]) -> int:
        ans=0
        n=len(nums)
        # fidx={}
        fidx=defaultdict(int)
        # lidx={}
        lidx=defaultdict(int)
        # cnt={}
        cnt=defaultdict(int)
        for i in range(n):
            if (nums[i] not in fidx):
                fidx[nums[i]]=i
            lidx[nums[i]]=i
            cnt[nums[i]]+=1
        for i in cnt:
            if  lidx[i]-fidx[i]+1==cnt[i]:
                ans+=1
        return ans