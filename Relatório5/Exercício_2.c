int main (void){
  DDRD = 0;
  DDRD |= (1<<PD7) | (1<<PD6) | (1<<PD5); //PD7=Motor 30HP , PD6=Motor50HP , PD5=Motor70HP
  PORTD |= (1<<PD4) | (1<<PD3) | (1<<PD2); //PD4=Botão1 , PD3=Botão2 , PD2=Botão3
  
  while(1){
    //Ligamento do led através dos botões
    if(!(PIND & (1<<PD4))){
      PORTD |= (1<<PD7);
    }
    if(!(PIND & (1<<PD3))){
       PORTD |= (1<<PD6);
    }
    if(!(PIND & (1<<PD2))){
      PORTD |= (1<<PD5);
    }
    if(!(PIND & (1<<PD2))){
      PORTD &= ~(1<<PD5);
    }
    
    //Combinação dos leds
    if ((PORTD & ((1<<PD7)|(1<<PD5))) == ((1<<PD7)|(1<<PD5))) {
       PORTD &= ~(1<<PD7);
    }
    if ((PORTD & ((1<<PD6)|(1<<PD5))) == ((1<<PD6)|(1<<PD5))) {
       PORTD &= ~(1<<PD6);
        }
    if ((PORTD & ((1<<PD7)|(1<<PD6)|(1<<PD5))) == ((1<<PD7)|(1<<PD6)|(1<<PD5))) {
       PORTD &= ~(1<<PD7);
    }
  }
}
