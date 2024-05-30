#include <iostream>

#define part1
using namespace std;



int main()
{

int satir = 7;
int sutun = 14;
    for(int a=0;a<satir;a++)
    {
        for(int b=0;b<sutun;b++)
        {
            if(a==0||a==satir-1||b==0||b==sutun-1) cout<<"*";
            else  cout<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl<<endl;

    for(int a=0;a<satir;a++)
    {
        for(int b=0;b<sutun;b++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
