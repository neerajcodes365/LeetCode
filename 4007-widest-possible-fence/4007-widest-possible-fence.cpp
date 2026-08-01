// class Solution {
// public:
//     int maximumWidth(vector<int>& planks) {
//         int maxi=INT_MIN;
//         map<int,int>mp;
//         for(auto it:planks){
//             mp[it]++;
//             maxi=max(maxi,it);
//         }
//         vector<int>p=planks;
//         sort(p.begin(),p.end());
//         int ans=INT_MIN;

//         set<long long>val;
//         int m=p.size();
        
//         for(int i=0;i<m;i++){
//             val.insert(p[i]);
//             for(int j=0;j<m;j++){
//                 val.insert(1LL*p[i]+p[j]);
//             }
//         }

//         // for(auto i:val){//stafcked height,answers possible
//         //     int wid=0;
//         //     if(mp.count(i)) wid+=mp[i];
//         //     for(auto j:uniq){//finding out max combination,iterating the map
//         //        if(j>i/2)break;
//         //         long long target=i-j;
//         //         if(!mp.count(target))continue;
//         //         else if(target==j) wid+=mp[j]/2;
//         //         else wid+=min(mp[j],mp[target]);
//         //     }
//         //     ans=max(ans,wid);
//         // }
//         for(auto h:val){
//             int wid=0;
//             int hi=upper_bound(p.begin(),p.end(),h);
//             int lo=lower_bound(p.begin(),p.end(),h);
//             if(h<=maxi)wid+=hi-lo;
            
            
            
//         }
//         return ans; 
//     }
// };
class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        sort(planks.begin(), planks.end());
        int n = planks.size();
        int ans = 0;

        unordered_map<int,int>mp;

        for(int i = 0; i<n; i++){
            mp[planks[i]]++;
            ans = max(ans, mp[planks[i]]);
            
        }

        vector<int> unq;

        for(auto it : mp){
            unq.push_back(it.first);
        }
        unordered_map<int,int> sum;

        for(int i = 0; i<unq.size(); i++){
            sum[2*unq[i]] += (mp[unq[i]]/2);
            for(int j = i+1; j<unq.size(); j++){
                sum[unq[i] + unq[j]] += min(mp[unq[i]], mp[unq[j]]);
            }
        }

        for(auto it : unq){
            int val = mp[it];
            if(sum.count(it)){
                val += sum[it];
            }
            ans = max(ans, val);
        }

        for(auto it : sum){
            ans = max(ans,it.second);
        }
        
        return ans;
    }
};