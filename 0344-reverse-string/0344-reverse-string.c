void reverseString(char* s, int si) {
    int i=0;
    int j=si-1;
    while(i<j){
        char tp=s[i];
        s[i]=s[j];
        s[j]=tp;
        i++;
        j--;
    }
}