#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main(){
	int random;
	srand (time(NULL)); // random sayiyimizin baslangicini  sistem zamanindan baslatir

	for (int i = 0 ; i <5 ; i++){
		random = rand()/100; // bu sayi cok büyük oldugundan 100 bolerek aliyoruz
		cout << random << endl;
	}
	
	return 0;
}
