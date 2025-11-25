#include<iostream>
#include<vector>

using namespace std;

int count_edges(const vector<vector<int>>& adjacency_matrix);

int main() {
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
    
    int edges = count_edges(adjacency_matrix);
    
    cout << "\nКоличество ребер в графе: " << edges << endl;
    
    return 0;
}

int count_edges(const vector<vector<int>>& adjacency_matrix){
    int edges_count = 0;
    int n = adjacency_matrix.size();
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++){
            if (adjacency_matrix[i][j] == 1){
                edges_count ++;
            }
        }
    }
    return edges_count;
}
