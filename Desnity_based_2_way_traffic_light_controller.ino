const int IR_A = A0;
const int IR_B = A1;
const int IR_C = A2;
const int IR_D = A3;
const int IR_E = A4;
const int IR_F = A5;

const int led1_red = 4;
const int led1_green = 2;
const int led1_yellow = 3;

const int led2_red = 7;
const int led2_green = 5;
const int led2_yellow = 6;

unsigned int line1_time=5000;
unsigned int line2_time=5000;

void all_led_off()
{
  digitalWrite(led1_red, LOW);
  digitalWrite(led1_green, LOW);
  digitalWrite(led1_yellow, LOW);
  digitalWrite(led2_red, LOW);
  digitalWrite(led2_green, LOW);
  digitalWrite(led2_yellow, LOW);
}


void all_led_on()
{
  digitalWrite(led1_red, HIGH);
  digitalWrite(led1_green, HIGH);
  digitalWrite(led1_yellow, HIGH);
  digitalWrite(led2_red, HIGH);
  digitalWrite(led2_green, HIGH);
  digitalWrite(led2_yellow, HIGH);
}

void setup() 
{
  Serial.begin(9600);
  pinMode(IR_A,  INPUT);
  pinMode(IR_B, INPUT);
  pinMode(IR_C, INPUT);
  pinMode(IR_D,  INPUT);
  pinMode(IR_E, INPUT);
  pinMode(IR_F, INPUT);
  pinMode(led1_red,  OUTPUT);
  pinMode(led1_green,  OUTPUT);
  pinMode(led1_yellow,  OUTPUT);
  pinMode(led2_red,  OUTPUT);
  pinMode(led2_green,  OUTPUT);
  pinMode(led2_yellow,  OUTPUT);
  
  
}

void run_traffic_lights()
{
  all_led_off();
  digitalWrite(led1_green, HIGH);
  digitalWrite(led2_red, HIGH);
  delay(line1_time);
  all_led_off();
  digitalWrite(led1_yellow, HIGH);
  digitalWrite(led2_yellow, HIGH);
  delay(1000);
  all_led_off();
  digitalWrite(led1_red, HIGH);
  digitalWrite(led2_green, HIGH);
  delay(line2_time);
  all_led_off();
  digitalWrite(led1_yellow, HIGH);
  digitalWrite(led2_yellow, HIGH);
  delay(1000);
  all_led_off();
}
void loop() 
{
  run_traffic_lights();
  line1_time = 5000;
  line2_time = 5000;

  if(digitalRead(IR_A) == HIGH)
  {
    line1_time = 20000;
  }
  if(digitalRead(IR_B) == HIGH)
  {
    line1_time = 30000;
  }
  if(digitalRead(IR_C) == HIGH)
  {
    line1_time = 40000;
  }

  if(digitalRead(IR_D) == HIGH)
  {
    line2_time = 20000;
  }
  if(digitalRead(IR_E) == HIGH)
  {
    line2_time = 30000;
  }
  if(digitalRead(IR_F) == HIGH)
  {
    line2_time = 40000;
  }


  Serial.print("Line1 Time: ");
  Serial.print(line1_time);
  Serial.print("  Line2 Time: ");
  Serial.println(line2_time);
  
  
}
