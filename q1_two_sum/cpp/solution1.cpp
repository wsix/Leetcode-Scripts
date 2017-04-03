class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int> > numsidx;
        vector<int> delidx;
        vector<int> rtnidx;
        int count = nums.size();
        for (int i = 0; i < count; i++) {
            int num = nums[i];
            numsidx[num].push_back(i);
            if (numsidx[num].size() == 2) {
                if (2 * num != target) {
                    delidx.push_back(num);
                } else {
                    rtnidx = numsidx[num];
                    return rtnidx;
                }
            }
        }

        for (auto &delnum : delidx) {
            numsidx.erase(delnum);
        }

        for (auto &num : numsidx) {
            int delta = target - num.first;
            if (numsidx.find(delta) != numsidx.end()) {
                if (num.second[0] != numsidx[delta][0]) {
                    rtnidx = {num.second[0], numsidx[delta][0]};
                    return rtnidx;
                }
            }
        }
    }
};
