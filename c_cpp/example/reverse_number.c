#include <stdio.h>

#define COLOR_RED "\x1b[31m"
#define COLOR_GRN "\x1b[32m"
#define COLOR_RST "\x1b[0m"
#define ERROR(X) printf(COLOR_RED"%s"COLOR_RST"\n",X)

int reverse, number, remainder;

int reverseNumber(int number);
int main(){
	printf("Enter integer:");
	if(!scanf("%d",&number)){
		ERROR("Not enter an integer!");
		return -1;
	}
	
	printf(COLOR_GRN"reverse: %d\n",reverseNumber(number));
	return 0 ;
}

int reverseNumber(int number){
	while (number>0){
		remainder = number%10;
		reverse = reverse*10 + remainder;
		number = number/10;
	}
	return reverse;
}