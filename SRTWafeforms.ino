//Raúl Pérez Sánchez
//Sample and Holding
//You can choose the waveform you want to be printed on the loop. It can be one at a time 

int Sine_Wave; // Sine wave variable
bool state = true; // Compares the last value for the chopper in the S/H circuit 1 or 0
int i = 0; //Counter for the for loops
void setup() {
 
  DDRD = B11111111;  // Sets port D as outputs (pins 0-7)
  DDRB = B100000; // Sets the MSB from port B as an output (pin 13) 
  TCCR1B = 0; //It is needed to have precise control of the square wave by using the atmega328 TIMER1 it sets to zero all bits from TCCR1B register
  TCCR1A = 0; //It is needed to have precise control of the square wave by using the atmega328 TIMER1 it sets to zero all bits from TCCR1A register
  TCNT1 = 65530; //Defines the value for TIMER1 to overflow. 1kHZ pulsed frquency for this example.
  TCCR1B |= (1<<CS10); // Sets the 1024 preescaler of the TIMER1
  TCCR1B |= (1<<CS12); // Sets the 1024 preescaler of the TIMER1
  TIMSK1 |= (1<<TOIE1); // Enables the Timer1 overflow interrupts 
  
}

// Interrupt subroutine
// Switch on and off the pin 13 
ISR(TIMER1_OVF_vect){
    if(state){
      PORTB = 100000;
      state = !state;
    }
    else{
      PORTB = 000000;
      state = true;
    }
    TCNT1 = 65530;
}

void loop(){
  
  //uncomment the code above to get a sine wave on the output.
  /*
  for (i = 0; i < 360; i++) { 
    Sine_Wave = ((sin(i * DEG_TO_RAD) + 1) * 255) / 2; 
    PORTD = Sine_Wave; 
    delayMicroseconds(1); // Change to adjust the frequency
  }*/

  //Uncomment the code above to get a ramp function
  /*
  for(i=0;i<256;i++){
      PORTD = i;
      delayMicroseconds(50);
  }
      PORTD = B00000000;
      */
  //Uncomment the code above to get a triangular function
   /*
   for(i = 0;i < 256;i++){
      PORTD = i;
      delayMicroseconds(50);
   }

   for(i = 256;i > 0;i--){
      PORTD = i;
      delayMicroseconds(50);
   }
   */
}
