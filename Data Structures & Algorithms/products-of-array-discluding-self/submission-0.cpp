class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product = 1;
        int n = nums.size();
        int zeroCount = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                zeroCount++;
            else
                product *= (long long)nums[i];
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (zeroCount > 1)
                ans.push_back(0);
            else if(nums[i]==0)
            {
                ans.push_back(product);
            }
            else if(zeroCount==1) {
                ans.push_back(0);
            }
            else {

                long long value = product / ((long long)nums[i]);
                ans.push_back((int)value);
            }
        }
        return ans;
    }
};
