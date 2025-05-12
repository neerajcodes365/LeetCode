class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    
    unordered_set<int> row;
    unordered_set<int> col;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(arr[i][j]==0){
                row.insert(i);
            }
        }
    }


    }