#include <iostream>
#include <vector>
using namespace std;

void display(const vector<int> &value, void(*func)(int));
void echo(int a);

int main(){
  vector<int> deger = {1,2,3,4,5,9,89};
  display(deger,echo);
  display(deger,[](int value) {cout<<"value: "<<value<<endl;}); //lamda ile de yapılabilir.
}


void display(const vector<int> &value, void(*func)(int)){
    for(int value:value){  func(value);   }
}

void echo(int a){  cout<<"value:"<<a<<endl; }
