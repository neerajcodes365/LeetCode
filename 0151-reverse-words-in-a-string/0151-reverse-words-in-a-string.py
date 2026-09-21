class Solution:
    def reverseWords(self, s: str) -> str:
        arr=s.split()
        print(arr)
        arr=arr[::-1]
        st=""
        n=len(arr)
        j=0
        for i in arr:
            # st.append(i)
            # st.append(" ")
            st+=i
            if j<n-1:
                st+=" "
            j+=1
        return st
        