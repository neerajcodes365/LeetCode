class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        
        nums.sort()
        ans=set()
        n=len(nums)
        for i in range(n):
            st=set()
            for j in range(i-1,-1,-1):
                target=-1*(nums[i]+nums[j])
                if target in st:
                    lt=(nums[i],nums[j],target)
                    ans.add(lt)
                st.add(nums[j])
        return [list(x) for x in ans ]
