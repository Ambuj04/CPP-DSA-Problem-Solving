class Solution
{
public:
    int func(int n)
    {
        int sum = 0;
        int digit;
        while (n != 0)
        {
            digit = n % 10;
            n = n / 10;
            sum = sum + digit * digit;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;
        while (fast != 1)
        {
            slow = func(slow);
            fast = func(func(fast));
            if (slow == fast && slow != 1)
            {
                return false;
            }
        }
        return true;
    }
};