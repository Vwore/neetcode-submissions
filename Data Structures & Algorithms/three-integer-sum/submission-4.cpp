class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,vector<int>> mapping;
        vector<pair<int,int>> arr;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            arr.push_back({nums[i],i});
        }

        sort(arr.begin(),arr.end());
        vector<vector<int>> answer;
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && arr[i].first == arr[i-1].first) continue;
            int target = -arr[i].first;
            int left=i+1,right=n-1;
            while(left<right)
            {
                if(arr[left].first+arr[right].first==target)
                {
                    answer.push_back({arr[i].first,arr[left].first,arr[right].first});
                    left++;
                    while(left<n && arr[left].first == arr[left-1].first ) left++;
                    right--;
                    while(right>=0 && arr[right].first == arr[right+1].first) right--;
                }
                else if(arr[left].first+arr[right].first>target)
                {
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return answer;
    }
};
