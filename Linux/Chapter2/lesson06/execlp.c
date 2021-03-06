#include <unistd.h>
#include <stdio.h>

int main() {

    pid_t pid = fork();

    if (pid > 0) {
        printf("I am parent: %d\n", getpid());
        sleep(1);
    }
    else if (pid == 0) {
        // execl("hello", "hello", NULL);

        execlp("ps", "ps", "aux", NULL);
        perror("execlp");
        printf("I am child: %d\n", getpid());
    }

    for (int i = 0; i < 3; i++) {
        printf("i = %d, pid = %d\n", i, getpid());
    }
    return 0;
}