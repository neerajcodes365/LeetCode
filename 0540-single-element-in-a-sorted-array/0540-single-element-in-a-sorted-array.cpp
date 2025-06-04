class Solution {
public:
// int singleNonDuplicate(vector<int>& nums) {
//     int a = nums[0];
//     for (int i = 1; i < nums.size(); i++) {
//         a = a ^ nums[i];
//     }
//     return a;
// }
// int singleNonDuplicate(vector<int>& nums) {
//     int low = 0;
//     int high = nums.size() - 1;

//     while (low <= high) {
//         int mid = low + (high - low) / 2 ;

//         // Case 1: nums[mid] is the single element (not equal to neighbors)
//         if ((mid == 0 || nums[mid] != nums[mid - 1]) &&
//             (mid == nums.size() - 1 || nums[mid] != nums[mid + 1])) {
//             return nums[mid];
//         }

//         // Case 2: nums[mid] pairs with the right neighbor
//         if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
//             // int leftCount = mid - low; // number of elements on the left
//             // if (leftCount % 2 == 0) {
//                 low = mid + 2; // move right
//             // } else {
//                 // high = mid - 1; // move left
//             // }
//         }

//         // Case 3: nums[mid] pairs with the left neighbor
//         else if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
//             // int leftCount = mid - 1 - low; // elements before the pair
//             // if (leftCount % 2 == 0) {
//                 // low = mid + 1; // move right
//             // } else {
//                 high = mid - 2; // move left
//             // }
//         }
//     }

//     return -1; // Should not happen if input is valid
// }


    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid % 2 == 1) {
                mid--;
            }
            if (nums[mid] != nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 2;
            }
        }
        return nums[right];
    }

};
