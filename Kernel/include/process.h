#ifndef PROCESS_H_
#define PROCESS_H_
#define MAX_PID 50

//Creo la struct
typedef struct process {
    unsigned char status; // READY/AVAILABLE ('a') , BLOCKED ('b') OR RUNNING ('r')
    unsigned char ppriority;
    void *bp;
    void *sp; // stack pointer
    struct process * next;
    char *name;
} process_t;

//struct para scheduler
typedef struct node {
    int pid;
    struct node *next;
} node_t;

typedef struct sleepingp{
    int tt;
    int ppid;
    struct sleepingp *next;
}sleeping_t;

int init_scheduler();
void *schedule(void *prev_rsp);
int update_process_priority(int pid, int priority);
int update_process_state(int pid, char state);
int create_process(int priority, void *rip, char* name, int rdi);
int get_pid(); // del running
int kill_process(int pid);
process_t ** process_list_returner();
void check_sleepers();
int every_n_seconds_procecess(int pid);
int get_free_bed();
int get_Process_Pid(process_t* process);
process_t* get_Pnode(int pid);
int addProcess_scheduler(int pid);
int removeProcess_scheduler( int pid );
int get_free_pid();


#endif