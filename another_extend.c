#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

#define LENGTH 2000

void *mythread(void *arg) {
    printf("begin of %s\n", (char *) arg);
    for (int i = 0; i < LENGTH; ++i) {
        int things_in_thread = i + 3;
    }
    printf("end of %s\n", (char *) arg);
    return NULL;
}

int main(int argc, char *argv []) {
    pthread_t p1, p2;
    int rc;
    printf("main: start\n");
    pthread_create(&p1, NULL, mythread, "A");
    pthread_create(&p2, NULL, mythread, "B");
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("main: finish\n");
    return 0;
}
