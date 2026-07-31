int maxSubArray(int* nums, int numsSize) {
    int curr = nums[0];
    int ans = nums[0];

    for (int i = 1; i < numsSize; i++) {
        curr = (curr + nums[i] > nums[i]) ? (curr + nums[i]) : nums[i];
        ans = (ans > curr) ? ans : curr;
    }

    return ans;
}