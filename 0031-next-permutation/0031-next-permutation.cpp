class Solution {
public:
    void nextPermutation(vector<int>& n) {
        int ind=-1;
        int size=n.size();
        for(int i=size-1;i>0;i--){
                if(n[i]>n[i-1]){
                    ind=i-1;
                    break;
                }
        }
        if(ind==-1){
            sort(n.begin(),n.end());
            return;
        }
        int matteindex=-1;
        int min=101;
        for(int i=ind+1;i<size;i++){
            if(n[i]>n[ind] && n[i]<min){
                matteindex=i;
                min=n[i];
            }
        }
        swap(n[ind],n[matteindex]);
        sort(n.begin()+ind+1,n.end());
        return;
    }
};