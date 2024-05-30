#include <iostream>
using namespace std;


class State{
private:
  int x;
  int y;
  int z;
  friend void setState(State);
  friend class Number;
  friend void operator - (State &s);
  friend std::ostream &operator<<(std::ostream &os , const State &r) ;
  friend std::istream &operator>>(std::istream &is, State &r);
public:
  State(): x(0), y(0), z(0) {}
  void getState() const {
    cout << "x = "<< this->x << " y = "<<this->y <<"  z = "<<this->z << endl; 
  }
};

std::ostream &operator<<(std::ostream &os , const State &r) {
   return os <<" X: " <<  "[" << r.x << "]"<<endl;
}
std::istream &operator>>(std::istream &is, State &r){
   return is>>r.x;
}


void setState(State s){
  s.x = 10;
  s.y = 20;
  s.z = 30;
  cout << s.x << " " << s.y << " " <<  s.z << endl;
}

void operator-(State &s){
  s.x -= 10;
  s.y -= 20;
  s.z -= 30;
}

class Number{
public:
  void getState(State & s){
    cout << s.x << " " << s.y << " " <<  s.z << endl;
  }
  void setState(State & s){
    s.x = 20;
    s.y = 50;
    s.z = 10;
  }
};

int main(){

  State state;
  Number number;
  state.getState();
  setState(state);
  number.getState(state);
  number.setState(state);
  state.getState();
  -state;
  state.getState();
  cout << state;
  cin >> state;
  cout << state;

  return 0;
}
