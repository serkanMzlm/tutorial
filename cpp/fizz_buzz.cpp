#include <iostream>
using namespace std;

string five[] = {"buzz", "\0", "\0", "\0", "\0"};
string three[] = {"fizz", "\0", "\0"};

int game(int n){
    for(int i = 1; i <= n; i++){
        if(i % 3 == 0 || i % 5 == 0){
            std::cout << " " << five[i%5] << three[i%3];
            continue;
        }
        cout << " " << i;
    }
}


int main(){

    game(29);
    cout << endl;

}