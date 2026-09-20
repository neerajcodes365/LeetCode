import heapq
import math 
class Solution:
    def dis(self,x,y):
        return math.sqrt(x**2+y**2)
    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
        ans=[]
        for i in points:
            ans.append([self.dis(i[0],i[1]),i])
        heapq.heapify(ans)
        return [heapq.heappop(ans)[1] for j in range(k)]
        