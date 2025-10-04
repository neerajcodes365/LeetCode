class Solution {
public:
    int maxArea(vector<int>& h) {
            int ans=0;
            int l=0;
            int r=h.size()-1;

            while(l<r){
                int mini=min(h[l],h[r]);
                int dis=r-l;
                ans=max(ans,mini*dis);
                if(h[r]>h[l])l++;
                else r--;
            }
            return ans;
        
    }
};