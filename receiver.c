#include "header.h"

int main()
{
    int id;
	struct msg receiver;
    key_t key = KEY;
    if ((id = msgget(key, 0666)) < 0)
    {
       printf("\nError\n");
       exit(1);
    }
	printf("\nWaiting for msgs...\n");
     //Receive an answer of message 
    if (msgrcv(id ,&receiver, MAXSIZE, 1, 0) < 0) {
		printf("\nerror in receiveing msg 1\n");
		exit(1);
	}
	printf("Received msg: %s\n", receiver.buff);
	if (msgrcv(id ,&receiver, MAXSIZE, 3, 0) < 0) {
                printf("\nerror in receiveing msg 1\n");
                exit(1);
    }
    printf("Received msg: %s\n", receiver.buff);
 	if (msgrcv(id ,&receiver, MAXSIZE, 2, 0) < 0) {
                printf("\nerror in receiveing msg 1\n");
                exit(1);
    }
   	printf("Received msg: %s\n", receiver.buff);
	msgctl(id, IPC_RMID, NULL);
	return 0;
}
