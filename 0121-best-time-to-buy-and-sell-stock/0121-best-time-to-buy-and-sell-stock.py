class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        n=len(prices)
        arr=[0]*n
        ans=0
        maxi=0
        for i in range(n-1,-1,-1):
            maxi=max(maxi,prices[i])
            arr[i]=maxi
        """     i=0
        for val in prices:
            ans=max(ans,arr[i]-val)
            i+=1
        """
        for i,val in enumerate(prices):
            ans=max(ans,arr[i]-val)
        return ans