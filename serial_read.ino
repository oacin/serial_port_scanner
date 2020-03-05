//serial communication library for external devices that isnt an arduino board
#include <SoftwareSerial.h>

//variable to store each char in the scanner buffer
char c;
//variable to concatenate all char readings in one string of text
String text = "";

//uses pin 10 and 11 for communication between the scanner and arduino
SoftwareSerial sc(10 , 11); // TX, RX

void setup() 
{
  //starts arduino serial
  Serial.begin(9600);
  //starts scanner serial
  sc.begin(9600);
  Serial.println("Connected!");
}

void loop()
{
  //while scanner buffer is available
  while (sc.available() != NULL) 
  {
    //reads the char in the buffer[n] index
    c = sc.read();

    //if read char isnt a carriage return 
    if (c != 13)
    {
      //concatenate the char read into the text string 
      text.concat(c);
    }
    //if read char is a carriage return, indicates that it's the end the buffer
    else
    {
      //prints the stored text
      Serial.println(text);
      //clear the text value
      text = "";
    }
  }
}
