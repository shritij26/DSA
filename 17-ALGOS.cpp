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

// BELLMAN-FORD ALGORITHM

/*
Theory:
Bellman-Ford Algorithm is used to find the shortest distance from a source node
to all other nodes in a graph.

Unlike Dijkstra's Algorithm, Bellman-Ford works even when the graph contains
negative edge weights.

Why Bellman-Ford?
1. Handles negative edge weights.
2. Detects negative weight cycles.
3. Works for both directed and undirected graphs.

Where Dijkstra Fails:
If a graph contains negative edges or a negative cycle, Dijkstra may produce
incorrect results because it assumes once a node gets the shortest distance,
it will never improve.

Negative Cycle:
A cycle whose total edge weight is negative. Traversing such a cycle repeatedly
keeps reducing the path cost indefinitely.

Intuition:
1. Initialize source distance as 0 and all others as infinity.
2. Relax all edges V-1 times.
3. Relaxation means updating a node's distance if a shorter path is found.
4. After V-1 iterations, shortest paths are guaranteed.
5. Perform one more relaxation.
6. If any distance still decreases, a negative cycle exists.

Time Complexity: O(V * E)
Space Complexity: O(V)
*/

int BellmanFord()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    int S;
    cin >> S;

    vector<int> dist(V, 1e8);
    dist[S] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
        {
            cout << "Negative Weight Cycle Detected" << endl;
            return 0;
        }
    }

    cout << "Shortest Distances from Source " << S << ": ";
    for (int d : dist)
    {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}

/*****************************************************************************************************************************/

// FLOYD-WARSHALL ALGORITHM

/*
Theory:
Floyd-Warshall Algorithm is used to find the shortest distance between every
pair of nodes in a graph.

Unlike Dijkstra and Bellman-Ford, it finds shortest paths between ALL pairs
of nodes, not just from one source.

Intuition:
1. Start with the given distance matrix.
2. Treat every node as an intermediate node one by one.
3. Check if going through that node gives a shorter path.
4. Update the distance if a shorter path is found.
5. After considering all nodes, the matrix contains shortest distances
   between every pair of nodes.

Time Complexity: O(V^3)
Space Complexity: O(V^2)
*/

int FloydWarshall()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][k] == -1 || matrix[k][j] == -1)
                {
                    continue;
                }

                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
                else
                {
                    matrix[i][j] = min(matrix[i][j],
                                       matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    cout << "Shortest Distance Matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*****************************************************************************************************************************/

// Subarray sum equal to k

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;
    int prefix = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        prefix = prefix + nums[i];
        if (prefixSumCount.find(k) != prefixSumCount.end())
        {
            cnt = cnt + prefixSumCount[k];
        }
        prefixSumCount[prefix]++;
    }
    return cnt;
}

/*****************************************************************************************************************************/

int main()
{
    // MooreVoting();
    // KadaneAlgo();
    // NextPermutation();
    // SieveOfEratosthenes();
    // BellmanFord();
    // FloydWarshall();
    // subarraySum();
    return 0;
}