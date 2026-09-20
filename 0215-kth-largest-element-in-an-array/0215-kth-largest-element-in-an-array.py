import heapq 
class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        pq=nums[:]
        heapq.heapify(pq)
        n=len(nums)
        f=n-k
        ans=0
        for i in range(f):
            ans=heapq.heappop(pq)
        return pq[0]