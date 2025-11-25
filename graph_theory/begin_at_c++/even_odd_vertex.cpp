#include<iostream>
#include<vector>

using namespace std;

int even_count(vector<vector<int>>& adjacency_matrix);

int odd_count(vector<vector<int>>& adjacency_matrix);

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
    
    int even_vertex = even_count(adjacency_matrix);
    int odd_vertex = odd_count(adjacency_matrix);
    
    cout << "\nКоличество вершин с четными степенями: " << even_vertex << "\nКоличество вершин с нечетными степенями: " << odd_vertex << endl;
    
    return 0;
}

int even_count(vector<vector<int>>& adjacency_matrix){
    int even_vertex_count = 0;
    int n = adjacency_matrix.size();
    for (int i = 0;i < n; i++){
        int vertex = 0;
        for (int j = 0;j < n; j++){
            if (adjacency_matrix[i][j] == 1){
                if (i == j){
                    vertex += 2;
                }
                    else {
                        vertex ++;
                    }
                }
            }            
            if (vertex % 2 == 0){
                even_vertex_count ++;
            }
        }
    return even_vertex_count;
}

int odd_count(vector<vector<int>>& adjacency_matrix){
    int odd_vertex_count = 0;
    int n = adjacency_matrix.size();
    for (int i = 0;i < n; i++){
        int vertex = 0;
        for (int j = 0;j < n; j++){
            if (adjacency_matrix[i][j] == 1){
                if (i == j){
                    vertex += 2;
                }
                    else {
                        vertex ++;
                    }
                }
            }            
            if (vertex % 2 == 1){
                odd_vertex_count ++;
            }
        }
    return odd_vertex_count;
}
