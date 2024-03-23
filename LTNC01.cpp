//Cau 1///
/*
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    printf("Hello, World!");
    return 0;
}
*/
//Cau 2//////
/*
#include <iostream>
using namespace std;


int main() {
   int a, b, c;
   cin >> a >> b >> c;
   cout << a+b+c;
    return 0;
}
/*
//Cau 3////
/*
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
    int a;
    long b;
    char c;
    float d;
    double e;
    cin >> a >> b >> c >> d >> e;
    cout << a << '\n' << b << '\n' << c << '\n'
    <<fixed<<setprecision(3)<< d << '\n'
    <<fixed<< setprecision(9)<< e;
    return 0;
}
*/
//Cau 4///////
/*
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr[] = {"one", "two", "three", "four", "five", "six", "seven", "eight","nine", "Greater than 9"};
    if(n>9) cout << arr[9];
    cout << arr[n-1];

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

//Cau 5//////////
/*
#include <iostream>
#include <cstdio>
using namespace std;


int max_of_four(int a, int b, int c, int d)
{
    int arr[4]={a,b,c,d};
    int max =a;
    for (int i=0; i<4;i++)
    {
        if (arr[i]>=max) max=arr[i];
    }
    return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    return 0;
}
*/

//Cau 6///////
/*
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) cin >> arr[i];
    for (int i=0; i<n; i++) cout << arr[n-i-1] << " ";
    return 0;
}
*/
//Cau 7//////////
/*
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


void plusMinus(vector<int> arr) {
    double arrCount[3]={0, 0, 0};
    double len = arr.size();
    for (int i=0; i<len; i++)
    {
        if (arr[i]<0) arrCount[1]++;
        else if (arr[i]==0) arrCount[2]++;
        else arrCount[0]++;
    }
    for (int i=0; i<3; i++)
    cout << fixed << setprecision(6) << arrCount[i]/len <<"\n";

}

int main()
{
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

    plusMinus(arr);

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

//Cau 8////////
/*
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

string balancedSums(vector<int> arr) {
    int len = arr.size();
    int sum(0);
    for (int num : arr)
    sum += num;
    int sumLeft(0), sumRight;
    for (int i=0; i<len; i++)
    {
        sumRight = sum - sumLeft - arr[i];
        if (sumLeft == sumRight) return "YES";
        sumLeft += arr[i];
    }
    return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
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

        string result = balancedSums(arr);

        fout << result << "\n";
    }

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

