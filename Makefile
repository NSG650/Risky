CC=riscv64-elf-gcc
CFLAGS=-nostdlib -fno-builtin -mcmodel=medany -march=rv64ima -mabi=lp64 -T linker.ld

all: risky.elf

risky.elf: boot/boot.S kernel/kernel.c $(wildcard kernel/*/*.c) $(wildcard kernel/*/*.s)
	${CC} ${CFLAGS} -o $@ $^

run: kernel.elf
	qemu-system-riscv64 -machine virt -monitor stdio -bios $< -sdl

clean:
	rm risky.elf	
