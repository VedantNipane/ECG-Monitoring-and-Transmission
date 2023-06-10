#include "SPIFFS.h"
#include <WiFi.h>

const char* ssid = "MyWifi";
const char* password = "abcdef123";

const int pin = 34; // the pin you want to read from
const char* filename = "/data.csv"; // the name of the file to save the data in
const int numReadings = 44605; // number of readings to take before saving to the file
int readingsTaken = 0;

void setup() {
  Serial.begin(115200);
  if(!SPIFFS.begin(true)){
    //Serial.println("An error occurred while mounting SPIFFS");
    return;
  }
  else
   // Serial.println("Success");
  
  WiFi.begin(ssid, password);
 // Serial.print("Connecting to ");
 // Serial.print(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  //  Serial.print(".");
  }
  // Serial.println("");
  // Serial.println("WiFi connected.");
  // Serial.println("IP address: ");
  // Serial.println(WiFi.localIP());
  
  delay(1000);
}


void loop()
{
  // open the file in append mode
  File file = SPIFFS.open(filename, "a");
  for (int i = 0; i < numReadings; i++)
  {
    // read the data from the pin
    // int data = analogRead(pin);
    double data = getDataFromESP32();
    Serial.println(data);
    // write the data to the file
    file.print(data);
    file.print(",");
    readingsTaken++;
   // Serial.println("Data added to file.");
    delay(2);
  }
  file.close();
 // Serial.println("Data saved to file.");
  // terminate the loop after saving the desired number of readings
  while (true) {
    delay(1000); // delay to avoid a tight loop
  }
}

double getDataFromESP32() {
  // replace this with your code to read data from your ESP32
  //return random(2000, 2500);
  return analogRead(pin);
}
