#include <bits/stdc++.h>
using namespace std;

int binary(int n)
{
    if (n == 1)
    {

        return 1;
    }
    if (n == 0)
    {

        return 0;
    }
    string res;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            res += '0';
        }
        else
        {
            res += '1';
        }
        n /= 2;
        if(n==1){
            res += '1';
        }
    }

    reverse(res.begin(), res.end());
    int ans = stoi(res);
    return ans;
}

int decimal(string str){
   int num = 0;
   int multiplyFactor = 1;
    for(int i = str.length()-1 ; i>=0 ; i--){
        if(str[i]=='1'){
            num += multiplyFactor ;
      }
      multiplyFactor *= 2;
    }
    return num;
}
int main()
{
    int n;
    string str;
    cout << "Enter a number :";
    cin >> n;
    cout << binary(n);
    cout<<endl<<"Enter a binary number :";
    cin>>str;
    cout<<decimal(str);

    return 0;
}