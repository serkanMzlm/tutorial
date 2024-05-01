#include <iostream>
#include <cstring>

typedef struct {
    int age;
    std::string name;
    std::string getName(){
        return name;
    }
    void setAge(int new_age){
        age = new_age;
    }
} Person;

int main(){
    Person person;
    person.age = 10;
    person.name = "mert";
    std::cout <<"Name: " <<  person.getName() << " Age: " << person.age << std::endl;
    person.setAge(123);
    std::cout <<"Name: " <<  person.getName() << " Age: " << person.age << std::endl;
    return 0;
}