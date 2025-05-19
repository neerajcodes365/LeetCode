class Solution {
private:
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftPart(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            arr[k++] = leftPart[i++];
        } else {
            arr[k++] = rightPart[j++];
        }
    }
    while (i < leftPart.size()) {
        arr[k++] = leftPart[i++];
    }
    while (j < rightPart.size()) {
        arr[k++] = rightPart[j++];
    }
}
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        countfn(arr,left,mid,right);
        
        merge(arr, left, mid, right);
    }
}
void countfn(vector<int>&nums,int left,int mid,int right){
    int rt=mid+1;
    for(int i=left;i<=mid;i++){
        while(rt<=right && nums[i]>2*nums[rt]){
            rt++;
        }
        count+=(rt-(mid+1));
    }
}

public:
    int count=0;
    int reversePairs(vector<int>& nums) {
        count=0;
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
};