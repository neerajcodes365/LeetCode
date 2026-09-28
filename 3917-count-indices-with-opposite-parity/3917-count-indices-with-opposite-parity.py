class Solution:
    def countOppositeParity(self, nums: list[int]) -> list[int]:
        odd=[]
        even=[]
        oddc=0
        evenc=0
        for i in nums[::-1]:
            if(i%2==0):
                evenc+=1
            else:
                oddc+=1
            odd.append(oddc)
            even.append(evenc)
        odd=odd[::-1]
        even=even[::-1]
        odd.append(0)
        even.append(0)
        j=1
        ans=[]
        for i in nums:
            if(i%2==1):
                ans.append(even[j])
            else:
                ans.append(odd[j])
            j+=1
        return ans