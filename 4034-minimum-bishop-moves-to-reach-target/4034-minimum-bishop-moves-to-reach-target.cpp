class Solution {
public:
    int minBishopMoves(vector<int>& s, vector<int>& t) {
        int a=s[0];
        int b=s[1];
        int c=t[0];
        int d=t[1];
        if( ( (a+b)%2 )!= ((c+d)%2) ) return -1;
        if( ((a+b)==(c+d)) || (a-b) == (c-d) )return 1;
        return 2;
    }
};