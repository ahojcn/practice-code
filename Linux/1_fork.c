#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t ret = fork();
  // printf("pid: %d\n ppid %d\n ret: %d\n", getpid(), getppid(), ret);
  if (ret == 0) {
    printf("子进程\n");
  } else if (ret > 0) {
    printf("父进程\n");
  } else {
    perror("fork");
  }

  sleep(1);
  return 0;
}
