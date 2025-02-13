#include "testlib.h"
#include <iostream>
#include <set>
#include <vector>

#define MAX 300
using namespace std;
 
vector<pair<int,int>> v;
 
int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
 
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int k = atoi(argv[3]);
    cout << n <<endl;
    cout << m <<endl;
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<MAX;j++){
            cout<<"a";
        }
        
        cout<<endl;
    }
    
    
    cout<<k<<endl;
    
    for(int i = MAX;i>MAX-k;i--){
        for(int j = 1;j<=i;j++){
            cout<<"a";
        }
        cout<<endl;
    }
    return 0;
}
