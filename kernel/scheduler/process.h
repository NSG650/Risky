#ifndef PROCESS_H
#define PROCESS_H

#include "switch.h"

struct process {
    unsigned int pid;
    char name[256];
    unsigned char stack[1024];
    struct context ctx;
};

extern struct process ptable[256]; 

void process_init(reg_t address);
int process_create(char *name, reg_t address);
void process_switch(int pid);
void process_yeild_to_scheduler(void);
void process_dump_ptable(void);

#endif
