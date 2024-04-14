#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    vector <wstring> m1 = {L"mạng", L"và", L"khoa", L"học", L"máy", L"tính"};
    vector <wstring> m3 = {L"hệ", L"thống", L"thông", L"tin"};
    vector <wstring> m2 = {L"công", L"nghệ", L"phần", L"mềm"};
    int n;
    wcin >> n;
    fflush(stdin);
    wstring input;
    
    for (int i = 0; i < n; i++)
    {   

        fflush(stdin);
        wcin >> input;
        //wcout << input;
        for(wstring x : m1)
        {
            if(input == x)
                wcout << 1;
        }
        for(wstring x : m2)
        {
            if(input == x)
                wcout << 2;
        }
        for(wstring x : m3)
        {
            if(input == x)
                wcout << 3;
        }
        
    }
    
}