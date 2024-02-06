#include <HardwareSerial.h>
#include <Arduino.h>

const char* startCommand = "startTrack(\"Simple pattern\");";
const char* stopCommand = "stop();";

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10);
    Serial.println("Waiting for Serial1 Connection");
  }

  Serial1.begin(9600, SERIAL_8N1, 18, 17);  // Adjust pins as per your hardware setup
  // Wait for serial connection to be established
  while (!Serial1) {
    delay(10);
    Serial.println("Waiting for Serial1 Connection");
  }

  Serial.println("Setup complete.");
}

void loop() {
  // Send start command
  sendCommand(startCommand);
  delay(3000); // Delay before sending the stop command
  // Send stop command
  //sendCommand(stopCommand);
  //delay(3000); // Delay before repeating the process
}

void sendCommand(const char* command) {
  // Send the command over UART
  Serial1.print(command);

  // Read and handle the response if needed
  while (Serial1.available() > 0) {
    char response = Serial1.read();
    Serial.print("Response: ");
    Serial.println(response); // Print response to Serial Monitor
    // Handle the response as needed
  }
}
