#include <iostream>

class MyClass{
  private:
    int age;
    std::string name;
  public:
    MyClass();
    MyClass(int age);
    MyClass(int age, std::string name);
    ~MyClass();
    int getAge() const;
    void setAge(int age);
    MyClass *echoName();
    MyClass &echoAge();
};

int age = 10;
std::string name = "Burak";

int main(){
  MyClass person_1;
  MyClass person_2 = {23, "Mert"};
  MyClass person_3(19, "Koray");
  MyClass person_array[3] = {{20, "Murat"}, {20}};

  // Copy Constructors
  MyClass cp_person_1(person_1);
  MyClass cp_person_2 = person_1;

  std::cout <<"person 1 age:" << person_1.getAge() << std::endl;
  person_1.setAge(20);

  person_2.echoName()->echoAge();
  person_2.echoAge().echoName();
  return 0;
}

MyClass::MyClass(){
  this->age = ::age;
  this->name = ::name;
}

MyClass::MyClass(int age){
  this->age = age;
  this->name = ::name;
}

MyClass::~MyClass() { }

MyClass::MyClass(int age = 29, std::string name ) : age(age), name(name){ }

int MyClass::getAge() const { return age; }

void MyClass::setAge(int age){ MyClass::age = age; }

MyClass *MyClass::echoName(){
  std::cout <<"name: " << name << std::endl;
  return this;
}

MyClass &MyClass::echoAge(){
  std::cout << "age: " << age << std::endl;
  return *this;
}
