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
    int l = atoi(argv[4]);
    cout << n <<endl;
    cout << m <<endl;
    
    //create letters
    vector<string> letters;
    
    string sumletter = "";
    while(sumletter.size() <= MAX * n) {
        int c = rnd.next(0,1);
        if(c==1) sumletter += "a";
        else sumletter += "b";
         
    }
    string temp ="";
    for(int i = 0;i<=MAX*n;i++){
        if(i!=0 && i%MAX ==0){
            letters.push_back(temp);
            temp = "";
        }
        temp += sumletter[i];
    }
    
    
    //print letter
    for(auto letter : letters){
        cout<<letter<<endl;
    }
    cout<<k<<endl;
    
    set<string> nameSet;
    for(int i = 1;i<=k;i++){
        string name = "";
        do{
            name = "";
            int len = rnd.next(1,l);
            for(int j = 1;j<=len;j++){
                int c = rnd.next(0,1);
                if(c==1) name += "a";
                else name += "b";
            }
        }while(nameSet.find(name)!=nameSet.end());
        
        nameSet.insert(name);
        
        cout<<name<<endl;
    }
    return 0;
}
