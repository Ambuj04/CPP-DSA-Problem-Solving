class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> temp; // store index of largest
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            // pop untill stack is empty when next element is smaller than present element
            while (!temp.empty() &&
                   temperatures[i] >= temperatures[temp.top()])
            {
                temp.pop();
            }
            // if first element is come
            if (temp.empty())
            {
                ans[i] = 0;
            }
            else
            {
                // find next bigger element at indext temp.top()
                ans[i] = (temp.top() - i);
            }
            temp.push(i);
        }
        return ans;
    }
};