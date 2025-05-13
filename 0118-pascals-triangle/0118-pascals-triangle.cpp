class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> outer;
        vector<int>inner;
        if(n>=1){
            inner.push_back(1);
            outer.push_back(inner);
            if(n==1)return outer;
            inner.clear();
        }
        if(n>=2){
            inner.push_back(1);
            inner.push_back(1);
            outer.push_back(inner);
            if(n==2)return outer;
            inner.clear();
        }        
        for(int i=3;i<=n;i++){
                inner.push_back(1);
            for (int j = 1; j <= i - 2; j++) {
    inner.push_back(outer[i - 2][j - 1] + outer[i - 2][j]);
}
            inner.push_back(1);
            outer.push_back(inner);
            inner.clear();
        }
        return outer;
    }
};