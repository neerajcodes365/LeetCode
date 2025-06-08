void swap(int * a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}



void heapifyup(int * arr,int i){
    int parent=(i-1)/2;
    if(i>0 && arr[i]>arr[parent]){
        swap(&arr[i],&arr[parent]);
        heapifyup(arr,parent);
    }
}

void heapifydown(int * arr,int size,int index){
    int largest=index;
    int left=(index*2)+1;
    int right=(index*2)+2;
    if(left<size && arr[largest]<arr[left]) largest=left;
    if(right<size && arr[largest]<arr[right]) largest=right;
    if(largest!=index){
        swap(&arr[index],&arr[largest]);
        heapifydown(arr,size,largest);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    int * arr = (int*)malloc(sizeof(int) * numsSize);
    
    for(int i = 0; i < numsSize; i++){
        arr[i] = nums[i];
        heapifyup(arr, i);
    }
    
    int size = numsSize;
    
    for(int i = 0; i < k; i++){
        swap(&arr[0], &arr[size - 1]);
        size--; 
        
        heapifydown(arr, size, 0);
    }
    
    int kth = arr[size];  
    
    return kth;
}
