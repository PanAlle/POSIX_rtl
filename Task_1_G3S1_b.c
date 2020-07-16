#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include "errno.h"
#include <stdlib.h>
#include <string.h>

# define CLOCKID CLOCK_REALTIME

void new_action_funct(){
printf("Missed deadline \n");
}


int main(){

sigset_t signal_set;
timer_t timer;
struct itimerspec timer_spec;
struct sigaction new_action;
memset(&new_action, 0, sizeof(new_action));
// Create a timer.
timer_create(CLOCK_REALTIME, NULL, &timer);

// Specify the timer’s period.
long period = 1;
timer_spec.it_value.tv_sec = 0;
timer_spec.it_value.tv_nsec = 1; /* Start immediately */
timer_spec.it_interval.tv_sec = 5*period;
timer_spec.it_interval.tv_nsec = 0;

printf("Set up structure for timer \n");

new_action.sa_handler = new_action_funct;
printf("Defined the next handler \n");

sigemptyset( &new_action.sa_mask );
new_action.sa_flags = 0;
sigaction(SIGALRM, &new_action, NULL);
printf("Define a new sigaction \n");

// Setup a signal set for sigwait() to wait for SIGALRM
sigemptyset(&signal_set);
sigaddset(&signal_set, SIGALRM);
//sigprocmask(SIG_BLOCK, &signal_set, NULL);
int signum;

// Setup the timer’s period.
timer_settime(timer, 0, &timer_spec, NULL);
sleep(10);
while (1){
//		unsigned long mesg;
	sigprocmask(SIG_BLOCK, &signal_set, NULL);
	sleep(10);
	sigwait(&signal_set, &signum);
	printf("--- Task completed ---\n");
	// since we put SIGALRM into the blocked singal then  the next step 		we will stop on sigwait
	}

}
