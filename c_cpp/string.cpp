#include <iostream>

using namespace std;

int main(){
    string  string1 = "an unnecessary sentence";
    if(string1.empty()==0){ // "empty" string icinde bir veri varsa "0" yoksa "1" degeri dondurur
        cout << string1.at(3) <<endl;//3. indiste bulunan karakteri gosterir
        cout << string1.length() <<endl;//"length" stirngin uzunlugunu gosterir bosluklarida sayar.
        cout << string1 <<endl;
        cout << string1.find("den") <<endl; /**stingin icinde kelime harf aramamiza yarar
        cikan veri bize o kelime yada harfin basladigi indisi gosterir. eger cikan sayi cok yuksekse bu aradigimiz
        kelimeninn string icinde olmadigini gosterir. İkinci parametre olrak basliyicagi indisi verilebilir.*/

        cout << string1.find_last_of("den") << endl; //bu sefer sondan basa dogru arama yapar.
        string1.insert(0,"Bu",3); /* stringin stedigimiz kismina ekleme yapar. ilk parametre baslangic adresi ikinci
        parametre eklenecek  ucuncu parametre ise uzunluk*/
        
        string1.erase(0,3);//silmek istedigimiz indis araligini belirtiriz
        cout<<string1<<endl;
        string1.clear();// stingin icinde bulunan veriyi siler.
        cout<<string1.empty()<<endl;//bize 1 ciktisini veriri yane ici bos oldugunu gosterir
    }

    string str = "Ankara";
    string1 = str.substr(2,3);//str icinden secilen kismi string1 yerlestirir.
    cout<<string1;

    return 0;
}
