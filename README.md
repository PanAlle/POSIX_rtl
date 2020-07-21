# POSIX_rtl
Posix compliant program to test rt application

# TASK 1

rite a periodic real-time task that uses a POSIX timer and the signal it sends to implement a periodic task.Your task should output a warning if the deadline (equal to period) is missed.  Hint:  If a signal is received and the process is not blocking on sigwait, the registered signal handler is used instead.
## Implementation
Task 1 implement a counter and define a handler for the signal SIGALRM, while the process is stuck in the while loop, when the counter put the execution to sleep, the defined handler is called, resulitng in a "missed deadline" print. During the normal execution, based on the clock period the loop is stopped on sigwait reuslting in a periodic print of "--completed task--".


# TASK 2

Extend the periodic task from the previous assignment by addingthe following command line arguments:

•period (in milliseconds, from 1 ms to 999 ms)
•priority
•CPU load factor
•scheduling policy (SCHEDFIFOorSCHEDRR)
## Implementation
The task take as input period, load factor (prop. to time spent in a useless for loop), scheduling policy (FIFO , RR) and the relative associated priority (1 - 99).

TAKS 1  = period = 500ms, load = 100000
TAKS 2  = period = 550ms, load = 100000

The task was run in differnt configuration:
 - Taks1 alone in RR, Taks 2 alone in RR
 - Taks1 alone in FIFO, Taks 2 alone in FIFO
 - Task1 with priority 2 and Task 2 with priorty 1 in FIFO
 
To run the task on the server 

root@ gcc -Wall -o task2 Task_2_G3S1.c -lrt

root@ taskset -c 31 ./task2 550 100000 1 0

##FIFO Explanation 

Task with period p = 500 get higher priority

![Screenshot from 2020-07-20 18-16-32](https://user-images.githubusercontent.com/65158179/87960845-2cef6800-cab5-11ea-9ea2-c1687d0d1d24.png)

