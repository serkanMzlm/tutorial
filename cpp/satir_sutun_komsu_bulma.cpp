#include <iostream>
#include <cmath>

#define JJ 2
#define II 3
#define DEBUG 0

int count = 0;
int count1 = 0;

int array[3][2] = {{9, 4}, 
                   {6, 3}, 
                   {5, 8}};

//----------------------------
// X | 9 | 4 | 6 | 3 | 5 | 8 |
//---|---|---|---|---|---|---|
// 9 | 0 | 1 | 1 | 0 | 0 | 0 |
// 4 | 1 | 0 | 0 | 1 | 0 | 0 |
// 6 | 1 | 0 | 0 | 1 | 1 | 0 |
// 3 | 0 | 1 | 1 | 0 | 0 | 1 |
// 5 | 0 | 0 | 1 | 0 | 0 | 1 |
// 8 | 0 | 0 | 0 | 1 | 1 | 0 |
// ---------------------------
int control_array[6][6] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 1},
    {0, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0},
};

int answer[6][6];

void control(){
    std::cout << "_________________________________________\n";
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            std::cout << " " << (answer[i][j] == control_array[i][j] ? "True" : "False") << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "_________________________________________\n";
}

void find(int i, int j){
    for(int ii = 0; ii < II; ii++){
        for(int jj = 0; jj < JJ; jj++){
            if(i == ii && j == jj){
#if DEBUG
                std::cout << " 0 (" << i << j << " " << ii << jj <<":" << array[ii][jj] <<  ") ";
#else
                std::cout << " 0 ";
#endif
                answer[count][count1++] = 0;
            }else if((ii == i && abs(jj - j) <= 1) || (j == jj && abs(i - ii) <= 1)){
#if DEBUG
                std::cout << " 1 (" << i << j << " " << ii << jj <<":" << array[ii][jj] <<  ") ";
#else
                std::cout << " 1 ";
#endif
                answer[count][count1++] = 1;
            }else{
#if DEBUG
                std::cout << " 0 (" << i << j << " " << ii << jj <<":" << array[ii][jj] << ") ";
#else
                std::cout << " 0 ";
#endif  
                answer[count][count1++] = 0;
            }
        }
    }
}

int main(){
#if DEBUG 
    std::cout << "X  9            4            6            3            5            8\n";
#else
    std::cout << "X  9  4  6  3  5  8\n";
#endif
    for(int i = 0; i < II; i++){
        for(int j = 0; j < JJ; j++){
            int search = array[i][j];
            std::cout << search << " ";
            find(i, j);
            std::cout << std::endl;
            count++;
        }
    }
    return 0;
}