#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 128
#define KEY 1000

struct msg {
    long mtype;
    char buff[MAXSIZE];
};
