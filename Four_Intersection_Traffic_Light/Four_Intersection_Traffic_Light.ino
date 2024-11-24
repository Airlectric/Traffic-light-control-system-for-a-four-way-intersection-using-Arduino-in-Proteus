// Pin definitions
const int trafficLights[4][3] = {
  {2, 3, 4},   // Lane 1: Red, Yellow, Green
  {5, 6, 7},   // Lane 2: Red, Yellow, Green
  {8, 9, 10},  // Lane 3: Red, Yellow, Green
  {11, 12, 13} // Lane 4: Red, Yellow, Green
};

// Timing constants
const int greenTime = 5000;  // Green light duration (ms)
const int yellowTime = 2000; // Yellow light duration (ms)

void setup() {
  // Set up traffic lights as OUTPUT
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      pinMode(trafficLights[i][j], OUTPUT);
    }
  }
}

void loop() {
  // Cycle through each lane
  for (int i = 0; i < 4; i++) {
    manageTraffic(i);
  }
}

void manageTraffic(int lane) {
  // Green light for the current lane
  setTrafficLight(lane, HIGH, LOW, LOW); // Red off, Yellow off, Green on
  delay(greenTime);

  // Yellow light for the current lane
  setTrafficLight(lane, LOW, HIGH, LOW); // Red off, Yellow on, Green off
  delay(yellowTime);

  // Red light for the current lane
  setTrafficLight(lane, LOW, LOW, HIGH); // Red on, Yellow off, Green off
}

void setTrafficLight(int lane, int green, int yellow, int red) {
  digitalWrite(trafficLights[lane][0], red);    // Red light
  digitalWrite(trafficLights[lane][1], yellow); // Yellow light
  digitalWrite(trafficLights[lane][2], green);  // Green light
}
