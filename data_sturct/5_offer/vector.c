#include <stdio.h>
#include<iostream>
using namespace std;
#include<vector>
int main()
{
   vector< vector<int> > a;
  // vector<int>a;
        int b=5;
    a.push_back(b);
    a.push_back(b);
    a.push_back(b);
    a.push_back(b);
   cout<<a[0][0];
    return 0;
}
