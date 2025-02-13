#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;

string makePallin(int N)
{
    if(N == 0)
        N+=1;
    string tmp = "";
    for(int i = 0;i < N;i++)
    {
        int rd = rnd.next(0,25);
        tmp += ('a' + rd);
    }
    string ttmp = tmp;
    reverse(tmp.begin(),tmp.end());
    ttmp+=tmp;
    
    return ttmp;
}

string makeWord(int N)
{
    if(N % 2 == 1)
        N++;
    string tmp = "";
    for(int i = 0;i < N;i++)
    {
        int rd = rnd.next(0,25);
        tmp += ('a' + rd);
    }
    return tmp;
}

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	int maxN = stoi(argv[1]);
	int pallinN = stoi(argv[2]);
	int maxLen = 1000;
	
	pallinN = rnd.next(2, pallinN);
	int N = rnd.next(pallinN+1, maxN);
	
	int num = 0;
	int tot = 0;
	vector<string> v;

	for(int i = 0;i < N;i++)
	{
	    int l = rnd.next(2,maxLen);
	    string p = "";
	    if(i < pallinN)
	    {
	        p = makePallin(l / 2);
	    }
	    else
	    {
	        p = makeWord(l); 
	    }
	  
	    num++;
	    v.push_back(p);
	}
	
	cout << (int)v.size() << endl;
	for(auto i : v)
	{
	    cout << i << endl;	
	}

    return 0;
}
