class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nextGreater(10001,-1);
        stack<int> st;

        for(int i = nums2.size()-1; i >= 0; i--){
            int val = nums2[i];
            while(!st.empty() && st.top() <= val){
                st.pop();
            }
            nextGreater[val] = st.empty() ? -1 : st.top();
            st.push(val);
        }
        vector<int> ans;
        ans.reserve(nums1.size());
        for(int val : nums1){
            ans.push_back(nextGreater[val]);
        }
        return ans;
    }
};