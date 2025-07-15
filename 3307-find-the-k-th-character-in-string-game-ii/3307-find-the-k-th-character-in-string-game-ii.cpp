class Solution {
public:
    int help(long long k,vector<int>&op,int index){


        if(index<0) return 0;

        //  long long total=(long long)pow(2,index+1);//index+1= size
        // int total=(index+1)<<1;
        // long  total = 1L << (index + 1);
        // long long total = 1LL << (index + 1);
        // long long total = static_cast<long long>(pow(2, index + 1));
        // long long total = static_cast<long long>(pow(2, index + 1));

        long long int total = 1LL <<(index+1);

    int ans=0;
    if(k>total/2){
        if( op[index]==1)ans++;
            ans+=help(k-total/2,op,index-1);

    }else{  
            ans+=help(k,op,index-1);
        } 
        return ans;
    }



    
    char kthCharacter(long long k, vector<int>& op) {
        int size=op.size();
        long long len = 1;
        /* 
        Instead of blindly recursing from the last operation to the first (deepest path to root),
we start from the smallest possible operation that covers k.
This is much more efficient, because once a character appears in a grammar level,
its path is fixed and will not change in deeper levels.
Hence, we only need to go up to that index i, not the full height.
This avoids unnecessary recursive calls.
*/
        for(int i = 0; i < size; i++){  
            len *= 2;
            if(k <= len){
                int aphla = help(k, op, i);
                return 'a' + (aphla % 26);
                break;
            }
        }
        

        int aphla=help(k,op,size-1);
        return 'a'+ (aphla%26);
    }
};
