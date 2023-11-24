#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    // 스레드의 작업 수행
    printf("스레드에서 작업 수행 중\n%d", (int)arg);
    sleep(2);  // 잠시 대기

    // 스레드 종료
    printf("스레드 종료\n %d", (int)arg);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_id;

	int arg = 42;

    // 새로운 스레드 생성
    if (pthread_create(&thread_id, NULL, thread_function, &arg) != 0) {
        fprintf(stderr, "스레드 생성 오류\n");
        return 1;
    }

    // 스레드를 분리
    // if (pthread_detach(thread_id) != 0) {
    //     fprintf(stderr, "스레드 분리 오류\n");
    //     return 2;
    // }

    if (pthread_join(thread_id, NULL) != 0) {
        fprintf(stderr, "스레드 분리 오류\n");
        return 2;
    }

    // 메인 스레드의 작업 수행
    printf("메인 스레드에서 작업 수행 중\n");

    // 메인 스레드 종료
    printf("메인 스레드 종료\n");

    return 0;
}
