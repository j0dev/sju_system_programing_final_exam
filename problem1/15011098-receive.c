#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void s_act_handler(int signum, siginfo_t *si);


int main() {




	struct sigaction s_act;
	s_act.sa_sigaction = s_act_handler;
	s_act.sa_flags = SA_SIGINFO;
	sigemptyset(&s_act.sa_mask);
	s_act.sa_restorer = NULL;
	//set sigaction and flags ~~ for get RTS Message

	printf("PID : %d\n", getpid());

	if(sigaction(SIGRTMIN, &s_act, NULL) == 1) {
	//에러 처리
		perror("Error : can't set SIGTSTP\n");
                exit(EXIT_FAILURE);
        }

	
	while(1){
		//For Test
		sleep(1);
	}

	return 0;
}


void s_act_handler(int signum, siginfo_t *si){
	if (si->si_code == SI_QUEUE) {
		//get RTS INFO & CODE
		printf("GET RTS SIGNAL : %d, SIGNUM : %d\n", si->si_pid, si->si_signo);
		printf("RECIEVED CODE IS : %d\n", si->si_value.sival_int);
		getchar();
	} else {
		//Not RTS
		printf("Opppppppooooos No RTS signal : %d\n", signum);
	}
}
