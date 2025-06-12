class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int size=t.size();
        int sum=0;
        for(int i=0;i<size;i++){
            sort(t[i].begin(),t[i].end());
            sum+=t[i][0];
        }

        return sum;
    }
};


