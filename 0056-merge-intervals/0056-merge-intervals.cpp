class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(), in.end());  
        int size = in.size();
        int i = 0;
        
        while (size != 1 && i < size - 1) {  
            if ((*(in[i].end() - 1)) >= (*(in[i + 1].begin()))) {  
                int large = (*(in[i].end() - 1) > *(in[i + 1].end() - 1)) ? 
                            *(in[i].end() - 1) : *(in[i + 1].end() - 1);

                // ❌ in[i] = [a, b]; → ✅ use std::vector<int>{a, b}
                in[i] = {*(in[i].begin()), large};

                in.erase(in.begin() + i + 1); 
                size--;  
            } else {
                i++;
            }
        }

        return in;
    }
};
