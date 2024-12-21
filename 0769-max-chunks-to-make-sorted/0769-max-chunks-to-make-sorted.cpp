class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count=1;
        auto dupit=arr.begin();
        for(auto it=arr.begin()+1;(it)!=arr.end();it++){
            if((*dupit)<*(it)){
                count++; 
                dupit=it;   
            } 
        }
        return count;   
    }
};