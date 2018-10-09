# CPU_Processs_Scheduler
So these are by far the principles for working of this code.

### First Come First Serve (FCFS) scheduling
First in, first out (FIFO), also known as first come, first served (FCFS), is the simplest scheduling algorithm. FIFO simply queues processes in the order that they arrive in the ready queue.
In this, the process that comes first will be executed first and next process starts only after the previous gets fully executed.
![alt text](https://www.geeksforgeeks.org/wp-content/uploads/FCFS.png)

### Shortest Job First (SJF) scheduling
Shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next. SJN is a non-preemptive algorithm.

    -Shortest Job first has the advantage of having minimum average waiting time among all scheduling algorithms.

    -It is a Greedy Algorithm.

    -It may cause starvation if shorter processes keep coming. This problem can be solved using the concept of aging.
    
    -It is practically infeasible as Operating System may not know burst time and therefore may not sort them. While it is not possible to predict execution time, several methods can be used to estimate the execution time for a job, such as a weighted average of previous execution times. SJF can be used in specialized environments where accurate estimates of running time are available.
![alt text](https://www.studytonight.com/operating-system/images/sjf.png)

sources: geeksforgeeks.org and Google images
