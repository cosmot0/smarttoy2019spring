//Echoes what is sent back through the serial port.
int incomingByte = 0;    // for incoming serial data

void setup() {
    Serial.begin(9600);    // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
  
    // read the incoming byte:
    incomingByte = Serial.read();
    incomingByte = incomingByte+1;   //??
    // say what you got:
    Serial.print((char)incomingByte);
  }
  
}

// References : https://gist.github.com/Protoneer/96db95bfb87c3befe46e
