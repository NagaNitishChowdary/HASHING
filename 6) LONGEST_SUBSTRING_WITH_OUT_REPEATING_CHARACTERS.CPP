// PROBLEM LINK --- https://leetcode.com/problems/longest-substring-without-repeating-characters/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/longest-substring-without-repeating-characters_758894?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std ;

int lengthOfLongestSubstring(string s) {
    // BETTER APPROACH
    // TC : O(2*N)
    /*
    int size = s.size() ;
    int l=0 , r=0 ;
    int maxi = 0 ;
    set<int> st ;
    while(r<size){
        if(st.count(s[r]) == 0){
            maxi = max(maxi , r-l+1) ;
            st.insert(s[r]) ;
            r++ ;
        }
        else{
            while(st.count(s[r])>0){
                st.erase(s[l]) ;
                l++ ;
            }
        }
    }
    return maxi ;
    */
    // MOST OPTIMIZED APPROACH 
    // TC : 0(N) 
    int size = s.size() ;
    vector<int> mpp(256,-1) ;
    // OR WE CAN CREATE MAP 
    int left = 0 , right = 0 ;
    int maxi = 0 ;
    while(right<size){
        if(mpp[s[right]] != -1) left = max(mpp[s[right]]+1,left) ;
        mpp[s[right]] = right ;
        maxi = max(maxi , right-left+1) ;
        right++ ;
    }
    return maxi ;
}

int main(){
    int t ; cin >> t ;
    while(t--){
        string s ; cin >> s ;
        cout << lengthOfLongestSubstring(s) << endl;
    }
    return 0; 
}
