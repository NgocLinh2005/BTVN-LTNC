//Cau 1///////
/*
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int pageCount(int n, int p) {
    return min(p/2, (n/2)-(p/2));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
*/

//Cau 2////////////

/*
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


//Complete the 'equalizeArray' function below.

int equalizeArray(vector<int> arr) {
    map <int, int> mp;
    int repeat, check = -1;
    for (int i =0; i<arr.size(); i++)
    {
        if (arr[i]==check) continue;
        else{
            repeat = count(arr.begin(), arr.end(), arr[i]);
            mp.insert(pair<int, int>(arr[i], repeat));
            check = arr[i];
        }
    }
    map <int, int> :: iterator it;
    int erase = INT_MAX;
    for (it = mp.begin(); it != mp.end(); it++ )
    {
        int element = arr.size()-it->second;
        if (element < erase)
        erase = element;
    }
    return erase;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = equalizeArray(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
*/

//Cau 3///////
/*
#include <bits/stdc++.h>

using namespace std;
bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int palindromeIndex(const string& s) {
    int len = s.size();
    for (int i = 0, j = len - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            if (isPalindrome(s, i + 1, j))
                return i;
            if (isPalindrome(s, i, j - 1))
                return j;
            return -1;
        }
    }
    return -1;
}

int main() {
    int q; cin >> q;
    string s;
    for (int i=0; i<q; i++)
    {
        cin >> s;
        cout << palindromeIndex(s) << endl;
    }
    return 0;
}
*/
//Cau 4////
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n, q;
    cin >> n >> q;
    vector <vector<int>> vec(n);
    int num, element;
    for (int a=0; a<n; a++)
    {
        cin >> num;
        for (int b=0; b<num; b++)
        {
            cin >> element;
            vec[a].push_back(element);
        }
    }
   int i, j;
   for (int a=0; a<q; a++)
   {
       cin >> i >> j;
       cout << vec[i][j] << endl;
   }


    return 0;
}
*/
//Cau 5////
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
    int A[n];
    int B[n+1];
    for (int i=0; i<n; i++)
        cin >> A[i];
    for (int i=0; i<n+1; i++)
        cin >> B[i];
    sort(A, A+n);
    sort(B, B+n+1);
    for (int i=0; i<n; i++)
    {
        if (A[i]!=B[i])
        {cout << B[i];
         return 0;}
    }
    cout << B[n];
    return 0;
}
*/

//Cau 6//////
/*
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int getTotalX(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int min_b = b.front();
    int max_a = a.back();

    int multiple = min_b/max_a; cout << multiple << " ";
    int result(0);

    for (int i=1; i<=multiple; i++)
    {   bool flag = true;
        for (int j=0; j<b.size(); j++)
        {
            if (b[j]%(max_a*i)!=0)
            {
                flag = false;
                break;
            }
        }
        for (int k=0; k<a.size(); k++)
        {
            if ((max_a*i)%a[k]!=0)
            {
                flag = false;
                break;
            }
        }

            if (flag) {result++; cout << "Yes" << " "; }
    }
    return result;
}

int main()


{

  string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    cout << total << "\n";


    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
*/
//Cau 7/////

