#include <iostream>
using namespace std;

int parent[10];

int findParent(int i) {
    if (parent[i] == i)
        return i;

    return parent[i] = findParent(parent[i]);
}

void unionSet(int u, int v) {
    int parentU = findParent(u);
    int parentV = findParent(v);

    parent[parentU] = parentV;
}

int main() {
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    int u[20], v[20], weight[20];

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < e; i++) {
        cin >> u[i] >> v[i] >> weight[i];
    }

    // Initialize parent
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Sort edges according to weight
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {

            if (weight[j] > weight[j + 1]) {

                swap(weight[j], weight[j + 1]);
                swap(u[j], u[j + 1]);
                swap(v[j], v[j + 1]);
            }
        }
    }

    int totalCost = 0;
    int count = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 0; i < e && count < n - 1; i++) {

        if (findParent(u[i]) != findParent(v[i])) {

            cout << u[i] << " - " << v[i]
                 << " : " << weight[i] << endl;

            totalCost += weight[i];

            unionSet(u[i], v[i]);

            count++;
        }
    }

    cout << "Minimum Cost = " << totalCost << endl;

    return 0;
}
