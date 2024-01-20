#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    typedef long long ll;
    vector<int> get_nsl(vector<int>& arr, int n){
        vector<int> result(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            if(st.empty()){
                result[i] = -1;
            }
            else{
                while(!st.empty() and arr[st.top()] > arr[i]){
                    st.pop();
                }
                result[i] = st.empty()? -1: st.top();
            }
            st.push(i);
        }
        return result;
    }

    vector<int> get_nsr(vector<int>& arr, int n){
        vector<int> result(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                result[i] = n;
            }
            else{
                while(!st.empty() and arr[st.top()] >= arr[i]){
                    st.pop();
                }
                result[i] = st.empty()? n: st.top();
            }
            st.push(i);
        }
        return result;
    }

    int sumSubarrayMins(vector<int>& arr) {
        ll MOD = 1e9+7;
        ll n = arr.size();
        vector<int> left_index, right_index;
        
        left_index = get_nsl(arr, n);
        right_index = get_nsr(arr, n);
        
        ll sum = 0;
        
        for(int i=0; i<n; i++){
            ll left = i - left_index[i];
            ll right = right_index[i] - i;
            sum = (sum + left*right*arr[i])%MOD;
        }
        return sum;
    }
};