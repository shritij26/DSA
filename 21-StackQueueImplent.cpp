#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;


//Next Greater Element (NGE) is the element which is greater than the current element and is present on the right side of the current element in the array. If there is no greater element on the right side, then the next greater element for the current element is -1.
vector<int> nse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

//Previous Greater Element (PGE) is the element which is greater than the current element and is present on the left side of the current element in the array. If there is no greater element on the left side, then the previous greater element for the current element is -1.
vector<int> pse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

int main()
{
    return 0;
}