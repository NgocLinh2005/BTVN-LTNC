
//Cau 1:////////
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
    cin >> a >> b;
    cout << a.size() << " " << b.size() << endl;
    cout << a+b << endl;
    swap(a[0],b[0]);
    cout << a << " " << b;

    return 0;
}*/

//Cau 2:////////
/*
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

void staircase(int n) {
    for (int i=1; i<=n; ++i){
    for (int j=n-i; j>0; --j)
    {
        cout << " ";
    }
    for (int k=1; k<=i; k++)
    {
        cout << "#";
    }
    cout << endl;

}}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    staircase(n);

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
}*/

//Cau 3:////////////////////
/*

#include <bits/stdc++.h>

using namespace std;


string timeConversion(string s) {
     int hh = stoi(s.substr(0,2));
     if (s[8]=='P')
    {

         if (hh!=12)
         s.replace(0,2,to_string(hh+12));
    }
      else {
        if (hh==12)  s.replace(0,2,"00");
      }
      s.erase(s.begin()+8, s.begin()+10);
      return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}*/

//Cau 4:////////////
/*
#include <bits/stdc++.h>

using namespace std;

int camelcase(string s) {
    int count(0);
    for (char c:s)
    if (isupper(c)) count ++;

    return count+1;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
*/

//Cau 5://///////
/*
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string hackerrankInString(string s) {
    string s1 = "hackerrank";
    int len1=s1.size();

    int j=0;
    int count=0;
    int len=s.size();
    for(int i=0;i<n;i++){
        if(s[i]==s1[j]){
            count++;
            j++;}}
    if(count==len1)
        return "YES";
    else
        return "NO";         ;

}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);
        cout << result <<"\n";
        //fout << result << "\n";
    }

    //fout.close();

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
//Cau 6:///////////
/*
#include <bits/stdc++.h>
using namespace std;

 string caesarCipher(string s, int k) {
    char base;
    for (char &c:s)
    {  if(isalpha(c))
    {
        base = islower(c) ? 'a' : 'A';
        c = (c-base+k)%26+base;
    }
    }
    return s;
}
int main()
{   int len; cin >> len;
    string s;
    cin >> s;
    int k; cin >> k;
    if (s.size()==len)
    {
        s = caesarCipher(s, k);
    }
    cout << s;
    return 0;

}
*/

