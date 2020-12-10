#include <stdio.h>
#include <signal.h>


int main () {

        int input, pid;
        printf("Input Target PID!\n");
        scanf("%d", &pid);
        printf("Input your Signal Code!\n");
        scanf("%d", &input);
	//input target pid and code which user want to send	 
 
	union sigval sgv;

        sgv.sival_int = input;
	//set code
        sigqueue(pid, SIGRTMIN, sgv);
	//send code
	return 0;
}
