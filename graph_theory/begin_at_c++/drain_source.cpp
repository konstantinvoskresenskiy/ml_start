#include<iostream>
#include<vector>

using namespace std;

int array_sum(vector<int> array , int size);
int drain_count(vector<vector<int>>& adjacency_matrix);
int source_count(vector<vector<int>>& adjacency_matrix);

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
    
    int drain = drain_count(adjacency_matrix);
    int source = source_count(adjacency_matrix);
    
    cout << "\nКоличество стоков: " << drain << "\nКоличество истоков: " << source << endl;
    
    return 0;
}


int array_sum(vector<int> array , int size){
    int sum = 0; 
    for (int p = 0;p < size;p++){
        sum += array[p];
    }
    return sum;
}

int drain_count(vector<vector<int>>& adjacency_matrix){
    int count_drain = 0;
    int n = adjacency_matrix.size();
    for(int i = 0;i < n;i++){
        vector<int> row;
        for (int j = 0; j < n;j++){
            row.push_back(adjacency_matrix[i][j]);
        }
            int sum_row = array_sum(row,n);
            if (sum_row == 0) {
                count_drain ++;
            }
    }
    return count_drain;
}

int source_count(vector<vector<int>>& adjacency_matrix){
    int count_source = 0;
    int n = adjacency_matrix.size();
    for(int j = 0;j < n;j++){
        vector<int> column;
        for (int i = 0; i < n;i++){
            column.push_back(adjacency_matrix[i][j]);
        }
            int column_row = array_sum(column,n);
            if (column_row == 0) {
                count_source ++;
            }
    }
    return count_source;
}