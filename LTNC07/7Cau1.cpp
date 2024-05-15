#include <bits/stdc++.h>
using namespace std;
int BinarySearch (int arr[], int x, int start_, int end_ )
{
    int k = (start_+end_)/2;

    if (arr[k] == x) return k;
    if (k==end_) return -1;

    if (x<arr[k])
    {
        BinarySearch(arr, x, start_, k-1);
    }
    else
    {
        BinarySearch(arr, x, k+1, end_);
    }

}

int main()
{
    int arr[7] = {2, 3, 6, 7, 10, 11, 18};
    cout << BinarySearch(arr, 10, 3, 6) << endl;
    cout << BinarySearch(arr, 2, 3, 7) << endl;
    return 0;
}
