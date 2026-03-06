class Solution {
public:
    bool checkOnesSegment(string s) {

/*        int flag=0;
        int ele=1;
        for(int i=1;i<s.size();i++){
            if(ele && s[i]=='0'){
                flag++;
                ele=0;
        }
        if(s[i]=='1')ele=1;
        cout<<ele<<" "<<flag<<endl;
    }
    if(ele==1)flag++;

    if(flag<2)return true;
    return false;
    */
    for(int i=1;i<s.size();i++){
            if(s[i]=='1'&& s[i-1]=='0') return false;
        }
        return true;
    }
};