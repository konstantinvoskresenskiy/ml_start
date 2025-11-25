#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

bool comp(pair<int , int> a , pair<int , int> b);

int main(){

    vector<pair<int , int>> arr_edges;
    int vertices;
    int edges;

    cout << "Введите количство вершин и количество ребер через пробел: ";
    cin >> vertices >> edges;
    cout << "Введите список ребер: ";

    for (int i = 0; i < edges;i++){
        int edge_from = 0;
        int edge_to = 0;
        cin >> edge_from >> edge_to;
        arr_edges.push_back({edge_from , edge_to});
    }

    cout << "Введенный список ребер: ";

    for (int i = 0;i < edges;i++){
        cout << "[" << arr_edges[i].first << ";" << arr_edges[i].second << "]";

    }
        sort(arr_edges.begin() , arr_edges.end(),comp);

        cout << "\n" << "Отсортированный список ребер: ";

        for (int i = 0;i < edges;i++){
        cout << "[" << arr_edges[i].first << ";" << arr_edges[i].second << "]";

    }
    vector<int> index(vertices,-1);

    cout << "\n" << "Массив индексов(c какого индекса в списке ребер начинают идти ребра каждой вершины): ";

    for (int i = 0;i < edges;i++){
        int temp = arr_edges[i].first;

        if (index[temp] == -1){
            index[temp] = i;
        }

    }

    for (int i = 0; i < vertices;i++){
        cout << index[i] << " ";
    } 

    return 0;
    }

    bool comp(pair<int , int> a , pair<int , int> b){
    if (a.first == b.first){
        return a.second < b.second;
    }
    else {
        return a.first < b.first;
    }
}


