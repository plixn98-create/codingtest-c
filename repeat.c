void draw1(int h) {
    if (h == 0) {
        return;    // h == 0일 때, "이 호출"만 끝냄
    }
    draw1(h - 1);  // 더 작은 h로 자기 자신 호출
    for (int i = 0; i < h; i++) {
        printf("*");
    }
    printf("\n");
}


// draw1(5) 실행 -> draw1(0)만 호출 종료, draw1(1~4)는 나머지 print 그대로 실행
