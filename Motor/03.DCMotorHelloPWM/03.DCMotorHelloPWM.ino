

int IN1 = 9;

int IN2 = 6;

int enA = 5;

int IN4 = 10;

int IN3 = 11;

int enB = 3;

 

int motorSpeedA = 0;

int motorSpeedB = 0;

 

void setup() {

 

  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);  

  

  pinMode(enA, OUTPUT);

  pinMode(IN1, OUTPUT);    

  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);    

  pinMode(IN4, OUTPUT);

  pinMode(enB, OUTPUT);

 

 

  // Set initial rotation direction

  // forward

  digitalWrite(IN1, HIGH);

  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);

  digitalWrite(IN4, LOW);

 

 

  // Initial speed

  motorSpeedA = 128; // 0~255

  motorSpeedB = 128;

  

}

 

void loop() {

  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }
  
  // 시리얼 모니터로 부터 입력 받은 데이터를 블루투스로 송신한다.
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }

  

  if (motorSpeedA < 0) 

  {

    motorSpeedA = 0;

  }

  if (motorSpeedA > 255) 

  {

    motorSpeedA = 255;

  }

  if (motorSpeedB < 0) 

  {

    motorSpeedB = 0;

  }

  if (motorSpeedB > 255) 

  {

    motorSpeedB = 255;

  }

    

  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A

  analogWrite(enB, motorSpeedB); // Send PWM signal to motor A

}

 

 

 

void serialEvent() {

  while (Serial.available()) 

  {

    // get the new byte:

    char inChar = (char)Serial.read();

    

    if(inChar == '0')

    {

      digitalWrite(IN1, LOW); 

      digitalWrite(IN2, LOW);

      digitalWrite(IN3, LOW); 

      digitalWrite(IN4, LOW);

      

    }

    else if(inChar == 'f')

    {

      digitalWrite(IN1, HIGH);

      digitalWrite(IN2, LOW);

      digitalWrite(IN3, HIGH);

      digitalWrite(IN4, LOW);

      

    }

    else if(inChar == 'b')

    {

      digitalWrite(IN1, LOW);

      digitalWrite(IN2, HIGH);

      digitalWrite(IN3, LOW);

      digitalWrite(IN4, HIGH);

    }

    else if(inChar == 'w')

    {

       motorSpeedA = motorSpeedA +5;

       motorSpeedB = motorSpeedB +5;

       Serial.println(motorSpeedA);

          if (motorSpeedA,motorSpeedB > 255) 

          {

             motorSpeedA = 255;

             motorSpeedB = 255;

          }

      }

   else if(inChar == 's')

    {

       motorSpeedA = motorSpeedA - 5;

       motorSpeedB = motorSpeedB - 5;

       Serial.println(motorSpeedA);

      if (motorSpeedA,motorSpeedB < 0) 

  {

    motorSpeedA = 0;

    motorSpeedB = 0;

  }

    }

  }

}

