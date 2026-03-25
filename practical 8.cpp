//// N-Queens Problem
//#include <iostream>
//using namespace std;
//
//int board[10][10], N;
//
//bool isSafe(int row, int col) {
//    for (int i = 0; i < col; i++)
//        if (board[row][i]) return false;
//
//    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
//        if (board[i][j]) return false;
//
//    for (int i = row, j = col; i < N && j >= 0; i++, j--)
//        if (board[i][j]) return false;
//
//    return true;
//}
//
//bool solve(int col) {
//    if (col >= N) return true;
//
//    for (int i = 0; i < N; i++) {
//        if (isSafe(i, col)) {
//            board[i][col] = 1;
//
//            if (solve(col + 1)) return true;
//
//            board[i][col] = 0; // backtrack
//        }
//    }
//    return false;
//}
//
//int main() {
//    cout << "Enter number of queens: ";
//    cin >> N;
//
//    if (solve(0)) {
//        cout << "Solution:\n";
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++)
//                cout << board[i][j] << " ";
//            cout << endl;
//        }
//    } else {
//        cout << "No solution exists";
//    }
//
//    return 0;
//}


//// Graph Coloring Problem
//#include <iostream>
//using namespace std;
//
//int graph[10][10], color[10], n, m;
//
//bool isSafe(int v, int c) {
//    for (int i = 0; i < n; i++)
//        if (graph[v][i] && color[i] == c)
//            return false;
//    return true;
//}
//
//bool graphColoring(int v) {
//    if (v == n) return true;
//
//    for (int c = 1; c <= m; c++) {
//        if (isSafe(v, c)) {
//            color[v] = c;
//
//            if (graphColoring(v + 1)) return true;
//
//            color[v] = 0; // backtrack
//        }
//    }
//    return false;
//}
//
//int main() {
//    cout << "Enter number of vertices: ";
//    cin >> n;
//
//    cout << "Enter adjacency matrix:\n";
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++)
//            cin >> graph[i][j];
//
//    cout << "Enter number of colors: ";
//    cin >> m;
//
//    if (graphColoring(0)) {
//        cout << "Coloring Solution:\n";
//        for (int i = 0; i < n; i++)
//            cout << "Vertex " << i << " -> Color " << color[i] << endl;
//    } else {
//        cout << "No solution exists";
//    }
//
//    return 0;
//}


// Hamiltonian Cycle
#include <iostream>
using namespace std;

int graph[10][10], path[10], n;

bool isSafe(int v, int pos) {
    if (!graph[path[pos - 1]][v]) return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v) return false;

    return true;
}

bool hamiltonian(int pos) {
    if (pos == n) {
        return graph[path[pos - 1]][path[0]];
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;

            if (hamiltonian(pos + 1)) return true;

            path[pos] = -1; // backtrack
        }
    }
    return false;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    for (int i = 0; i < n; i++) path[i] = -1;

    path[0] = 0;

    if (hamiltonian(1)) {
        cout << "Hamiltonian Cycle:\n";
        for (int i = 0; i < n; i++)
            cout << path[i] << " ";
        cout << path[0];
    } else {
        cout << "No Hamiltonian Cycle exists";
    }

    return 0;
}



