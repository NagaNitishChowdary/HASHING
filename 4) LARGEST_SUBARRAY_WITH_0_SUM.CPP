// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/longest-subarray-zero-sum_757507

#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int>&A, int n)
{   
    // Your code here
    unordered_map<int,int> mpp ;
    // prefixSum , index 
    int sumi = 0 , maxi = 0 ;
    for(int i=0 ; i<n ; i++){
        sumi += A[i] ;
        if(sumi == 0) maxi = i+1 ;
        if(mpp.find(sumi) != mpp.end()){
            maxi = max(maxi , i-mpp[sumi]) ;
        }
        else mpp[sumi] = i ;
    }
    return maxi ;
}

int main(){
    int t ; cin >> t ;
    while(t--){
        int m ; cin >> m ;
        vector<int> array1(m) ;
        for (int i = 0; i < m; ++i) cin >> array1[i] ;
        cout << maxLen(array1,m) <<endl;
    }
    return 0; 
}
