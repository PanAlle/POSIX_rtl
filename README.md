# POSIX_rtl
Posix compliant program to test rt application

## TASK 1
Write a periodic real-time task that uses a POSIX timer and the signal it sends to implement a periodic task.Your task should output a warning if the deadline (equal to period) is missed.  Hint:  If a signal is received and the process is not blocking on sigwait, the registered signal handler is used instead

## TASK 2

Extend the periodic task from the previous assignment by addingthe following command line arguments:

•period (in milliseconds, from 1 ms to 999 ms)
•priority
•CPU load factor
•scheduling policy (SCHEDFIFOorSCHEDRR)

To run the task on the server 

root@ gcc -Wall -o task2 Task_2_G3S1.c -lrt
root@ taskset -c 31 ./task2 550 100000 1 0

##FIFO Explanation 

Task with period p = 500 get higher priority

![Screenshot from 2020-07-20 18-16-32](https://user-images.githubusercontent.com/65158179/87960845-2cef6800-cab5-11ea-9ea2-c1687d0d1d24.png)

