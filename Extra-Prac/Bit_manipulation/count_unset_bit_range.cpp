class Solution
{
public:
    int countUnsetBits(int n, int l, int r)
    {
        n = n >> (l - 1);
        int cnt = 0;
        // r-l+1 times loop
        for (int i = 0; i < (r - l + 1); i++)
        {
            if (!(n & 1))
            {
                cnt++;
            }
            n = n >> 1;
        }
        return cnt;
    }
};