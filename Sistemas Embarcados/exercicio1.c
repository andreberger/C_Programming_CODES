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
	int count = 0;
	
	while (1) {
		pio_write(PIO_BASE, count);
		count++;
		
		/* 8 bits counter = max value is 255 */
		if (count == 255) {
			for (i = 0; i < 3; i++) {
				sleep_time(2000);
				pio_write(PIO_BASE, 0);
				sleep_time(2000);
				pio_write(PIO_BASE, count);
			}
			count = 0;
		} else
			sleep_time(1000);
	}
	
	return 0;
}