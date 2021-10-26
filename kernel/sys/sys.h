#ifndef SYS_H
#define SYS_H

#include "../scheduler/switch.h"

static inline reg_t r_mhartid() {
  reg_t x;
  asm volatile("csrr %0, mhartid" : "=r" (x) );
  return x;
}

static inline reg_t r_mstatus() {
  reg_t x;
  asm volatile("csrr %0, mstatus" : "=r" (x) );
  return x;
}

static inline void w_mstatus(reg_t x) {
  asm volatile("csrw mstatus, %0" : : "r" (x));
}

static inline void w_mepc(reg_t x) {
  asm volatile("csrw mepc, %0" : : "r" (x));
}

static inline reg_t r_mepc() {
  reg_t x;
  asm volatile("csrr %0, mepc" : "=r" (x));
  return x;
}

static inline void w_mscratch(reg_t x) {
  asm volatile("csrw mscratch, %0" : : "r" (x));
}

// Machine-mode interrupt vector
static inline void w_mtvec(reg_t x) {
  asm volatile("csrw mtvec, %0" : : "r" (x));
}

static inline reg_t r_mie() {
  reg_t x;
  asm volatile("csrr %0, mie" : "=r" (x) );
  return x;
}

static inline void w_mie(reg_t x) {
  asm volatile("csrw mie, %0" : : "r" (x));
}


#endif