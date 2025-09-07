#include <stdio.h>
#include <stdbool.h>


typedef struct {
    int x, y;
} Node;

#define MAX 1000

// ******* 스택 *******

Node stack[MAX]; 
int top = 0;   // 스택의 현재 크기 (다음 push 위치)

// push: 새로운 원소를 스택 위에 추가
void push(int x, int y) {
    stack[top].x = x;
    stack[top].y = y;
    top++;
}

// pop: 스택 위에서 하나 꺼내기
Node pop() {
    top--;               // top을 하나 줄이고
    return stack[top];   // 줄인 위치의 원소 반환
}

// empty: 스택이 비었는지 확인
bool empty() {
    return top == 0;
}


// ******* 큐 *******

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

