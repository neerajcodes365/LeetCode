// class Solution {
// public:
//     string convert(string s, int num) {
//         vector<vector<char>>array(num);
//         int n=s.size();
//         int gap=num-2;
//         int k=1,j=num;
//         int i=0;
//         int loopval;
//         int count=1;
//         while(i<n){
//             if(count%k==0 || count%num==0){
//                 // for(i:)
//                  loopval=0;
//                 while(loopval<num &&i<n){
//                     array[loopval++].push_back(s[i++]);
//                 }
//                 count++;
//             }else{
//                 loopval=num-1-1;
//                 while(loopval>0 && i<n && !((count%k==0 || count%num==0))){
//                     array[loopval--].push_back(s[i++]);
//                     count++;
//                 }
//             }
//         }
//         string ans="";
//         for(int i=0;i<num;i++){
//             for(int j=0;j<array[0].size();j++){
//                 ans+=array[i][j];
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    string convert(string s, int num) {
        if (num == 1 || s.size() <= num) return s;
        vector<string>array(num);
        bool down=false;
int i=0;

  for(char c:s){
    array[i].push_back(c);
    if(i==0 || i==num-1) down=!down;
    if(down)i++;
    else i--;
  }

  string ans="";

  for(int i=0;i<num;i++){
    ans+=array[i];
  }
  return ans;
  
    }
};
