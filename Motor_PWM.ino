#include <Arduino.h>
#include <U8x8lib.h>
#include <Wire.h>

#define pwm 6 //2,6,7 worked

U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // OLEDs without Reset of the Display

// Counts number of button presses
// output count to serial
// blink a led according to count

byte switchPin = 1;                    // switch is connected to pin 2
//byte ledPin = 13;                      // led on pin 13
byte buttonPresses = 0;                // how many times the button has been pressed 
byte lastPressCount = 0;               // to keep track of last press count

int pwmVal = 0;

void setup() {
  pinMode(switchPin, INPUT);          // Set the switch pin as input
  digitalWrite(switchPin, HIGH);      // set pullup resistor
  Serial.begin(9600);                 // Set up serial communication at 9600bps
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pwm,OUTPUT); //define pwm
  //screen
  u8x8.begin();
  u8x8.setFlipMode(1);   // set number from 1 to 3, the screen word will rotary 180

  
}

void loop(){

    u8x8.setFont(u8x8_font_chroma48medium8_r);
    u8x8.setCursor(0, 0);
    u8x8.print("Presses = ");
    u8x8.print(buttonPresses);
    u8x8.setCursor(0,3);
    //u8x8.print("             ");
    u8x8.setCursor(0,3);
    u8x8.print("PWM Val =  ");
    u8x8.print(pwmVal);
    u8x8.print("  ");//removes previous characters that don't get refreshed

  
  if (digitalRead(switchPin) == LOW)  // check if button was pressed
  {
    buttonPresses++;                  // increment buttonPresses count
    delay(250);                       // debounce switch
  }
  if (buttonPresses == 10) buttonPresses = 0;         // rollover every tenth press
  if (lastPressCount != buttonPresses)              // only do output if the count has changed
  {
    Serial.print ("Button press count = ");          // out to serial
    Serial.println(buttonPresses, DEC);
    
    

if (buttonPresses==0)
  {
    pwmVal = 0.000;
  }
if (buttonPresses==1)
  {
    pwmVal = 100;
  }
if (buttonPresses==2)
  {
    pwmVal = 119;
  }
if (buttonPresses==3)
  {
    pwmVal = 139;
  }
if (buttonPresses==4)
  {
    pwmVal = 158;
  }
if (buttonPresses==5)
  {
    pwmVal = 177;
  }
if (buttonPresses==6)
  {
    pwmVal = 196;
  }
if (buttonPresses==7)
  {
    pwmVal = 216;
  }
if (buttonPresses==8)
  {
    pwmVal = 236;
  }
if (buttonPresses==9)
  {
    pwmVal = 255;
  }

analogWrite(pwm,pwmVal);
  Serial.print ("PWM VALUE = ");
  Serial.println(pwmVal, DEC);
  
  lastPressCount = buttonPresses;    // track last press count
  }
}
