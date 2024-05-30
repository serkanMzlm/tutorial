#include <stdio.h>

typedef enum
{
  STATE_X,
  STATE_Y,
  STATE_Z,
  STATE_ALL
} State_t;

State_t state_t;

struct People
{
  char name[20];
  int age;
  float weight;
};

typedef struct
{
  char name[20];
  int age;
  float weight;
} People_2;

// Bellekte sadece bir alan ayırıp bu alana x y z veya state[] ile
// erişilebilir state[] verilerine enum verileri ile erişilebilir.
typedef union
{
  struct
  {
    int x;
    int y;
    int z;
  };
  int state[STATE_ALL];
} State_s;

struct People people = {"Ali", 35, 70.0}; // İlk değer ataması
People_2 *people_2 = {"mert", 10, 40};    // typedef olduğu için struct yazmaya gerek yok
State_s state_1 = {1, 2, 4};

int main()
{
  printf("name: %s\n", people.name);
  printf("name: %s\n", people_2->name); // pointer olduğu için -> ile erişilir.
  printf("name: %s\n", (*people_2).name);
  printf("state: %d - %d - %d\n", state_1.x, state_1.y, state_1.z);
  printf("state: %d - %d - %d\n", state_1.state[STATE_X], state_1.state[STATE_Y], state_1.state[STATE_Z]);

  return 0;
}