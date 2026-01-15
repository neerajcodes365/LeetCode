class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n=words.size();
        for(int j=0;j<n;j++){
            int num=words[j][0]-'a';
            for(int i=0;i<words[j].size();i++){
                int val=words[j][i]-num;
                if(val<97)val+=26;
                words[j][i]=val;
            }
        }
        // for(auto it:words) cout<<it<<" ";
        // return 0;
        long long ans=0;
        map<string,int>st;
        for(int i=0;i<n;i++){
            if(st.count(words[i]))ans+=st[words[i]];
            int num=st[words[i]];
            // st.inset(words[i],num+1);
            st[words[i]]=num+1;
        }
        return ans;
    }
};