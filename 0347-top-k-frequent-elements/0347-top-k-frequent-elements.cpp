class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        make_heap(nums.begin(), nums.end()); // builds a max-heap

        set<int> result;
        int count = 0;
        int prev = -1;

        for (int i = 0; i < size && result.size() < k; i++) {
            pop_heap(nums.begin(), nums.end()); // largest moves to the end
            int ele = nums.back();              // get largest element
            nums.pop_back();                    // remove it from heap

            if (ele == prev) {
                count++;
            } else {
                count = 1;
            }

            if (count >=k) { // this will just add unique elements
                result.insert(ele);
            }

            prev = ele;
        }

        return vector<int>(result.begin(), result.end());
    }
};
