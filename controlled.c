#define rGPKCON (*(volatile unsigned long *)0x7F008800)
#define rGPK_DAT (*(volatile unsigned long *)0x7F008808)

#define rGPNCON (*(volatile unsigned long *)0x7F008830)
#define rGPNDAT (*(volatile unsigned long *)0x7F008834)

//read data
#define GPK4_OUT (1<<(8*2))
#define GPK5_OUT (1<<(10*2))
#define GPK6_OUT (1<<(12*2))
#define GPK7_OUT (1<<(14*2))

//write data 
#define GPN0_IN ~(1<<(0*2))
#define GPN1_IN ~(1<<(1*2)) 
#define GPN2_IN ~(1<<(2*2))
#define GPN3_IN ~(1<<(3*2))

int main()
{
	unsigned long dwDAT;

	rGPKCON = GPK4_OUT | GPK5_OUT | GPK6_OUT |GPK7_OUT;

	rGPNCON = GPN0_IN & GPN1_IN & GPN2_IN & GPN3_IN;

	while (1){
		
		dwDAT = rGPNDAT;
	
		if (dwDAT & (1<<0))
			rGPK_DAT &= ~(1<<4);
		else 
			rGPK_DAT |= (1<<4);
	
		if (dwDAT & (1<<1))
			rGPK_DAT |= (1<<5);
		else 
			rGPK_DAT &= ~(1<<5);

		if (dwDAT & (1<<2))
			rGPK_DAT &= ~(1<<6);
		else 
			rGPK_DAT |= (1<<6);

		if (dwDAT & (1<<3))
			rGPK_DAT &= ~(1<<7);
		else 
			rGPK_DAT |= (1<<7);
	}
	return 0;
}
