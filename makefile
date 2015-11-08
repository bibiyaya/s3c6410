controlled.bin : crt.s controlled.c
	arm-linux-gcc -g -c -o crt.o crt.s
	arm-linux-gcc -g -c -o controlled.o controlled.c
	arm-linux-ld -Ttext 0x00000000 -g crt.o controlled.o -o controlled_elf
	arm-linux-objcopy -O binary -S controlled_elf controlled.bin
	arm-linux-objdump -D -m arm controlled_elf > controlled.dis
clean : 
	rm -f controlled.bin controlled.dis controlled_elf *.o
