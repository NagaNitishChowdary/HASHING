// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/job-sequencing-problem_1169460?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std ;

bool comp(vector<int> a,vector<int> b){
    return a[1] > b[1] ;
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(),jobs.end(),comp) ;
    int maxDeadLine = jobs[0][0] ;
    for(int i=0 ; i<jobs.size() ; i++)
        maxDeadLine = max(maxDeadLine,jobs[i][0]) ;
    int arr[maxDeadLine+1] ; arr[0] = 0 ;
    for(int i=1 ; i<=maxDeadLine ; i++) arr[i] = -1 ;
    int countJobs = 0 , jobProfit = 0 ;
    for(int i=0 ; i<jobs.size() ; i++){
        if(arr[jobs[i][0]] == -1){
            countJobs++ ;
            jobProfit += jobs[i][1] ;
            arr[jobs[i][0]] = 0 ;
        }
        else{
            for(int j=jobs[i][0] ; j>0 ; j--){
                if(arr[j] == -1){
                    countJobs++ ;
                    jobProfit += jobs[i][1] ;
                    arr[j] = 0 ;
                    break ;
                }
            }
        }
    }    
    /*
    for(auto vctr:jobs){
        for(auto it:vctr) cout << it << " " ;
        cout << endl ;
    }
    for(int i=0 ; i<=maxDeadLine ; i++) cout << arr[i] << " " ; cout << endl ;
    */
    return jobProfit ; 
}

int main(){
    int testCases; cin >> testCases ;
    while(testCases--){
        int n; cin >> n ;
        vector<vector<int>> jobs ;
        vector<int> knnc ;
        for(int i=0 ; i<n ; i++){
            int deadLine; cin >> deadLine ;
            knnc.emplace_back(deadLine) ;
        }
        for(int i=0 ; i<n ; i++){
            int pro; cin >> pro ;
            vector<int> knnc1 ;
            knnc1.emplace_back(knnc[i]) ;
            knnc1.emplace_back(pro) ;
            jobs.emplace_back(knnc1) ;
        }
        
        cout << jobScheduling(jobs) << endl ;
    }
}
