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
    
    //1 create name
    set<string> duplName;
    vector<string> names;
    for(int i = 1;i<=k;i++){
        int c = rnd.next(1,21);
        string name;
        do{
            name = "";
            for(int j = 1;j<=c;j++){
                name += (char)(97 + rnd.next(0,25));
            }
        }while(duplName.find(name) != duplName.end());
        duplName.insert(name);
        names.push_back(name);
    }
    
    //2 create letters
    vector<string> letters;
    
    string sumletter = "";
    while(sumletter.size() <= MAX * n) {
        int c = rnd.next(0,k + k);
        if(c >= k){
            sumletter += '.';
        }
        else {
            sumletter += names[c];
        } 
    }
    string temp ="";
    for(int i = 0;i<=MAX*n;i++){
        if(i!=0 && i%MAX ==0){
            letters.push_back(temp);
            temp = "";
        }
        temp += sumletter[i];
    }
    
    
    //3 print letter
    for(auto letter : letters){
        cout<<letter<<endl;
    }
    cout<<k<<endl;
    
    //4 print name
    for(auto name : names){
        cout<<name<<endl;
    }
    return 0;
}
