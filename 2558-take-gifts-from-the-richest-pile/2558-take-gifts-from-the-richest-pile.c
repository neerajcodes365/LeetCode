void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapifyup(int *arr, int i) {
    int child = i;
    int parent = (i - 1) / 2;
    while (child > 0 && arr[child] > arr[parent]) {
        swap(&arr[child], &arr[parent]);
        child = parent;
        parent = (child - 1) / 2;
    }
}


void heapifydown(int *arr, int size, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int index = i;

    if (left < size && arr[left] > arr[index]) {
        index = left;
    }
    if (right < size && arr[right] > arr[index]) {
        index = right;
    }

    if (index != i) {
        swap(&arr[i], &arr[index]);
        heapifydown(arr, size, index);
    }
}


void insert(int val,int * arr,int i){
    arr[i]=val;
    heapifyup(arr,i);
}

long long pickGifts(int* gifts, int size, int k) {
    int arr[size];
    for(int i=0;i<size;i++){
        insert(gifts[i],arr,i);
    }
    for(int i=0;i<k;i++){
        arr[0]=(int)sqrt(arr[0]);
        heapifydown(arr,size,0);
    }
    long long sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
}