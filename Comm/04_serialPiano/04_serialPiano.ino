 int speak = 9;

int incomingByte = 0;    // for incoming serial data

void setup() {

    Serial.begin(9600);    // opens serial port, sets data rate to 9600 bps

    pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {

  // send data only when you receive data:

  if (Serial.available() > 0) {

  

    // read the incoming byte:

    incomingByte = Serial.read();

    //incomingByte = incomingByte+1;

    if(incomingByte == '1')

     tone(speak,261.6256, 500) ;

     else if(incomingByte == '2')

     tone(speak,293.6648, 500) ;

     else if(incomingByte == '3')

     tone(speak,329.6276, 500) ;

     else if(incomingByte == '4')

     tone(speak,349.2282, 500) ;

     else if(incomingByte == '5')

     tone(speak,391.9954, 500) ;

     else if(incomingByte == '6')

     tone(speak,440.0000, 500) ;

     else if(incomingByte == '7')

     tone(speak,493.8833, 500) ;

     else if(incomingByte == '8')

     tone(speak,523.2511, 500) ;

     else if(incomingByte == '9')

     tone(speak,587.3295, 500) ;

     else if(incomingByte == 'a')

     tone(speak,659.2551, 500) ;

     else if(incomingByte == 's')

     tone(speak,698.4565, 500) ;

      else if(incomingByte == 'd')

     tone(speak,783.9909, 500) ;

      else if(incomingByte == 'f')

     tone(speak,880.0000, 500) ;

      else if(incomingByte == 'g')

     tone(speak,987.7666, 500) ;

      else if(incomingByte == 'h')

     tone(speak,1046.502, 500) ;

      else if(incomingByte == 'j')

     tone(speak,1046.502, 500) ;

   

   

     

    }

    }
