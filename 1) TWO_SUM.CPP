// PROBLEM LINK --- https://leetcode.com/problems/two-sum/description/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

#include<bits/stdc++.h>
#define LL long long int
using namespace std;

vector<int> twoSum(vector<int>& vt1, int target) {
    /*
    vector<int>vt2;
    int d,c=0;
    for(int i=0;i<vt1.size();i++){
        d=count(vt1.begin(),vt1.end(),target-vt1[i]);//cout<<d<<endl;
        //c++;
        if(vt1[i]==(target-vt1[i]))
        {
            if(d==2){
                vt2.emplace_back(i);
                //nums.erase(nums.begin()+i);
                vt2.emplace_back(find(vt1.begin()+i+1,vt1.end(),target-vt1[i])-vt1.begin());
                break;
            }
            else{continue;}
            }
        else if(d==1){
            vt2.emplace_back(i);
            vt2.emplace_back(find(vt1.begin()+i+1,vt1.end(),target-vt1[i])-vt1.begin());
            break;
        }
    }
    //cout<<" c is "<<c<<endl;
    return vt2;
    */
    // OPTIMIZED APPROACH --- USES HASH MAP 
    vector<int> ans ; int size = vt1.size() ;
    unordered_map<int,int> mpp ;
    for(int i=0 ; i<size; i++){
        if(mpp.find(target-vt1[i]) != mpp.end()){
            ans.emplace_back(mpp[target-vt1[i]]) ; 
            ans.emplace_back(i) ; return ans ; }
        mpp[vt1[i]] = i ;
    }
    return ans ;
}

int main(int argc,char const *argv[]) {
    LL testCases ; cin >> testCases ;
    while(testCases--){
        int n ; cin >> n ;
        vector<int> vt1(n) ; 
        for(int i=0 ; i<n ; i++) cin >> vt1[i] ;
        int target ; cin >> target ;
        vector<int> ans = twoSum(vt1,target) ;
        for(auto it:ans) cout << it << " " ;
        cout << endl ;
    }
    return 0;  
}


