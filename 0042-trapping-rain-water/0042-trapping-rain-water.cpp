class Solution {
public:
    int trap(vector<int>& h) {
        int size=h.size();
        vector<int>leftmax(size);
        vector<int>rightmax(size);
        leftmax[0]=h[0];
        rightmax[size-1]=h[size-1];
        for(int i=1;i<size;i++){
            leftmax[i]=max(leftmax[i-1],h[i]);
        }
        for(int j=size-2;j>=0;j--){
            rightmax[j]=max(rightmax[j+1],h[j]);
        }
        int sum=0;
        for(int i=0;i<size;i++){
            sum+=min(leftmax[i],rightmax[i])-h[i];
        }
        return sum;
    }
};