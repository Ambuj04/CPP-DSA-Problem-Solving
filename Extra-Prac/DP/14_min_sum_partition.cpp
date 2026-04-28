//FOR NON-NEGATIVE NUMBER
class Solution {
public:
   int so(int n, int target, vector<int> &a)
    {
        //(tc O(2^n),sc O(target)
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);
        prev[0] = true;
        if (a[0] <= target)
            prev[a[0]] = true;
        for (int ind = 1; ind < n; ind++)
        {
            curr[0] = true; // IMPORTANT
            for (int i = 1; i <= target; i++)
            {
                bool inclusive = false;
                if (a[ind] <= i)
                    inclusive = prev[i - a[ind]];
                bool exclusive = prev[i];
                curr[i] = inclusive || exclusive;
            }
            prev = curr;
        }
        int mini = 1e9;
        for(int i = 0;i<=target/2;i++){
            if(prev[i]){
                int s1 = i;
                int s2 = target -i;
                mini = min(mini,abs(s1-s2));
            }
        }
        return mini;
    }
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for(int i:nums){
            target += i;
        }
       return so(n,target,nums);

    }
};