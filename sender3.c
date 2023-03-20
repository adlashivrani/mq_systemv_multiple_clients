#include "header.h"

int main()
{
	key_t key = KEY;
    int id;
	struct msg sender;	
    
    if ((id = msgget(key, IPC_CREAT | 0666 )) < 0)
    {
      	printf("\nError in creating\n"); 
        exit(1);
    }
	//msg type
	sender.mtype = 3;
    printf("Enter a message:");
 	fgets(sender.buff, MAXSIZE, stdin);

    if (msgsnd(id, &sender, sizeof(sender.buff), 0) < 0)
    {
        printf ("Error while seding a message");
        exit(1);
    } else {
        printf("Message Sent\n");
	}
	printf("sent message: %s\n", sender.buff);
	return 0;   
}
