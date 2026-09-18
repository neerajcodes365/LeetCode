class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        dicti={}
        summ=0
        ans=0
        dicti[0]=1
        for val in nums:
            summ+=val
            target=summ-k
            if target in dicti:
                ans+=dicti[target]
            dicti[summ]=dicti.get(summ,0)+1
        return  ans