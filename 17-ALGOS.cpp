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

// NEXT PERMUTATION

/*
Theory:
Next Permutation is used to find the next lexicographically greater arrangement
of elements in an array.

Working:
1. Traverse from right and find the first index 'i' such that arr[i] < arr[i+1].
   This is called the breakpoint.
2. If no breakpoint exists, reverse the entire array because it is the last permutation.
3. Traverse from the right again and find the first element greater than arr[i].
4. Swap arr[i] with that element.
5. Reverse the part of the array after index i.
6. The resulting array is the next permutation.

Time Complexity: O(n)
Space Complexity: O(1)
*/

int NextPermutation()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int index = -1;

    // Find breakpoint
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }

    // Last permutation
    if (index == -1)
    {
        reverse(arr.begin(), arr.end());

        cout << "Next Permutation: ";
        for (int x : arr)
        {
            cout << x << " ";
        }
        cout << endl;

        return 0;
    }

    // Find element just greater than arr[index]
    for (int i = n - 1; i > index; i--)
    {
        if (arr[i] > arr[index])
        {
            swap(arr[i], arr[index]);
            break;
        }
    }

    // Reverse remaining part
    reverse(arr.begin() + index + 1, arr.end());

    cout << "Next Permutation: ";
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

/*****************************************************************************************************************************/

// SIEVE OF ERATOSTHENES

/* Theory: The Sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to a given limit. It works
 by iteratively marking the multiples of each prime number as composite. */

int SieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    cout << "Prime numbers up to " << n << ": ";
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}

/*****************************************************************************************************************************/ 

int main()
{
    // MooreVoting();
    // KadaneAlgo();
    // NextPermutation();
    // SieveOfEratosthenes();
    return 0;
}