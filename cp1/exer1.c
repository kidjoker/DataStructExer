//顺序打印0-N之间的数
#include <stdio.h>
#include <time.h>

#define MAXK 1e7;

clock_t start,stop;
double duration;

void PrintNIteration(int N) {
    if(N) {
        PrintNIteration(N-1);
        printf("%d\n", N);
    }
    return;
}

void PrintNLoop(int N) {
    int i;
    for(i = 1;i <= N;i++) {
        printf("%d\n",i);
    }
    return;
}

int main(void) {
    int i;
    start = clock(); //开始计时
    for(i = 0; i < MAXK; i++) {
        PrintNIteration(10);
    }
    stop = clock(); //结束计时

    duration = ((double)(stop-start))/CLOCKS_PER_SEC/MAXK;
    printf("%6.2e\n", duration);
    return 0;
}