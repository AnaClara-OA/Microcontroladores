int main() {
  DDRD |= (1 << PD5) | (1 << PD4);

  EICRA |= (1 << ISC00) | (1 << ISC01);
  EIMSK = (1 << INT0);

  sei();
  for(;;) {
    PORTD |= (1 << PD5);
    _delay_ms(500);
    PORTD &= ~(1 << PD5);
    _delay_ms(500);
  }
}
ISR(INT0_vect) {
  PORTD |= (1 << PD4);
  _delay_ms(1000);
  PORTD &= ~(1 << PD4);
}
