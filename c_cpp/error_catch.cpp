#include <iostream>

using namespace std;

int main(){
  tekrarla:
  try { //hatanin olabilecegi alan
    int sayi1, sayi2;
    cout<<"boluneni girin : ";
    cin>>sayi1;
    cout<<"boleni girin : ";
    cin>>sayi2;
    if(sayi2==0)   throw 101; //hata oldugunda   catch gitmemizi saglar
    cout<<"sonuc : "<<sayi1/float(sayi2);
  }

  catch (int hatakodu){ //hata durumunda yapilacak
  cout<<"Bolen '0' olamaz ..."<<endl;
  goto tekrarla;
  }
  
  return 0;
}
