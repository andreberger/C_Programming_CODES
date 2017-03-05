/*
 * Embedded Systems - Unilasalle/Canoas
 * Author: Filipe de Aguiar Geissler
 * Date: 26/09/2016
 * 
 * Solution of problem 6 of the simulated exam
 * 
 */
 
#define AR_COND_MAX  	2
#define ROOM_A 			0
#define ROOM_B 			1

/* Struct to keep the residential system configuration */
struct {
	int start;
	int end;
	int notification;
} ar_cond[AR_COND_MAX];

void set_bit(int *val, int bit)
{
	*val |= bit;
}

void unset_bit(int *val, int bit)
{
	*val &= ~bit;
}

void handler_1(void)
{
	int vet[3], value;
	
	/* notification is disabled */
	if (ar_cond[ROOM_A].notification == 0)
		return;
	
	/* Send message to phone app */
	vet[0] = 13;	
	vet[1] = ROOM_A;
	vet[3] = 1;
	write_pkt(vet);
	
	/* Turn on the ar_cond_A */
	value = read_pio(PIO_3_BASE);
	write_pio(PIO_3_BASE, value | (1 << ROOM_A));
}

void handler_2(void)
{
	int vet[3], value;

	/* notification is disabled */
	if (ar_cond[ROOM_B].notification == 0)
		return;
	
	/* Send message to phone app */
	vet[0] = 13;	
	vet[1] = ROOM_B;
	vet[3] = 1;
	write_pkt(vet);
	
	/* Turn on the ar_cond_B */
	value = read_pio(PIO_3_BASE);
	write_pio(PIO_3_BASE, value | (1 << ROOM_B));
}

int main(int argc, char *argv[])
{
	uint *vet;
	int value = 0, hour, i;

	/* Register interrupt routine for sensor A */
	register_irq(PIO_1_IRQ, handler_1);	
	/* Register interrupt routine for sensor B */
	register_irq(PIO_2_IRQ, handler_2);

	while (1) {
		/* Request hour */
		hour = 14;
		write_pkt(&hour);
		
		/* Get current hour */
		hour = read_hour();

		/* Get the current value of PIO_3 */
		value = read_pio(PIO_3_BASE);
		
		/* Check programmed action for both ar_conf */
		for (i = 0; i < AR_COND_MAX; i++) {
			if (ar_cond[i].start >= hour)
				set_bit(&value, (1 << i);
			else if (ar_cond[i].stop <= hour)
				unset_bit(&value, (1 << i);
			
			write_pio(PIO_3_BASE, value);
		}

		/* Get configuration from phone app */
		vet = read_pkt();
		/* No packet received from phone app */
		if (!vet)
			continue;

		switch (pkt_type) {
		case CONFIG_ACTION_1:
			ar_cond[vet[0]].start = vet[1];
			ar_cond[vet[0]].stop = vet[2];
			break;

		case CONFIG_ACTION_2:
			/* activate/deactivate ar_cond */
			if (vet[1])
				set_bit(&value, (1 << vet[0]));
			else
				unset_bit(&value, (1 << vet[0]))

			write_pio(PIO_3_BASE, value);
		break;

		case CONFIG_ACTION_3:
			ar_cond[vet[0]].notification = vet[1];
			break;

		default:
			printf(“invalid message type\n!!);
			break;
		}
	}
	
	return 0;
}
