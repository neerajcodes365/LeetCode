class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int size=m.size();

        for(int i=0;i<size;i++){
            for(int j=i;j<size;j++){
                swap(m[i][j],m[j][i]);
            }
        }
        for(int i=0;i<size;i++){
            // for(int j=0;j<size;j++){
                reverse(m[i].begin(),m[i].end());
            }
        // }
    }
};