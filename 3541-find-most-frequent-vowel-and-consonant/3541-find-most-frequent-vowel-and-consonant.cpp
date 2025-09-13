class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int>vov;
        map<char,int>non;

        unordered_set<char>seti;
        seti.insert('a');
        seti.insert('e');
        seti.insert('i');
        seti.insert('o');
        seti.insert('u');
int maxi1=0,maxi2=0;
        for(auto it:s){
            if(seti.count(it)>0){
                vov[it]++;
                maxi1=max(maxi1,vov[it]);
            }else{
                non[it]++;
                maxi2=max(maxi2,non[it]);
            }
        }

return maxi1+maxi2;

        

    }
};