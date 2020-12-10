#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>



void s_act_handler(int signum);

int main() {


	int i = 0;
        struct sigaction s_act;
        //set sigaction
        s_act.sa_handler = s_act_handler;
        //set Handler
        s_act.sa_flags = 0;
        //set flag 0 => SIGINT에 대한 act 함.
        sigemptyset(&s_act.sa_mask);
        //no option, 신호가 block 되면 안됨
        sigaddset(&s_act.sa_mask, SIGQUIT);
        //현제 set에 sigquit 추가


        if(sigaction(SIGTSTP, &s_act, NULL) < 0) {
	//에러 처리
		perror("Error : can't set SIGTSTP\n");
                exit(EXIT_FAILURE);
        }





	for (i; i<10000; i++){
		printf("Waiting for signal to be received! Count:%d\n", i);
		sleep(1);
	}


	//wait for recieve signal
        printf("finish\n");
        return 0;

}



void s_act_handler(int signum) {
        psignal(signum, "Received Signal:: ");
	//if signal recieved, print out signal
}
