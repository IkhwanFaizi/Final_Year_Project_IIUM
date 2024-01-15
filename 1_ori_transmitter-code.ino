#define TRANSMIT_LED 3
#define SAMPLING_TIME 5

char* text = "U";

bool led_state = false;    
bool transmit_data = true;
int bytes_counter = 5;
int total_bytes;
char data_byte;

void setup() 
{
  Serial.begin(9600);
  pinMode(TRANSMIT_LED,OUTPUT);
  total_bytes = strlen(text);
}

void loop() 
{
   while(transmit_data)
   {
    transmit_byte(text[total_bytes - bytes_counter]);
    bytes_counter--;
      if(bytes_counter == 0)
      {
        transmit_data = false;
      } 
   }
   transmit_data = true;
   bytes_counter = total_bytes;
   delay(100);
}

char transmit_byte(char data_byte)   
{
  digitalWrite(TRANSMIT_LED,LOW);
  delay(SAMPLING_TIME);
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(TRANSMIT_LED,(data_byte >> i) & 0x01);
    delay(SAMPLING_TIME); 
    Serial.print(data_byte);
  }
 digitalWrite(TRANSMIT_LED,HIGH); //Return to IDLE state
 delay(1);
 return data_byte;
}
