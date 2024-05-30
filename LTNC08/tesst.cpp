#include <bits/stdc++.h>
using namespace std;
int main()
{   string ip1, ip2;
cin >> ip1 >> ip2;
    unordered_set<char> xau1;
    unordered_set<char> xau2;
    for (char c:ip1)
    {
        xau1.insert(c);
    }
    for (char c:ip2)
    {
        xau2.insert(c);
    }
    int len1 = xau1.size();
    int len2 = xau2.size();
    for (auto it = xau1.begin(); it != xau1.end(); ++it)
    cout << *it;
    cout <<endl;
    for (auto it = xau2.begin(); it != xau2.end(); ++it)
    cout << *it;
    cout <<endl;
    return 0;
}
