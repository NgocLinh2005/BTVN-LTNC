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
    vector <int> v;
    for (int i=0; i<n; i++)
    {
        int x; cin >> x;
        v.push_back(x);
    }
    int pos; cin >> pos;
    int a, b;
    cin >> a >> b;
    v.erase(v.begin()+pos-1);
    v.erase(v.begin()+a-1, v.begin()+b-1);
    cout << v.size() <<"\n";
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
*/

//Cau 4/////

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    vector <int> v;
    for (int i=0; i<n; i++)
    {
        int x; cin >> x;
        v.push_back(x);
    }
    int m; cin >> m;
    int Y[m];
    for (int i=0; i<m; i++)
    {
        cin >> Y[i];
    }
   for (int i = 0; i < m; ++i) {
        auto it = lower_bound(v.begin(), v.end(), Y[i]);
        cout << *it << "\n";
        if (it != v.end() && *it == Y[i]) {
            cout << "Yes " << (it - v.begin() + 1) << endl;
        } else {
            cout << "No " << (it - v.begin() + 1) << endl;
        }
   }
    return 0;
}
