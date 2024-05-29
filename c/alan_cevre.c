#include <stdio.h>

float area, environment;
float height, width;

float areaCalc(float height, float width)
{
    return height * width;
}

float environmentCalc(float height, float width)
{
    return 2 * (height + width);
}

void info(){
  printf("\n************************************************************\n");
  printf("* This is a program that calculates the area of rectangle. *");
  printf("\n************************************************************\n");
}

int main()
{   
    info();
    printf("Height: ");
    scanf("%f", &height);
    printf("Width: ");
    scanf("%f", &width);

    area = areaCalc(height, width);
    environment = environmentCalc(height, width);
    printf("-----------------------------------\n");
    printf("area: %.2f\nenvironment: %.2f\n", area, environment);
    return 0;
}