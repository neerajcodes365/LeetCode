bool canMakeSubsequence(char *str1, char *str2)
{
	int len1 = strlen( str1 ), len2 = strlen( str2 ), i, j, ch;
	
	for ( j = 0, i = 0; j < len2; j++ )
	{
		while ( i < len1 )
		{
			ch = ( str1[i] == 'z' ? 'a' : str1[i] + 1 );
			
			if ( str1[i] == str2[j] || ch == str2[j] )
				break;
			
			i += 1;
		}
		
		if ( i == len1 )
			return false;
		
		i += 1;
	}
	
	return true;
}
/*
*** 
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
***
*/