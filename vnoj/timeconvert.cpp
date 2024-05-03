#include<bits/stdc++.h>
using namespace std;
struct Timer
{
    int h;
    int m;
    int s;
    bool is24h;
};
void convert(struct Timer &time, string tgian)
{
    string timeformat;
    for(int i = 8; i < tgian.length(); i++  )
    {
        timeformat.push_back(tgian[i]);
    }
    string hours;
    string min;
    string sec;
    for(int i = 0; i < 2; i++  )
    {
        hours.push_back(tgian[i]);
    }
    for(int i = 3; i < 5; i++  )
    {
        min.push_back(tgian[i]);
    }
    for(int i = 6; i < 8; i++  )
    {
        sec.push_back(tgian[i]);
    }
    if(timeformat == "PM" && stoi(hours) > 12)
    {
        time.h = stoi(hours) + 12;
    }
    else
        time.h = stoi(hours);
    time.m = stoi(min);
    time.s = stoi(sec);
}
int main()
{
    struct Timer time;
    string tgian;
    cin >> tgian;
    convert(time, tgian);
    if(time.h < 10)
        cout << '0' <<time.h << ':' ;
    else
        cout <<time.h << ':' ;
    if(time.m < 10)
        cout << '0' <<time.m << ':' ;
    else
        cout <<time.m << ':' ;
    if(time.s < 10)
        cout << '0' <<time.s ;
    else
        cout <<time.s ;
}