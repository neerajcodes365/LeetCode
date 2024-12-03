char* addSpaces(char* s, int* spaces, int spacesSize) {

    char* result = (char*)malloc((strlen(s) + spacesSize + 1)*sizeof(char));
    int s_len = strlen(s);
    int spaceptr = 0;
    int res_char = 0;

    for (int i = 0; i < s_len; i++)
    {
       if (spaceptr< spacesSize && i == spaces[spaceptr])
        {
            result[res_char++] =' ';
            spaceptr++;
        }
        result[res_char++] = s[i];
    }    
    result[res_char] = '\0';
    return result;
}