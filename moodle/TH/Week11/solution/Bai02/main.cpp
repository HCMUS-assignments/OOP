#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

// thuat toan duyet do thi theo chieu rong BFS
void BFS(int V[][MAX], int n, int X)
{
    // khoi tao mang danh dau cho cac dinh
    int visited[n] = {0};

    // khoi tao hang doi
    queue<int> Q;

    // day phan tu X vao hang doi
    Q.push(X);

    while (!Q.empty())
    {
        int u = Q.front(); // lay phan tu dau tien cua hang doi
        Q.pop();           // xoa phan tu dau tien cua hang doi

        if (visited[u] == 1)
        {
            continue;
        }

        visited[u] = 1; // danh dau dinh u da duyet

        // in ra dinh u
        cout << u << " ";

        for (int v = 0; v < n; v++)
        {
            // neu u ke voi v va v chua duoc duyet thi day v vao hang doi
            if (V[u][v] == 1 && visited[v] == 0)
            {
                Q.push(v);
            }
        }
    }
}

int main()
{
    // ma tran ke
    int V[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 1, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}};

    int n = 6; // so dinh cua do thi
    int X = 0; // dinh bat dau duyet

    // duyet do thi theo chieu rong
    BFS(V, n, X);

    return 225;
}