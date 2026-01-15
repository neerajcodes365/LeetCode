class Solution {
public:
    int help(vector<int>bars){
        if(!bars.size())return 1;
        sort(bars.begin(), bars.end());

        int longest=1,cur=1;
        for(int i=1;i<bars.size();i++){
            if(bars[i]==bars[i-1]+1) cur++;
            else cur=1;
            longest=max(cur,longest);
        }
        return longest+1;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hbars, vector<int>& vbars) {
        // vector<int>h,v;
        // for(int i=1;i<=n+2;i++) h.push_back(i);
        // for(int i=1;i<=m+2;i++) v.push_back(i);

        // sort(hbars.begin(), hbars.end());
        // sort(vbars.begin(), vbars.end());

        // // for(auto it:hbars) h.erase(h.begin()+it-1);
        // // for(auto it:vbars) v.erase(v.begin()+it-1);

        //  for (int i = hbars.size() - 1; i >= 0; i--) h.erase(h.begin() + hbars[i] - 1);
        // for (int i = vbars.size() - 1; i >= 0; i--) v.erase(v.begin() + vbars[i] - 1);


        // int hmax=INT_MIN,vmax=INT_MIN;

        // for(int i=0;i<h.size()-1;i++) hmax=max(hmax,h[i+1]-h[i]);
        
        //  for(int i=0;i<v.size()-1;i++)  vmax=max(vmax,v[i+1]-v[i]);

        // int ans=min(hmax,vmax);

        // return ans*ans;


        int hmax=INT_MIN,vmax=INT_MIN;
        hmax=help(hbars);
        vmax=help(vbars);

        int ans=min(hmax,vmax);
        return ans*ans;


    }
};