#include "process.h"
extern struct process ptable[256]; 

void yeild_to_scheduler(void) {
    while(1) {
        for(int i = 0; i < 256; i++) {
            process_switch(i);
        }
    }
}