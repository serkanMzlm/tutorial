
#include <iostream>
using namespace std;



int main()
{

int satir=10;

for(int i=0; i<satir;i++)
    {
        for(int b=0;b<satir-(1+i);b++)
        {
            cout<<" ";
        }
        for(int y=0;y<2*i+1;y++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}



















