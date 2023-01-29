// PROBLEM LINK --- https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h> 
using namespace std ;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st ;
    int size = nums.size() ;
    for(auto it:nums) st.insert(it) ;
    int maxi = 0 ;
    for(auto it:nums){
        if(st.count(it-1)) continue ;
        // else case
        int knnc= it , c = 0 ;
        while(st.count(knnc++)) c++ ;
        maxi = max(maxi , c) ;
    }
    return maxi ;
}

int main(){
    int testCases ; cin >> testCases;
    while(testCases--){
        int n ; cin >> n ;
        vector<int> nums(n) ;
        for(int i=0 ; i<n ; i++) cin >> nums[i] ;
        cout << longestConsecutive(nums) << endl ;
    }
}
