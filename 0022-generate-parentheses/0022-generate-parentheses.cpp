class Solution {
public:
    bool isvalid(string cur){
        int count=0;
        for(auto it:cur){
            if(it=='(') count++;
            if(it==')') count--;
            if(count<0)return false;
        }
        if(count==0) return true;
        return false;
    }
    void solve(vector<string>&result,string cur,int open ,int close,int n){
        if(cur.length()==2*n && isvalid(cur)){
            result.push_back(cur);
            return;
        }
        if(open<n){
            cur.push_back('(');
            solve(result,cur,open+1,close,n);
            cur.pop_back();
        }
        if(close<open){
            cur.push_back(')');
            solve(result,cur,open,close+1,n);
            cur.pop_back();
        }


    }


    vector<string> generateParenthesis(int n) {
        string cur="";
        vector<string> result;
        solve(result,cur,0,0,n);
        return result;
    }
};