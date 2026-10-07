#include <iostream>
using namespace std;

#define INF 999

int main() {
    int n;
    int cost[10][10];
    int visited[10] = {0};

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the cost adjacency matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    int edges = 0;
    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edges < n - 1) {
        int minimum = INF;
        int u = -1;
        int v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < minimum) {
                        minimum = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        cout << u << " - " << v << " : " << minimum << endl;

        totalCost += minimum;
        visited[v] = 1;
        edges++;
    }

    cout << "Minimum Cost = " << totalCost << endl;

    return 0;
}
