/* Taken from https://github.com/cccriscv/mini-riscv-os */
.equ STACK_SIZE, 8192 /* Ensure the stack is 8192 bytes. */

.global _start

_start:
	/* Setup a stack per hart */
	csrr t0, mhartid /* Read the current hart's ID */
	slli t0, t0, 10 /* Shift the hart's ID to the left by 1024 bytes */
	la sp, stacks + STACK_SIZE /* Set the stack pointer */
	
	add sp, sp, t0 /* Move current hart pointer */
	
	/* If there is a hart that isn't 0 among us, park it */
	csrr a0, mhartid /* What hart are we? */
	bnez a0, park /* If we are not zero, park by jumping to park */
	
	j kmain /* Hart 0, jump to C */

park:
	/* Not somewhere you would walk your dog. */
	wfi
	j park

stacks:
	.skip STACK_SIZE * 4 /* Allocate space for stacks */
