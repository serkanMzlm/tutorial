// İki boyutlu dizin içinde bulunan 1'lerin gruplanması
//       a) Sağ, sol, alt, üst kısımdakileri gruplama
//       b) Sağ, sağ alt, sağ üst... temas eden herhangi
//          bir yüzey
// Çözüm: DFS (Depth-First Search)

#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrix = {
    {1, 0, 1},
    {1, 0, 0},
    {0, 0, 1}
};

int cols = matrix.size(); 
int rows = matrix[0].size();

typedef struct
{
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<bool>> visited;
    std::vector<std::pair<int, int>> indices;
    std::vector<std::vector<std::pair<int, int>>> groups;
} DFS_s;

int dRow[4] = {0, 0, -1, 1};
int dCol[4] = {-1, 1, 0, 0};

void dfs(DFS_s &data, int row, int col);

int main(int argc, char** argv)
{
    DFS_s data;
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    data.matrix = matrix;
    data.visited = visited;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Eğer hücre değeri 1 ise ve ziyaret edilmemişse, yeni bir grup başlat
            if (data.matrix[i][j] == 1 && !data.visited[i][j]) {
                dfs(data, i, j);
                data.groups.push_back(data.indices);
                data.indices.clear();
            }
        }
    }

    std::cout << "Toplam grup sayısı: " << data.groups.size() << std::endl;
    for (int i = 0; i < data.groups.size(); i++) {
        std::cout << "Grup " << i + 1 << ": ";
        for (const auto& idx : data.groups[i]) {
            std::cout << "(" << idx.first << ", " << idx.second << ") ";
        }
        std::cout << std::endl;
    }

    return 0;
}

void dfs(DFS_s &data, int row, int col)
{
    data.visited[row][col] = true;
    data.indices.push_back({row, col});

    for(int i = 0; i < 4; i++){
        int newRow = row + dRow[i]; 
        int newCol = col + dCol[i]; 

        bool is_limit = (newCol >= 0 && newCol < cols && newRow >= 0 && newRow < rows);
        if(!is_limit)
        {
            continue;
        } 

        bool is_group = data.matrix[newRow][newCol] && !data.visited[newRow][newCol];
        if(is_group )
        {
            dfs(data, newRow, newCol);
        }
    }
}