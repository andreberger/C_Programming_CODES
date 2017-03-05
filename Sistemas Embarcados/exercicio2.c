/* aula 4 */
#define FREQ 50000000
#define MSEC 1000

void sleep_time(int milliseconds)
{
	int delay = (milliseconds*FREQ) / MSEC;
	
	while (delay--);
}

int main(int argc, char *argv[])
{
	int vet[7];
	
	vet[0] = 129;
	vet[1] = 195;
	vet[2] = 102;
	vet[3] =  60;
	vet[4] = 102;
	vet[5] = 195;
	vet[6] = 129;
	
	while (i++) {
		pio_write(PIO_BASE, vet[i]);
		if (i > 6)
			i = 0;
		sleep_time(1500);
	}
	
	return 0;
}