#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// 방향 (상, 하, 좌, 우)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

typedef struct{
	int x, y;
} Node;


// 큐 : 선입선출
int queue[MAX * MAX][2];
int front=0, rear = 0;


void push(int x, int y){
	queue[rear][0] = x;
	queue[rear][1] = y;
	rear++;
}

Node pop(){
	Node n;
	n.x = queue[front][0];
	n.y = queue[front][1];
	front++;
	return n;
}

bool empty(){
	return front==rear;
}

int bfs(int **map, size_t rows, size_t cols,
        int startX, int startY, int endX, int endY) {

	// 큐 인덱스 초기화
    front = rear = 0;

	// 범위 및 통행 가능 여부 확인
    if (startX < 0 || startY < 0 || startX >= (int)cols || startY >= (int)rows) return -1;
    if (endX   < 0 || endY   < 0 || endX   >= (int)cols || endY   >= (int)rows) return -1;
    if (map[startY][startX] == 0 || map[endY][endX] == 0) return -1;
	//
	
	int visited[MAX][MAX] = {0};
	
	push(startY,startX);
	visited[startY][startX]= 1;

	while(!empty()){
		Node cur = pop();
		int x = cur.x;
		int y = cur.y;

		if (x==endX && y==endY) return visited[y][x];

		for (int i=0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if (nx<0 || nx>= cols || ny<0 || ny>= rows) continue;
			if (map[ny][nx] == 0) continue;          // 벽
            if (visited[ny][nx] != 0) continue;      // 이미 방문
			
			if (maps[nx][ny] == 1 && visited[nx][ny] == 0) {
                		visited[nx][ny] = visited[x][y] + 1;
                		push(nx, ny);
			}
		}
	}

	return -1; // 도착 불가능

}



int solution(int **rectangle, size_t rectangle_row_len, size_t rectangle_col_len, int characterX, int characterY, int itemX, int itemY) {
  int answer = 0;
	
	answer = bfs(rectangle, rectangle_row_len, rectangle_col_len, characterX, characterY, itemX, itemY);

  //
  int copy[rectangle_row_len][rectangle_col_len];
  
  for (int i = 0; i < rectangle_row_len; i++) {
        // rectangle[i]는 i번째 행의 시작 주소(int*)
        memcpy(copy[i], rectangle[i], rectangle_col_len * sizeof(int));
    }
    
  //
	return answer;

}
