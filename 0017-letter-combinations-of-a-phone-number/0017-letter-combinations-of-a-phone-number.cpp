class Solution {
public:
    unordered_map<char, string> mapi = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    void backtrack(string digits,vector<string> &final,string cur,int index){
        if(cur.length()==digits.length()){
            final.push_back(cur);
            return;
        }
        char num=digits[index];
        string st=mapi[num];
        for(char it : st){
            backtrack(digits,final,cur+it,index+1);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>final;
       if(digits.size()==0)return final;
       string cur="";
       backtrack(digits,final,cur,0);
       return final;
    }
};