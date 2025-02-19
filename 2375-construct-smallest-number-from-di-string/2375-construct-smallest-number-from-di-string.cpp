class Solution {
public:


    bool match(string pattern,string num){
        for(int i=0;i<pattern.length();i++){
            if((pattern[i]=='I' && num[i] > num[i + 1] ) ||(pattern[i]=='D' &&num[i]<num[i + 1])){
                return false;
            }
        }
        return true;
    }

    string smallestNumber(string pattern) {
        string num="";
        for(int i=1;i<=pattern.length()+1;i++){
            num.push_back(i+'0');
        }

        while(!match(pattern,num)){
            next_permutation(num.begin(),num.end());
        }
        return num;
    }
};