class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_map<int,int>st;//element,freq
int j=0;
int n=arr.size();
int ans=1;

        for(int i=0;i<n;i++){
            st[arr[i]]++;
                while(st.size()>2){
                    st[arr[j]]--;
                    if(st[arr[j]]==0) st.erase(arr[j]);
                    j++;
                }
            ans=max(ans,i-j+1);
            }
return ans;
    }
};