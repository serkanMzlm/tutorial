#include <iostream>
#define part1
using namespace std;



#ifdef part1 

int main()
{

int satir=10;

for(int i=0; i<satir;i++)
{
    if(satir/2-i>0)
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

    else
    {
        for(int i=0;i<satir-1;i++)
        {
            cout<<" ";
        }
        cout<<"*"<<endl;
    }
}

}

#endif 


#ifdef part1

int main()
{

int satir=10;
int b,y;

for(int i=0; i<satir;i++)
{
        for(b=0;b<satir-(1+i);b++)
        {
            cout<<" ";
        }
        for(y=0;y<2*i;y++)
        {   
            if(satir/2-i-1<0){
                for(int a=0;a<satir-1-b;a++)
                {
                    cout<<" ";
                }
                break;
            }
            cout<<"*";
        }
        cout<<"*";
        cout<<endl;
}

}

#endif
