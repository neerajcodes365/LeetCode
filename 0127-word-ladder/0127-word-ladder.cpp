class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& list) {
        // int n=begin();
        set<string>dic(list.begin(),list.end());
        // for(int i=0;i<list.size();i++){
        //     dic.insert(list[i]);
        // }
        
        dic.erase(begin);
        queue<pair<string,int>> q;
        q.push({begin,1});
        while(!q.empty()){
            // int size=q.size();
            // for(int i=0;i<size;i++){
                pair<string,int>top=q.front();
                string word=top.first;
                int level=top.second;
                q.pop();
                if(word==end) return level;
                for(int i=0;i<word.size();i++){
                    // for()
                    char original=word[i];
                    for(char ch='a';ch<='z';ch++){
                        word[i]=ch;
                        if(dic.count(word)) {
                            q.push({word,level+1});
                            dic.erase(word);
                        }
                    }
                    word[i]=original;//back to original for next index char checking
                }
            }
        
        return 0;
    }
};