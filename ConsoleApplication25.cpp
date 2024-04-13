#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int dfs(int** graph, const int n, int start, int finish, int* visited, int* path) {
    if (visited[start] == true) {
        return -1;
    }
    visited[start] = true;
    if (start == finish) {
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        if (graph[start][i] == 0)
            continue;
        int path_size = dfs(graph, n, i, finish, visited, path);
        if (path_size ==-1)
            return -1;
        if (path_size ==1){
            for (int j = 0; j < n; j++) {
                if (path[j] == 0) {
                    path[j] = i + 1;
                    return 1;
                }
            }
        }
        
    }
}
int main() {
    int start, finish;
    std::ifstream fin("graph.txt");
    int max=0;
    string tm;
    if (fin) {
        while (!fin.eof()) {
            fin >> tm;
            if (max < stoi(tm)-1) {
                max = stoi(tm)-1;
            }

        }
    }fin.close();
    int** graph{ new int* [max] {} };  
    for (int i{}; i < max; i++)
    {
        graph[i] = new int[max] {0};
    }
    int* visited{ new int[max] {0} };
    int* path{ new int[max] {0} };
    string a, b;
    fin.open("graph.txt");
    if (fin){
    while (!fin.eof()) {
    fin >>a;
    fin >> b;
    graph[stoi(a)-1][stoi(b)-1] = 1;
        }
    cin >> start;
    cin >> finish;
    int g;
    g=dfs(graph, max-1, start-1, finish-1, visited, path);
    if (g == 1) {
        cout << start;
        for (int j = max-1; j >=0; j=j-1) {
            if (path[j] != 0) {
                cout << path[j];
            }
        }
    }
        if (g == -1) {
            cout << "path does not exist";
        }
        fin.close();
    }
    return 0;
}