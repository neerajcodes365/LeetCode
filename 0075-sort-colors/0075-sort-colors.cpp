class Solution {
public:
    void sortColors(vector<int>& n) {
        int size=n.size();
        for(int i=0;i<size;i++){
            if(n[i]==0){
                int j=i;
                while(j>0 && n[j-1]!=0){
                    swap(n[j-1],n[j]);
                    j--;
                }
            }
        }
        for(int i=0;i<size;i++){
            if(n[i]==1){
                int j=i;
                while(j>0 && n[j-1]!=1){
                    swap(n[j-1],n[j]);
                    j--;
                }
            }
        }
        for(int i=0;i<size;i++){
            if(n[i]==2){
                int j=i;
                while(j>0 && (n[j-1]!=2)){
                    swap(n[j-1],n[j]);
                    j--;
                }
            }
        }
        reverse(n.begin(),n.end());
        return;
    }
};