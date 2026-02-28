class Solution {
public:
    int concatenatedBinary(int n) {
        string ans="";
        for(int i=1;i<=n;i++){
            string s = bitset<32>(i).to_string();
            s.erase(0, s.find('1'));
            ans.append(s);
        }
       const int cont=1e+7;
        // cout<<ans<<endl;
        // long long int  final=0;
        // int len=ans.size();
        // for(int i=0;i<ans.size();i++){
        //     if(ans[i]=='1'){
        //         final= (final+(1LL<<len-i-1)%cont)%cont;
        //     }
        // }
        const int mod = 1e9 + 7;
        long long final = 0;

        for(int i = 0; i < ans.size(); i++){
            final = (final * 2 + (ans[i] - '0')) % mod;
        }
        return final;
    }
};