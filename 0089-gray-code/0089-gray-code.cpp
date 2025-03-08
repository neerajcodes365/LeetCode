class Solution {
public:
    vector<int> grayCode(int n) {
        int size=1<<n; // left shift 2 power ne implies cheyane,logic design il padiche pole
        vector<int>result;
        for(int i=0;i<size;i++){
            result.push_back(i^(i>>1));
        }
        return result;
    }
};