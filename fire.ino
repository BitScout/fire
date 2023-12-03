

#define SETS     2 // Number of LED sets (rows)
#define SET_SIZE 4 // Max number of LEDs per set

long deylayed;

// Exterior array is a list of rows of LED pins, each interior array is a list of LED pins that will light up in a row
const long leds[SETS][SET_SIZE] = {{2,3,4,5},{A0,A1,A2}};

// Number of LEDs per set, this way sets don't have to be equally long; do not exceed SET_SIZE!
const int setSize[SETS] = {4,3};

// Storage for each set, noting if we're switching LEDs on or off
bool stateChanges[SETS] = {false, false};

// Storage for planning at what time we're going to turn what LED on or off
long stateChangesAt[SETS][SET_SIZE] = {{0, 0, 0, 0}, {0, 0, 0}};

void setup() {
  for(int s=0; s < SETS; s++) {
    for(int i=0; i < setSize[s]; i++) {
      pinMode(leds[s][i], OUTPUT);
    }
  }
}

void loop() {
  for(int s=0; s < SETS; s++) {
    for(int i=0; i < setSize[s]; i++) {
      if(millis() >= stateChangesAt[s][i]) {
        digitalWrite(leds[s][i], stateChanges[s]);
  
        if(i >= setSize[s] - 1) {
          stateChanges[s] = !stateChanges[s];
          setStateChanges(s);
        }
      }
    }
  }
}

void setStateChanges(int s) {
  deylayed = millis();
  
  for(int i=0; i < setSize[s]; i++) {
    deylayed += 30 + random(100);
    stateChangesAt[s][i] = deylayed;
  }
}
