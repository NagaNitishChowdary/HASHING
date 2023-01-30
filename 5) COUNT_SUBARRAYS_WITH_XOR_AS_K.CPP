// PROBLEM LINK --- https://www.interviewbit.com/problems/subarray-with-given-xor/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/count-subarrays-with-given-xor_1115652
// EXPLANATION LINK --- https://www.geeksforgeeks.org/count-number-subarrays-given-xor/

#include <bits/stdc++.h> 
using namespace std ;

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    unordered_map<int,int> mpp ;
    int xorr = 0 , cnt = 0 ;
    int size = arr.size() ;
    for(int i=0 ; i<size ; i++){
        xorr ^= arr[i] ;
        if(xorr == x) cnt++ ;
        int y = xorr^x ;
        if(mpp.find(y) != mpp.end()) cnt += mpp[y] ;
        mpp[xorr]++ ;
    }
    return cnt ;
}

int main(){
    int t ; cin >> t ;
    while(t--){
        int m , x ; cin >> m >> x ;
        vector<int> arr(m) ;
        for (int i = 0; i < m; ++i) cin >> arr[i] ;
        cout << subarraysXor(arr,x) <<endl;
    }
    return 0; 
}
