#include<iostream>
#include<vector>

using namespace std;

int count_incident_edges(int n, int m, int k) {
    int count = 0;
    
    for (int i = 0; i < m; i++) {
        int edge_from, edge_to;
        cin >> edge_from >> edge_to;
        
        if (edge_from == k || edge_to == k) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int vertices, edges, k;
    cout << "Введите количество вершин, ребер и вершину k через пробел: ";
    cin >> vertices >> edges >> k;
    
    cout << "Введите " << edges << " ребер (формат: u v):" << endl;
    int count = count_incident_edges(vertices, edges, k);
    
    cout << "Количество ребер, инцидентных вершине " << k << ": " << count << endl;
    
    return 0;
}