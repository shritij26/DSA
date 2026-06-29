#include <iostream>
#include <vector>
using namespace std;

// Sliding Window Technique 3 applications
/*
1)longest subarray/substring where <condition> is satisfied
2)No. of subarrays/substrings where <condition> is satisfied
  Eg: Q) no. of subarrays with sum = k
      no. of subarray with sum < k = x
      no. of subarray with sum < (k-1) = y
      no. of subarray with sum = k = x-y
3)Maximum/minimum subarray where <condition> is satisfied
*/

int longestSubarrayWithSumlessThanK(vector<int> arr, int k)
{
    int n = arr.size();
    int sum = 0;
    int start = 0;
    int end = 0;
    int maxLength = 0;
    while (end < n)
    {
        sum += arr[end];
        while (sum >= k && start <= end) // shrink the window
        {
            sum -= arr[start];
            start++;
        }
        maxLength = max(maxLength, end - start + 1);
        end++; // expand the window
    }
    return maxLength;
}

int longestSubarrayWithSumlessThanKOPTIMAL(vector<int> arr, int k)
{
    int n = arr.size();
    int sum = 0;
    int start = 0;
    int end = 0;
    int maxLength = 0;
    while (end < n)
    {
        sum += arr[end];
        if (sum >= k) // this is the optimal way to shrink the window coz only 1 iteration is needed to shrink the window
        {
            sum -= arr[start];
            start++;
        }
        maxLength = max(maxLength, end - start + 1);
        end++; // expand the window
    }
    return maxLength;
}

/*************************************************************************/
int numofSubarraysWithSumK(vector<int> &nums, int goal)
{
    return atMost(nums, goal) - atMost(nums, goal - 1);
}
int atMost(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;

    int n = nums.size();
    int l = 0, r = 0;
    int sum = 0, count = 0;
    while (r < n)
    {
        sum += nums[r];
        while (sum > goal)
        {
            sum -= nums[l];
            l++;
        }
        count += (r - l + 1);
        r++;
    }

    return count;
}

int main()
{
}