class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size(),m=num2.size();
        string ans(n + m, '0');
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int nu1=num1[i]-'0';
                int nu2=num2[j]-'0';
                int mul=nu1*nu2;
                int sum = mul + (ans[i + j + 1] - '0');
                ans[i + j + 1] = (sum % 10) + '0';
                ans[i + j] += sum / 10;
            }
        }
         int idx = 0;
        while (idx < ans.size() && ans[idx] == '0') idx++;
        return idx == ans.size() ? "0" : ans.substr(idx);
    }
};