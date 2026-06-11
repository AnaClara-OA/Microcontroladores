int main(void){
    DDRD = 0; //PD5 entrada de NA , PD4 entrada de NF , PD3 S1 
    DDRD |= (1 << PD7) | (1 << PD6); //PD7 motor high  e PD6 alarme
	PORTD |= (1 << PD4) | (1 << PD3);
	PORTD &= ~(1 << PD5);

  while(1){
    if(PIND & (1 << PD5)){
      PORTD |=(1 << PD7);
      PORTD &= ~(1<< PD6);

    } else if(!(PIND & (1 << PD4 ))){
      PORTD &= ~(1 << PD7);

    }else if(!(PIND & (1 << PD3))){
      PORTD |=(1 << PD6);
      PORTD &= ~(1<< PD7);

    }
  }
}
