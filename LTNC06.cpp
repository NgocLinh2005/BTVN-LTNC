//Cau 1/////
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Student
{
    int age;
    string first_name;
    string last_name;
    int standard;
};

int main() {
    Student st;

    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;

    return 0;
}
*/
//Cau 2////
/*
#include <iostream>
#include <sstream>
using namespace std;

class Student
{
    private:

    int age, standard;
    string first_name, last_name;

    public:

    void set_age(int a) { age = a; }
    void set_standard(int a) { standard = a; }
    void set_first_name(string a) { first_name = a; }
    void set_last_name(string a) { last_name = a; }

    int get_age() { return age; }
    int get_standard() { return standard; }
    string get_first_name() { return first_name; }
    string get_last_name() { return last_name; }

    void to_string()
    {
        cout << age << "," << first_name << "," << last_name << "," << standard;
    }
};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    st.to_string();

    return 0;
}
*/

//Cau 3/////
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
class Student
{
  public:
  int a, b, c, d, e;
  void input()
  {
      cin >> a >> b >> c >> d >> e;
  }
  int calculateTotalScore()
  {
      return a+b+c+d+e;
  }
};
// Write your Student class here

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}
*/
//Cau 4///
/*
#include<bits/stdc++.h>

using namespace std;

class Box
{   private:

    int l, b, h;

    public:

    Box()
    {
        l=0;
        b=0;
        h=0;
    }
    Box(int length,int breadth,int height)
    {
            l=length;
            b=breadth;
            h=height;
    }
    Box(const Box& B)
    {
            l=B.l;
            b=B.b;
            h=B.h;
    }

    int getLength() { return l; }
    int getBreadth () { return b; }
    int getHeight ()  { return h; }

    friend bool operator<(Box& A, Box& B){
    if( (A.l < B.l) || ((A.b < B.b) && (A.l == B.l)) || ((A.h < B.h) && (A.l == B.l) && (A.l== B.b)) )
    {
        return true;
    }
     else { return false;}
    }
    friend ostream& operator<< (ostream& output, const Box& B){
    output<< B.l<<" "<<B.b<<" "<<B.h;
    return output;
    }

    long long CalculateVolume()
    {
        return (long long) l*b*h;
    }

};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
*/
