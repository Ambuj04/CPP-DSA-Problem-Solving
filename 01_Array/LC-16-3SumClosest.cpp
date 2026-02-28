/*
When i see this question my first thought is The question is like 3 Sum and this question is solve by Two pointer.
But my code take bit more time because of some extra operation. At bottom there are sample code which is fast and i do comment which makes that 
code fastest.
*/
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int mindiff = INT_MAX;
        int diff;
        int n = nums.size();
        int left;
        int right;
        int resultSum;
        int sum;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (n - 2); i++)
        {
            left = i + 1;
            right = n - 1;
            while (left < right)
            {
                sum = nums[left] + nums[right] + nums[i];
                if (sum == target)
                {
                    return target;
                }
                else if (sum < target)
                {
                    diff = abs(sum - target);
                    if (mindiff > diff)
                    {
                        mindiff = diff;
                        resultSum = sum;
                    }
                    left++;
                }
                else
                {
                    diff = abs(sum - target);
                    if (mindiff > diff)
                    {
                        mindiff = diff;
                        resultSum = sum;
                    }
                    right--;
                }
            }
        }
        return resultSum;
    }
};
//Fastest code
class Solution {
public:
    int threeSumClosest(vector<int>& a, int t)
    {
        sort(a.begin(),a.end());
        int n=a.size(),i,j,k,ans=a[0]+a[1]+a[2];
        if(ans>t) return ans; //This makes fast because if after sort the minimum difference we get by sum minimum elements and if that is more than target that means this is answer because if we proceed further we only get large difference instead of minimum difference
        for(i=0;i<n-2;i++)
        {
            if(i>0&&a[i]==a[i-1])continue;//skips operation for same first digit because it give same result
            if(a[i]+a[n-1]+a[n-2]<t){ans=a[i]+a[n-1]+a[n-2];continue;}//This plays major role because the sum of  fixed i and last two digit is less than target thats means thats the closest one for that i becasue if we go left side then the difference increase and we don't want that.Then this skips whole two pointer loop
            j=i+1;k=n-1;
            while(j<k)
            {
                ans=ccc(a[i]+a[j]+a[k],ans,t);//The function not take much time because it only perform single operation
                if(a[i]+a[j]+a[k]>t) k--;
                else if(a[i]+a[j]+a[k]<t) j++;
                else return ans;
            }
        }
        return ans;
    }
    int ccc(int a,int b,int t)
    {
        if(abs(a-t)>abs(b-t)) return b;
        else return a;
    }
};