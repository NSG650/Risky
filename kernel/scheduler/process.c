#include "process.h"
#include "switch.h"
#include "../klibc/string.h"
#include "../klibc/printf.h"
#include "../uart/uart.h"

int total_process = 0;

struct process scheduler_proc;
struct process ptable[256]; 
struct process *running_process;

void process_init(reg_t address) {
    process_create("kernel_tasks", address);
}

int process_create(char *name, reg_t address) {
    strncpy(ptable[total_process].name, name, 256);
    ptable[total_process].ctx.ra = address;
    ptable[total_process].ctx.sp = (reg_t)ptable[total_process].stack;
    ptable[total_process].pid = total_process;
    total_process++;
    return total_process;
}

void process_switch(int pid) {
    running_process = &ptable[pid];
    sched_switch(&scheduler_proc.ctx, &ptable[pid].ctx);
}
void process_dump_ptable(void) {
    uart_puts("Name\tPID\r\n");
    for(int i = 0; i < total_process; i++) {
        char x[256];
        snprintf(x, 256, "%s\t%d\r\n", ptable[i].name, ptable[i].pid);
        uart_puts(x);
    }
}