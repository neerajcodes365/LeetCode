class Solution {
public:
    int compress(vector<char>& c) {
        int n=c.size();
        vector<char>s;
        int i=0;
        while(i<n){
            char ogi=c[i];
            int count=0;
                while(i+1<n && c[i]==c[i+1]){
                    count++;
                    i++;
                }
         if(count>0) count++;
         s.push_back(ogi);
                if(count!=0){
                    string num=to_string(count);
                    for(auto &it:num){
                        s.push_back(it);
                    }
                }
            i++;
        }
        c=s;
        return c.size();
    }
};