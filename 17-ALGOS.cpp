// Moore Voting Algorithm

/*
Theory:
Moore Voting Algorithm is used to find the majority element in an array.
A majority element is an element that appears more than n/2 times.

Working:
1. Assume the first element as candidate.
2. Increase count if same element appears.
3. Decrease count if different element appears.
4. If count becomes 0, choose new candidate.
5. At the end, candidate will be the majority element.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int MooreVoting()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = 0;
    int element = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            element = arr[i];
        }
        if (arr[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    cout << "Majority Element: " << element << endl;
    return 0;
}

/*****************************************************************************************************************************/

// KADANE'S ALGORITHM

/*
Theory:
Kadane's Algorithm is used to find the maximum sum subarray in an array.
A subarray is a contiguous part of the array.

Working:
1. Traverse the array from left to right.
2. Add the current element to the current sum.
3. Update the maximum sum if current sum becomes greater.
4. If current sum becomes negative, reset it to 0.
5. At the end, maximum sum will be the answer.

Time Complexity: O(n)
Space Complexity: O(1)
*/

int KadaneAlgo()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxi = arr[0];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    cout << "Maximum Subarray Sum: " << maxi << endl;
    return 0;
}

/*****************************************************************************************************************************/

int main()
{
    // MooreVoting();
    KadaneAlgo();
    return 0;
}