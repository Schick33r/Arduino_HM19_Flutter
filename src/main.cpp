#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial ble(2, 3); //RX, TX
String serialBuffer = "";
String oldBuffer = "";

void setup() {
  Serial.begin(9600); // Serial port for debugging
  ble.begin(9600);
  Serial.println("Serial available"); // Bluetoothmodule
}

void loop() {
   while(ble.available() > 0) {
     /// READING
     char ch = ble.read();
      serialBuffer += ch;
      if (ch == '\n') { // SERIAL READ UNTIL '\n' IS SENT
        Serial.print("SerialRead: ");
        Serial.println(serialBuffer);
        oldBuffer = serialBuffer;
        oldBuffer.remove(oldBuffer.length() - 1, 2); // CUT OFF THE \n
        Serial.println(oldBuffer);
        serialBuffer = "";

        /// WRITE AFTER READ
        delay(2000);
        ble.print( oldBuffer + " received and sent");
        Serial.println("Message successfully sent to app"); // Print to Serial Monitor
        /// END WRITE
      }
  
  }
}




