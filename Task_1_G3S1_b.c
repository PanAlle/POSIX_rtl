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

// Setup a signal set for sigwait() to wait for SIGALRM
sigemptyset(&signal_set);
sigaddset(&signal_set, SIGALRM);

// Block SIGALRM to avoid Alarm clock before handler is defined
sigprocmask(SIG_BLOCK, &signal_set, NULL);

// Specify the timer’s period.
long period = 1;
timer_spec.it_value.tv_sec = period;
timer_spec.it_value.tv_nsec = 0; 
timer_spec.it_interval.tv_sec = period;
timer_spec.it_interval.tv_nsec = 0;
printf("My pid:%d\n", getpid());
printf("Set up struct for timer \n");
timer_settime(timer, 0, &timer_spec, NULL);

//Give to sigaction the new handler
new_action.sa_handler = new_action_funct;

//Clean the sigaction mask for blocked singals
sigemptyset( &new_action.sa_mask );
new_action.sa_flags = 0;
sigaction(SIGALRM, &new_action, NULL);
printf("Defined a new handler for SIGALRM \n");

int signum;
int counter = 1;

// Unblock SIGALRM
sigprocmask(SIG_UNBLOCK, &signal_set, NULL);

while(1){
	if(counter%10 == 0){
	       	sleep(2);
		counter = 0;}
	sigwait(&signal_set, &signum);
	printf("--- Task completed ---\n");
	counter++;
	}
}
