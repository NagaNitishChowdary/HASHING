// PROBLEM LINK --- https://leetcode.com/problems/4sum/description/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/find-four-elements-that-sums-to-a-given-value_983605?leftPanelTab=0
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > fourSum(vector<int> &arr, int k) {
    // Your code goes here
    // BRUTEFORCE --- SORT THE ARRAY AND USE 3 POINTER + BINARY SEARCH --- ACCEPTED
    /*
    int n = arr.size() ;
    set<vector<int>> st ;
    sort(arr.begin() , arr.end()) ;
    for(int i=0 ; i<n-3 ; i++){
        for(int j=i+1 ; j<n-2 ; j++){
            for(int k1=j+1 ; k1<n-1 ; k1++){
                int knnc = arr[i]+arr[j]+arr[k1] ;
                if(binary_search(arr.begin()+k1+1,arr.end(),k-knnc))
                st.insert({arr[i],arr[j],arr[k1],k-(int)knnc}) ;
            }
        }
    }
    vector<vector<int>> ans ;
    for(auto it:st) ans.push_back(it) ;
    return ans ;
    */
    vector<vector<int>> ans ;
    int n = arr.size() ;
    sort(arr.begin() , arr.end()) ;
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            long long required_target = (long long)k - arr[i] - arr[j] ;
            int front_pointer = j + 1 ;
            int back_pointer = n - 1 ;
            while(front_pointer < back_pointer){
                int two_sum = arr[front_pointer] + arr[back_pointer] ;
                if(two_sum > required_target) back_pointer-- ;
                else if(two_sum < required_target) front_pointer++ ;
                else{
                    // IF THE REQUIRED TARGET == TWO_SUM THEN 
                    int var1 = arr[front_pointer] , var2 = arr[back_pointer] ;
                    ans.push_back({arr[i],arr[j],var1,var2}) ;
                    // PROCESSING THE DUPLICATES OF NUMBER 3 
                    while(front_pointer < back_pointer && arr[front_pointer] == var1) front_pointer++ ;
                    // PROCESSING THE DUPLICATES OF NUMBER 4 
                    while(front_pointer < back_pointer && arr[back_pointer] == var2) back_pointer-- ;
                }
            }
            // PROCESSING THE DUPLICATES OF THE NUMBER 2 
            while(j+1 < n && arr[j+1] == arr[j]) j++ ;
        }
        // PROCESSING THE DUPLICATES OF THE NUMBER 1 
        while(i+1 < n && arr[i+1] == arr[i]) i++ ;
    }
    return ans ;
}

int main() {
    int t ; cin >> t ;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) cin >> a[i] ;
        vector<vector<int> > ans = fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) cout << u << " " ;
            cout << endl ;
        }
        if (ans.empty()) cout << -1 ;
        cout << "\n";
    }
    return 0;
}
