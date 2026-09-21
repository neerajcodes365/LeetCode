# class Solution:
#     def longestCommonPrefix(self, strs: list[str]) -> str:
#         # ans=200
#         hel=sorted(strs,key=len)
#         st=hel[0]
#         ans=len(st)-1
#         for i in hel:
#             cnt=0
#             for j in range(len(st)):
#                 if(st[j]==i[j]):
#                     cnt+=1
#                 else:
#                     break
#             ans=min(ans,cnt)
        
#         return st[:ans]

class Solution:
    def longestCommonPrefix(self, v: List[str]) -> str:
        ans=""
        v=sorted(v)
        first=v[0]
        last=v[-1]
        for i in range(min(len(first),len(last))):
            if(first[i]!=last[i]):
                return ans
            ans+=first[i]
        return ans 
