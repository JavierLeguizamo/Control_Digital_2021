#define F_CPU 8e6
#include <avr/io.h>
#include <avr/interrupt.h>
int y[4],xn;

ISR(ADC_vect){
	xn=ADC;
	y[0]=5*xn+2*y[1]+4*y[2]+3*y[3];
	y[1]=y[0];
	y[2]=y[1];
	y[3]=y[2];
}

ISR(TIMER0_COMPA_vect){
	
}

int main(void)
{
    DDRB |= 0xff;
	ADMUX |= 1<<REFS0;
	ADCSRA |= _BV(ADEN) | _BV(ADATE) | _BV(ADIE) | _BV(ADPS0);
	ADCSRB |= _BV(ADTS0) | _BV(ADTS1);
	OCR0A = 255;
	TCCR0A |=_BV(WGM01);
	TCCR0B |= _BV(CS01);
	TIMSK0 |= _BV(OCIE0A);
	sei();
    while (1) 
    {
    }
}

