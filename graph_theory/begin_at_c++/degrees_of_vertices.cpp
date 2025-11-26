#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<pair<int, int>> arr_edges;
    int vertices;
    int edges;

    cout << "Введите количество вершин и количество ребер через пробел: ";
    cin >> vertices >> edges;
    cout << "\nВведите список ребер: ";

    for (int i = 0; i < edges; i++) {
        int edge_from = 0;
        int edge_to = 0;
        cin >> edge_from >> edge_to;
        arr_edges.push_back({edge_from, edge_to});
    }

    cout << "\nВведенный список ребер: ";

    for (int i = 0; i < edges; i++) {
        cout << "[" << arr_edges[i].first << ";" << arr_edges[i].second << "] ";
    }
    
    vector<int> temp;

    for (int i = 0; i < edges; i++) {
        temp.push_back(arr_edges[i].first);
        temp.push_back(arr_edges[i].second);
    }

    sort(temp.begin(), temp.end());

    vector<int> temp2;

    int schet = 0;

    for (int i = 0; i < temp.size(); i++) {
        schet = 1;
        
        while (i + 1 < temp.size() && temp[i] == temp[i + 1]) {
            schet++;
            i++;
        }
        temp2.push_back(schet);
    }

    cout << "\nКоличество повторений каждой вершины: ";

    for (int i = 0; i < temp2.size(); i++) {
        cout << temp2[i] << " ";
    }
    
    return 0;
}