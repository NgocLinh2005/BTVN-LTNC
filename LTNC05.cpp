//Cau 1////////
/*
#include <stdio.h>
#include <cmath>
void update(int *a,int *b) {
    long tmp = *a;
    *a = *a + *b;
    *b = sqrt((*b-tmp)*(*b-tmp));
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}*/
//Cau 2//////////
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i=0; i<n; i++)
    {   int x;
        cin >> x;
        v.push_back(x);
    }
    sort (v.begin(), v.end());
    for (int i=0; i<n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
*/
//Cau 3/////////

