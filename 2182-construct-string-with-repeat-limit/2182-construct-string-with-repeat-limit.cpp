class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>arr(26,0);
        for(auto it:s){
            arr[it-'a']++;
        }
        int i=25;
        string result;
        while(i>=0){
            if(arr[i]==0){
                i--;
                continue;
            }
            int count=arr[i];
            int feq=min(count,repeatLimit);
            char ch='a'+i;
            result.append(feq,ch);
            arr[i]-=feq;
            if(arr[i]>0){
                int j=i-1;
                while(j>=0 && arr[j]==0) j--;
                if(j<0)break;
                result.push_back('a'+j);
                arr[j]--;
            }
        }
        return result;
    }
};