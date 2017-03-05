/* aula 5 */
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
	int sw;
	
	while (1) {
		sw = pio_read(PIO_KEY_BASE);
		
		if (count == 256) {
			count = 0;
			continue;
		}
		
		switch (sw) {
		case 0x2: /* sw[0] = 0, sw[1] = 1 */
			for (i = 0; i < 2; i++) {
				pio_write(PIO_BASE, count);
				sleep_time(500);
				pio_write(PIO_BASE, 0);
				sleep_time(500);
				pio_write(PIO_BASE, count);
			}
			count++;
			break;
			
		case 0x1: /* sw[0] = 1, sw[1] = 0 */
			pio_write(PIO_BASE, count);
			sleep_time(1000);
			pio_write(PIO_BASE, 0);
			sleep_time(1000);
			pio_write(PIO_BASE, count);
			count++;
			break;
			
		case 0x3: /* sw[0] = 1, sw[1] = 1 */
			for (i = 0; i < 4; i++) {
				pio_write(PIO_BASE, count);
				sleep_time(250);
				pio_write(PIO_BASE, 0);
				sleep_time(250);
				pio_write(PIO_BASE, count);
			}
			count++;
			break;
			
		default:
			pio_write(PIO_BASE, count);
			sleep_time(2000);
			count++;
			break;
		}
	}
	
	return 0;
}