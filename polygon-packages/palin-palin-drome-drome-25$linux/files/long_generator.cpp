#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
    
    string a = "";
    string b = "";
    
    for(int i = 0;i < 50000000;i++)
    {
        a+="a";
        b+="b";
    }
	
    cout << 2 << endl;
	cout << a << endl;
	cout << b << endl;
 
    return 0;
}
