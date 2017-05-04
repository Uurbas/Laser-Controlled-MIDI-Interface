int delaymotor = 4;
int delaylaser = 1;
int bigdelay = 100;
int sensor = 40;
int y = 0;
int x = 0;
int array1[] = {"a", "b", "c", "d", "e", "f", "g", "h"};
int array2[] = {"h", "g", "f", "e", "d", "c", "b", "a"};
int LEDS1[] = {A5, A4, 2, 3, 4, 5, 6, 7};
int LEDS2[] = {7, 6, 5, 4, 3, 2, A4, A5};
void setup() {
  // put your setup code here, to run once:
  DDRB |= 0x0F; // motor pins
  DDRD |= 0xFC; //Led pins
  DDRC |= 0x30; //Led pins
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  motorslide(7);
  reverseslide(7);

}
void motorslide(byte steps)
{
  for (int i = 0; i <= steps; i++)
  {
    y %= 8;
    x %= 2;
    array1[y] = 0;
    if ( (analogRead(A0) > sensor ) && (array1[y] == 0) )
    {
      digitalWrite(LEDS1[y], HIGH);
      if (y == 0)
        Serial.print('C');
      else if (y == 1)
        Serial.print('D');
      else if (y == 2)
        Serial.print('E');
      else if (y == 3)
        Serial.print('F');
      else if (y == 4)
        Serial.print('G');
      else if (y == 5)
        Serial.print('A');
      else if (y == 6)
        Serial.print('B');
      else
        Serial.print('Z');
      array1[y]++;
    }
    else if (analogRead(A0) < sensor )
    {
      //digitalWrite(13,LOW);
      digitalWrite(LEDS1[y], LOW);
    }
    if (x == 0)
    {
      PORTB |= 0x01;
      PORTB &= ~0x3E;
      delay(delaymotor);
      PORTB |= 0x02;
      PORTB &= ~0x3D;
      delay(delaymotor);
    }
    else
    {
      PORTB |= 0x04;
      PORTB &= ~0x3B;
      delay(delaymotor);
      PORTB |= 0x08;
      PORTB &= ~0x37;
      delay(delaymotor);
    }
    y++;
    x++;
    delay(bigdelay);
  }
}
void reverseslide(byte steps)
{
  for (int j = 0; j <= steps; j++)
  {
    y %= 8;
    x %= 2;
    array2[y] = 0;
    if ( (analogRead(A0) > sensor ) && (array2[y] == 0) )
    {
      digitalWrite(LEDS2[y], HIGH);
      if (y == 0)
        Serial.print('Z');
      else if (y == 1)
        Serial.print('B');
      else if (y == 2)
        Serial.print('A');
      else if (y == 3)
        Serial.print('G');
      else if (y == 4)
        Serial.print('F');
      else if (y == 5)
        Serial.print('E');
      else if (y == 6)
        Serial.print('D');
      else
        Serial.print('C');
      array2[y]++;
    }
    else if (analogRead(A0) < sensor )
    {
      digitalWrite(LEDS2[y], LOW);
    }
    if (x == 0)
    {
      PORTB |= 0x08;
      PORTB &= ~0x37;
      delay(delaymotor);
      PORTB |= 0x04;
      PORTB &= ~0x3B;
      delay(delaymotor);
    }
    else
    {
      PORTB |= 0x02;
      PORTB &= ~0x3D;
      delay(delaymotor);
      PORTB |= 0x01;
      PORTB &= ~0x3E;
      delay(delaymotor);
    }
    y++;
    x++;
    delay(bigdelay);
  }
}
