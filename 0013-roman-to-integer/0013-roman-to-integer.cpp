class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map<char,int>map;
        map['I']=1,map['V']=5,map['X']=10,map['L']=50,map['C']=100,map['D']=500,map['M']=1000;
        for(int i=0;i<s.length();i++){
            if(i+1<s.length() && map[s[i]]<map[s[i+1]]) ans-=map[s[i]];//subtract now ,in next step corresponding number will be added ,ie we want to 5 - 1 =4, so we minus 1 first then add 5 in next step ,
            else ans+=map[s[i]];
            
        }
        return ans;
    }
};