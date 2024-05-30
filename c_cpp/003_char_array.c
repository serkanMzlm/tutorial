#include <stdio.h>
#include <string.h>

char char_array[] = {'A', 'B', 'C'};
char name[30];
char* surname = "Mazlum";
char county[3][10] = {"Ankara", "Antalya", "Bursa"};
char word1[20]= "asdfgh" ;
char word2[20]= "zxcvbn" ;

int main() {
  
  /* Bu kısımda name[] bellek alanıda okunacaktır. Bunun nedeni 
  * karakter dizilerinin son elamnı "\0" dır. "char_array" bellek
  * alanında \0 konulmadığı için ve bir sonraki bellek alnıda char 
  * ise bir sonraki bellek alanınıda okur. */
  printf("%s\nWhat is your name:", char_array);
  scanf("%s",name);  //char dizinleri bir pointer adresi tutuğu için & konulmaz
  printf("name: %s\n", name); 
  puts(county[1]);

  printf("wort1 : %s\tword2 : %s\n",word1,word2);
	strcat(word1,word2); // ikinçiyi birincinin sonuna ekler
	printf("word1 : %s\tword2 : %s\n",word1,word2);
	strcpy(word2,word1); // ikinçiyi birinciye kopyalar
	printf("word1 : %s\tword2 : %s\n",word1,word2);

	if(strcmp(word1,word2)){ printf("not equal\n"); }
	else  printf("equal\n");

	char* siple =strchr(word1,'m'); // m harfini arar ve ondan sonraki kısmı yazar 
	char* mixed =strrchr(word1,'m'); // sondan m harfini arar  ve oraya kadar olan kısmı yazar
	puts(siple);//ekrana  yazma
	puts(mixed);
  return 0;
}