#ifndef CLIB_H_
#define CLIB_H_

#include <stdint.h>
#include <stdarg.h>

#define DAY_REG     0X07
#define MONTH_REG   0X08
#define YEAR_REG    0X09
#define HOUR_REG    0X04
#define MIN_REG     0X02
#define SEC_REG     0X00

#define DATE_SEP    '-'
#define TIME_SEP    ':'
#define NULL 0

// definition of structures

typedef struct p_blocked{
    int pid;
    struct p_blocked * next;
    
} p_blocked_t;

typedef struct sem {
    int identifier;
    int counter;
    struct sem* next;
    //lista de procesos bloqueados en un semaforo
    p_blocked_t * blocked_processes;
    
} sem_t;

typedef struct pipe {
    const char *identifier;
    // sem_t * read_sem;
    // sem_t * write_sem;
    sem_t * global_sem;
    //Region donde se va a escribir
    void * critical_region;

    struct pipe * next;
} pipe_t;

void puts(const char * string);
void perror(const char * string);
void putchar(uint8_t character);
void printf(char * str, ...);
uint8_t getchar(void);
char * gets(char * string, uint64_t size);
void clearScreen(void);
char * getDate(char * date);
char * getTime(char * time);
void sleep(uint64_t millis);
void beep(uint32_t frequency, uint64_t millis);
void exit();
uint64_t getTicks();
void drawPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);
void printMemState();
int free(void *addr);
void *malloc(unsigned long bytes);
int new_process(int priority,void *rip, const char *name);
uint64_t set_process_priority(int pid, int priority);
uint64_t set_process_state(int pid, char state);
uint64_t list_processes() ;
uint64_t list_sem();
uint64_t list_pipes();


extern uint64_t syscall(uint64_t rax, uint64_t rdi, uint64_t rsi, uint64_t rdx);

#endif /* CLIB_H_ */