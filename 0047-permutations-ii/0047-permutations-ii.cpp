class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for (int i = idx; i < nums.size(); i++) {
            if (used.count(nums[i])) continue;
            used.insert(nums[i]);

            swap(nums[idx], nums[i]);
            backtrack(nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};