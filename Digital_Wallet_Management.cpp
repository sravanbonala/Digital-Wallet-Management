#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    int acc[n];
    map<int, int> bal;
    
    for(int i=0; i<n; i++){
        cin>>acc[i];
        cin>>bal[acc[i]];
    }
    
    int t;
    cin>>t;
    while(t--){
        int from, to, amo;
        cin>>from;
        cin>>to;
        cin>>amo;
        
        if(bal[from] >= amo){cout<<"Success\n"; bal[from]-=amo; bal[to]+=amo;}
        else{cout<<"Failure\n";}
    }
    
    //sort by amounts
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(bal[acc[i]]>bal[acc[j]]){
                int temp= acc[i];
                acc[i]=acc[j];
                acc[j]=temp;
            }
        }
    }
    
    cout<<"\n";
    
    //printing accs and amounts
    
    for(int i=0; i<n; i++){
        cout<<acc[i]<<" "<<bal[acc[i]]<<"\n";
    }
    
    
    return 0;
}
