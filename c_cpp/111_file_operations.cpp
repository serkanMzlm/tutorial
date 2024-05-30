#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char yazi[100];
    string yazi2;

    /** ifstream  okuma islemi icin acilir
        ofstream yazma islemi icin acilir
        fstream hem okuma hem de yazma */
    fstream dosya; // dosya adinda nesne  olusturuldu
    dosya.open("deneme.txt", ios::out | ios::in | ios::app);
    /** sirasi ile  yazma okuma ve sonda bulunan app ise dosya
        varsa devamina yazma  saglar.    */
    dosya << "denemeye yazi yazma";
    dosya.close();
    dosya.open("deneme.txt", ios::in);
    dosya >> yazi;
    getline(dosya, yazi2, '\n');
    cout << yazi << endl;
    cout << "---------------------------" << endl;
    cout << yazi2 << endl;
    ;
    cout << "---------------------------" << endl;
    dosya.close();
    return 0;
}
