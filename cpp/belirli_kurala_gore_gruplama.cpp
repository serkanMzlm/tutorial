/*
 * İki boyutlu dizin içinde bulunan 1'lerin gruplanması
 *       a) Sağ, sol, alt, üst kısımdakileri gruplama
 *       b) Sağ, sağ alt, sağ üst... temas eden herhangi
 *          bir yüzey
 * Çözüm: DFS (Depth-First Search)
*/

#include <iostream>
#include <vector>

using namespace std;
int rows, cols;

// A
void dfs(std::vector<std::vector<int>> &matrix, std::vector<std::vector<bool>> &visited,
                                int row, int col, std::vector<std::pair<int, int>> &indices)
{

    // sağ, sol, alt, üst
    static int directions = 4;
    // Hareket Yönleri (sol, sağ, üst, alt)
    static int dRow[] = {0, 0, -1, 1};
    static int dCol[] = {-1, 1, 0, 0};

    visited[row][col] = true; // Hücre ziyaret edilmiş olarak işaretlenir
    indices.push_back({row, col});

    for (int i = 0; i < directions; i++){
        int newRow = row + dRow[i];
        int newCol = col + dCol[i];

        if (newRow >= 0 && newRow < rows && newCol >= 0 && 
                newCol < cols && matrix[newRow][newCol] == 1 
                                    && !visited[newRow][newCol]) {
                dfs(matrix, visited, newRow, newCol, indices);
            }
    }
}

int main()
{
    std::vector<std::vector<int>> matrix = {
        {1, 0, 0},
        {1, 0, 0},
        {0, 0, 1}
    };

    rows = matrix.size();
    cols = matrix[0].size();

    // Ziyaret edilen hücreleri tutmak için vektör
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Grupları ve indekslerini tutmak için vektör
    vector<vector<pair<int, int>>> groups;

    // Matris üzerindeki her hücreyi gez
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Eğer hücre değeri 1 ise ve ziyaret edilmemişse, yeni bir grup başlat
            if (matrix[i][j] == 1 && !visited[i][j]) {
                vector<pair<int, int>> indices;
                dfs(matrix, visited, i, j, indices);
                groups.push_back(indices);
            }
        }
    }

    // Grupları ve indekslerini yazdır
    cout << "Toplam grup sayısı: " << groups.size() << endl;
    for (int i = 0; i < groups.size(); i++) {
        cout << "Grup " << i + 1 << ": ";
        for (const auto& idx : groups[i]) {
            cout << "(" << idx.first << ", " << idx.second << ") ";
        }
        cout << endl;
    }

    return 0;
}