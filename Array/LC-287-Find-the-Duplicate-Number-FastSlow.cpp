class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    int slow = 0;
    int fast = 0;
    while (true)
    {
      slow = nums[slow];
      fast = nums[nums[fast]];
      if (fast == slow) 
      {
        slow = 0;
        while (fast != slow) 
        {
          slow = nums[slow];
          fast = nums[fast];
        }
        return slow;
      }
    }
    return -1;
  }
};