class Solution {
public:
    int characterReplacement(string s, int k) {
        // int ans=0;
        // int i=0;
        // int j=1;
        // char main=s[0];
        // int n=s.size();
        // int count=0;
        // while(j<n){
        //     if(main!=s[j]){
        //         count++;
        //     }
        //     if(count>k){
        //         while(i<n&&s[i]==main){
        //             i++;
        //             count--;
        //         }
        //        if(i<n) main=s[i];
        // ans=max(ans,j-i+1);

        //        j=i;
        //     }
            
        // ans=max(ans,j-i+1);
        // j++;
        // }
        // return ans;
        int ans=0;
        int i=0;
        int j=0;
        int n=s.size();
        int maxi=0;
        vector<int>hash(26,0);
        // int count=0;
        while(j<n){

            hash[s[j]-'A']++;

            maxi=max(maxi,hash[s[j]-'A']);

            while(j-i+1 - maxi>k){
                hash[s[i]-'A']--;
                    i++;
                    maxi=0;
                for(auto it :hash){
                    maxi=max(it,maxi);
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};