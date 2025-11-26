#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> matrix_to_list(vector<vector<int>>& adjacency_matrix);

int main(){
    int n;
    
    cout << "Введите количество вершин графа (размер матрицы): ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Ошибка: размер матрицы должен быть положительным числом!" << endl;
        return 1;
    }
    
    vector<vector<int>> adjacency_matrix(n, vector<int>(n));
    
    cout << "Введите матрицу смежности " << n << "x" << n << " (построчно, через пробел):" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << "Строка " << (i + 1) << ": ";
        for (int j = 0; j < n; j++) {
            cin >> adjacency_matrix[i][j];
        }
    }
    
    cout << "\nВведенная матрица смежности:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    vector<pair<int, int>> list_of_edges = matrix_to_list(adjacency_matrix);
    
     for (const auto& edge : list_of_edges) {
        cout << edge.first << " -> " << edge.second << endl;
     }
    return 0;
    }

    vector<pair<int, int>> matrix_to_list(vector<vector<int>>& adjacency_matrix) {
    int n = adjacency_matrix.size();
    vector<pair<int, int>> result;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { 
            if (adjacency_matrix[i][j] == 1) {
                result.push_back({i, j});
            }
        }
    }
    
    return result;
}

