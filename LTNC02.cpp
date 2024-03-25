//Cau 1///
/*
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

//Complete the 'findDigits' function below.

int findDigits(int n) {
    int m = n;
    int count(0);
    int digit;
    while (m!=0)
    {
        digit = m%10;
        if (digit!=0){
        if(n % digit == 0) count ++;}
        m/=10;
    }
    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        int result = findDigits(n);

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
*/

//Cau 2///////
/*
#include <bits/stdc++.h>

using namespace std;

 // Complete the 'kangaroo' function below.
 // The function is expected to return a STRING.

string kangaroo(int x1, int v1, int x2, int v2) {
    if (v1==v2) return "NO";
    int k=(x2-x1)/(v1-v2);
    if (k*(v1-v2)==(x2-x1)&&k>0) return "YES";
    return "NO";

}

int main()
{
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    string result = kangaroo(x1, v1, x2, v2);
    cout << result << "\n";
    return 0;
}

*/
//Cau 3/////////
/*
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

 // Complete the 'divisibleSumPairs' function below.

int divisibleSumPairs(int n, int k, vector<int> ar) {
    int count(0);
      for (int i=0; i<n-1; i++)
      for (int j=i+1; j<n; j++)
      {
          if ((ar[i]+ar[j])%k ==0) count++;
      }
      return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split(rtrim(ar_temp_temp));

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = divisibleSumPairs(n, k, ar);

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

