#include "iostream" //standart fonksiyonların oldugu kütüphane
using namespace std; // std içindiki tüm fonksiyonları  programa dahil ediyoruz 

class sinif { //sınıf tanımı  
	public : //dışardan erişilebilir alan 
		int x,y;
		void degerler(int X , int Y)
	{
		x = X; // alınan degerleri atama yapılıyor  
		y = Y;
	}
		void goster(){ // x ve y degerleri ekranda gösterme 
		cout << "X = " << x << endl;
		cout << "Y = " << y << endl;	
	}
};
int main ()
{
	sinif nesne; //nesne tanımlıyoruz 
	sinif* nesne2;
	sinif* nesne3;
	nesne3 = new sinif(); // bellekte yeni alan almak 
	nesne2 = &nesne; //nesen pointer adresini nesne ikiye aktarımı 
	nesne.degerler(1,5);
	nesne.goster();
	nesne2->degerler(10,50);
	nesne2->goster();
	nesne3->degerler(100,500);
	nesne3->goster();
	return 0;
}
