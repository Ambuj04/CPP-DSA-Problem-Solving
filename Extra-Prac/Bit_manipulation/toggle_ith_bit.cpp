
#include<iostream>
using namespace std;

int main()
{
    int n = 5, i = 1;
    //1 based indexing instead of zero based. In system uses 0th based indexing
    int ans = (n ^ (i-1<<1));
    return 0;
}