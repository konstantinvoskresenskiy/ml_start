#include <iostream>
#include <vector>

using namespace std;

int countLoops(const vector<vector<int>>& adjacencyMatrix) {
    int loopCount = 0;
    int n = adjacencyMatrix.size();
    
    for (int i = 0; i < n; i++) {
        if (adjacencyMatrix[i][i] == 1) {
            loopCount++;
        }
    }
    
    return loopCount;
}

int main() {
    int n;
    
    cout << "Введите количество вершин графа (размер матрицы): ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Ошибка: размер матрицы должен быть положительным числом!" << endl;
        return 1;
    }
    
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));
    
    cout << "Введите матрицу смежности " << n << "x" << n << " (построчно, через пробел):" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << "Строка " << (i + 1) << ": ";
        for (int j = 0; j < n; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }
    
    cout << "\nВведенная матрица смежности:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
    
    int loops = countLoops(adjacencyMatrix);
    
    cout << "\nКоличество петель в графе: " << loops << endl;
    
    return 0;
}