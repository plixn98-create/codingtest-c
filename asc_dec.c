#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// qsort 비교 함수 (오름차순)
int cmp_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);  // a<b → 음수 → 오름차순 // 내림차순 : b - a // 문자열 : int -> char
}

// qsort 비교 함수 (내림차순)
int cmp_desc(const void *a, const void *b) {         // 문자열 정렬 때도 형식 유지
    return (*(int*)b - *(int*)a);  // b-a → 큰 게 먼저 // 문자열 : int -> char
}

// qsort 비교 함수 (오름차순) - 문자열
int cmp_asc_str(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);  
}



int* solution(const char* my_string) {
    int* answer = (int*)malloc(count * sizeof(int)); // 대상크기 * 대상형식
    
    qsort(answer, count, sizeof(int), cmp_asc); // 정렬대상, 대상크기, 대상형식, 오름/내림 
    // 문자열 : int -> char
    
    printf("%d \n", answer[0]);
    return answer;
}
