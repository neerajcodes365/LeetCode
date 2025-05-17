int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int elt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            elt = nums[i];
            count = 1;
        } else if (nums[i] == elt) {
            count++;
        } else {
            count--;
        }
    } 
    count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == elt) {
            count++;
        }
    }

    if (count > numsSize / 2) {
        return elt;
    } else {
        return -1;
    }
}

