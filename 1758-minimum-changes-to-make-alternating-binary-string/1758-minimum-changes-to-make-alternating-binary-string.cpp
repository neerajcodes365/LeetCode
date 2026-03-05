class Solution {
public:
    int minOperations(string s) {
        int forzero=0,forone=0;
        int flag0=0,flag1=1;

        for(int i=0;i<s.length();i++){
            if((s[i]-'0')!=flag0)forzero++;
            if((s[i]-'0')!=flag1)forone++;
            // cout<<forzero<<" "<<forone<<endl;
            flag0=!flag0;
            flag1=!flag1;
        }
        return min(forzero,forone);
    }
};