class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        for(int i=0;i<n;i++){
            // if()
            char a=s[0];
            s.erase(0,1);
            s.push_back(a);
            if(s==goal) return true;
        }
        return false ;
    }
};