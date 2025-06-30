class Solution {
public:
    int compareVersion(string vi, string vii) {
 
        int si=vi.length();
        int sii=vii.length();
        // int size=si<sii?si:sii;
        vector<int>fir,sec;

        int start=0;
        int len=0;

        for(int i=0;i<si;i++){
            if(vi[i]=='.'){
                fir.push_back(stoi(vi.substr(start,len)));
                start=i+1;
                len=0;
            }
            else{
                len++;
            }
        }
                fir.push_back(stoi(vi.substr(start,len)));

        start=0,len=0;
        for(int i=0;i<sii;i++){
            if(vii[i]=='.'){
                sec.push_back(stoi(vii.substr(start,len)));
                start=i+1;
                len=0;
            }
            else{
                len++;
            }
        }
                sec.push_back(stoi(vii.substr(start,len)));

        int n=fir.size();
        int m=sec.size();
        int size=n>m?n:m;

        for (int i= 0;i<size;i++) {
            int f=(i<n)?fir[i]:0;
            int s=(i<m)?sec[i]:0;

            if (f>s) return 1;
            else if (f<s) return -1;
        }
        return 0;

    }
};