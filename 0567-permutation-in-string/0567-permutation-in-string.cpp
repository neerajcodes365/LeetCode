class Solution {
public:
    bool checkInclusion(string p, string s) {
        map<char,int>pmap,smap;//pmap=char,times
        for(int i=0;i<p.size();i++){
            pmap[p[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            if(i<p.size()) smap[s[i]]++;
            else{
                smap[s[i]]++;
                smap[s[i-p.size()]]--;
                if ( smap[s[i-p.size()]] == 0)
                    smap.erase(s[i-p.size()]);
            }
            if (i >= p.size()- 1 && smap == pmap)
                ans.push_back(i - p.size() + 1);
        }
        return ans.size()>0;
    }
};