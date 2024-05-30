#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int tahmin1 ,tahmin2 , tahmin3 , random ,veri  ;
int main(){
	tekrar :
	cout << "zar kac gelecek [ 3 deger girin] : ";
	cin >> tahmin1 >> tahmin2 >> tahmin3 ;
	srand(time(NULL));
	random = rand()%6+1;
	if (tahmin1 > 0 && tahmin1 <7 && tahmin2 > 0 && tahmin2 <7 &&tahmin2 > 0 && tahmin2 <7 ){
		if (random == tahmin1 ||random == tahmin2||random == tahmin3)
		{
			cout << "Tebrikler Dogru Tahmin" << endl 
				 << "Zar : " << random << endl;
		}
		else
		{
			cout << "Yanlis Tahmin " << endl
				<< "Zar : "<< random << endl;
		}
	}
	else 
	{
		cout << "Gecersiz Islem ";
	}
	cout << "Tekrar Etmek [1] " << endl;
	cin >> veri;
	if (veri == 1){
		goto tekrar;
	}
	
	return 0;
}
