/*
 * Unilasalle/Canoas-RS 2016/02
 * Autor: Filipe de Aguiar Geissler
 *
 * Questão 2 da prova de sistemas embarcados.
 * Codificação em linguagem C com pseudo API.
 *
 */
int count = 0;

void inc(void)
{
	count++;
	if (count > 3)
		count = 0;
}

int main(void)
{
	int i, last_count = -1;
	
	register_irq(PIO_2_IRQ, inc);
	
	while (1) {
		switch (count) {
		case 0:
			if (count == last_count)
				continue;
			pio_write(PIO_1_BASE, 0);
			last_count = count;
			break;
		
		case 1:
			if (count != last_count || desloc == 0) {
				desloc = 0x80;
				last_count = count;
			} else
				desloc = (desloc >> 1);
			
			pio_write(PIO_1_BASE, desloc);
			delay(2000);
			
			break;
			
		case 2:
			if (count != last_count || desloc == 0x100) {
				desloc = 0x1;
				last_count = count;
			} else
				desloc = (desloc << 1);
			
			pio_write(PIO_1_BASE, desloc);
			delay(2000);
			
			break;
			
		case 3:
			if (count == last_count)
				continue;
			
			for (i = 0; i < 3; i++) {
				pio_write(PIO_1_BASE, 0xFF);
				delay(1000);
				pio_write(PIO_1_BASE, 0x0);
			}
			
			last_count = count;
		
			break;
		
		default:
			/* invalid value */
			break;
		}
	}

	return 0;
}