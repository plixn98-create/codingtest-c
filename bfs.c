#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// 방향 (상, 하, 좌, 우)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// BFS에 사용할 큐 구조체
typedef struct {
    int x, y;
} Node;

int queue[MAX * MAX][2];
int front = 0, rear = 0;

void push(int x, int y) {
    queue[rear][0] = x;
    queue[rear][1] = y;
    rear++;
}
Node pop() {
    Node n;
    n.x = queue[front][0];
    n.y = queue[front][1];
    front++;
    return n;
}
bool empty() {
    return front == rear;
}

// --------------------------
// BFS 최단거리 함수
// --------------------------
int bfs(int maps[][MAX], int n, int m) {
    int visited[MAX][MAX] = {0};

    // 시작점
    push(0, 0);
    visited[0][0] = 1;

    while (!empty()) {
        Node cur = pop();
        int x = cur.x;
        int y = cur.y;

        // 도착점이면 반환
        if (x == n - 1 && y == m - 1) {
            return visited[x][y];
        }

        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 확인
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            // 갈 수 있는 길 && 방문하지 않은 곳
            if (maps[nx][ny] == 1 && visited[nx][ny] == 0) {
                visited[nx][ny] = visited[x][y] + 1;
                push(nx, ny);
            }
        }
    }
    return -1; // 도착 불가능
}

// --------------------------
// 메인 함수 (테스트용)
// --------------------------
int main(void) {
    // 예시 지도 (5x5)
    int n = 5, m = 5;
    int maps[5][MAX] = {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1}
    };

    int result = bfs(maps, n, m);
    printf("%d\n", result); // 최단 거리 출력
    return 0;
}


