#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* my_string) {
    int len = strlen(my_string);
    char* answer = (char*)malloc((len + 1) * sizeof(char)); // 결과 문자열
    int cnt[128] = {0};  // 아스키 코드 기준 카운트 (영문/공백이면 충분)

    // 1단계: 각 문자의 등장 횟수 세기
    for (int i = 0; i < len; i++) {
        cnt[(unsigned char)my_string[i]]++;
    }

    // 2단계: 등장 횟수가 1인 문자만 결과에 추가
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (cnt[(unsigned char)my_string[i]] == 1) {
            answer[k++] = my_string[i];
        }
    }

    answer[k] = '\0';  // 문자열 종료, 배열->문자열 변환
    return answer;
}


// 프로그래머스 형식
// 중복되는 문자 모두 제거
// 예 : "people"->"ol"
