bool canMakeSubsequence(char* str1, char* str2) {
    int len1=strlen(str1);
    int len2=strlen(str2);
    if(len2>len1)return false;
int st1=0;
int st2=0;
for(int i=0;i<len1;i++){
    if(str2[st2]==str1[i] || str2[st2]==(char)(((str1[i]+1-'a')%26)+'a')){
        st2++;
    }
    if(st2==len2)return true;
}
return false;   
}