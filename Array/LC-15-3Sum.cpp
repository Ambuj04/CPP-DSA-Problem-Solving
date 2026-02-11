/*
After read this question , firstly i try to do with nested loop.
Then second time i try two pointer approach then i mesh up all with add twoSum function, duplicate function,multiple subset, array of j and k for store multiple j and k . that's so terrible.
Then i give another try the question is correctly done with set and two pointer.
When i see solution in other platform then i realised there is also a way to minimize the space complexity.
*/
//////////Horrible and Memory limit exceeds code/////////////////////
class Solution {
public:
void twoSum(vector<int>& numbers ,vector<vector<int>>&jandk,int&start ,int &end , int &target){
        while (start < end)
        {
            if (numbers[start] + numbers[end] == target)
            {  
               jandk.push_back({start,end});
            }
            else if (numbers[start] + numbers[end] > target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
}
    bool already(vector<vector<int>>& mat, vector<int>& v) {
    for (auto &row : mat) {
        if (row == v) {
            return true;
        }
    }
    return false;
}
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
            vector<int>subset; //size = 3
            vector<vector<int>>jandk;
        for(int i = 0;i <= (n-3);i++){
            int j = i+1;
            int k = n-1;
            int remaining = 0-nums[i];
            twoSum(nums,jandk,j,k,remaining);
            if(jandk.size()>0){
                for(auto v : jandk){
                    subset.push_back(nums[i]);
                    subset.push_back(nums[v[0]]);
                    subset.push_back(nums[v[1]]);
                     if(!already(ans,subset)){
                    ans.push_back(subset);
                    }
                }
                jandk.clear();
                subset.clear();
            }
        }
        return ans;
    }
};
/////////////////Two pointer with set////////////////////////
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> ans;
        vector<vector<int>> result;
        for (int i = 0; i <= (n - 3); i++)
        {
            int j = i + 1;
            int k = n - 1;
            int remaining = 0 - nums[i];
            while (j < k)
            {
                if (nums[j] + nums[k] == remaining)
                {
                    ans.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] > remaining)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        result.assign(ans.begin(), ans.end());
        return result;
    }
};
////////Two pointer only//////////////
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i <= (n - 3); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            int remaining = -nums[i];
            while (j < k)
            {
                if (nums[j] + nums[k] == remaining)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (j < k && nums[k] == nums[k - 1])
                        k--;
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] > remaining)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return result;
    }
};