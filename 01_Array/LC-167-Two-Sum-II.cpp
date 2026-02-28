/*
At first glance , the approach come is nested loop of space complexity  O(n^2) and time colmpexity O(1).
Then the second approach is using hashmap for find remaining sum. Because find in hashmap take O(1) time complexity.
Third and most optimal way is two pointer approach Time complexity O(n) and time colmpexity O(1)
*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int start = 0;
        int end = numbers.size() - 1;
        vector<int> ans = {-1,-1}; //In case of solution not exist
        while (start < end)
        {
            if (numbers[start] + numbers[end] == target)
            {
                ans[0] = (start + 1);
                ans[1] = (end + 1);
                return ans;
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
        return ans;
    }
};
