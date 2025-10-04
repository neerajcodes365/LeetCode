int min(int a, int b) {
    return (a < b) ? a : b;
}
int maxArea(int* height, int heightSize) {
    int l=0;
    int r=heightSize-1;
    int max=0;
    int vol;

    while(l<=r){

        vol=(r-l)* (min(height[r],height[l]));
        if(height[r]>height[l]) l++;
        else r--;
        if(vol>max) max= vol;
    }
    return max;
}