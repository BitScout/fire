

#define REDS    3
#define YELLOWS 3

#define PIN_LED_RED_1     A0
#define PIN_LED_RED_2     A1
#define PIN_LED_RED_3     A2
#define PIN_LED_YELLOW_1  A4
#define PIN_LED_YELLOW_2  A5
#define PIN_LED_YELLOW_3  2

long deylayed;

int redLeds[REDS] =       {PIN_LED_RED_1, PIN_LED_RED_2, PIN_LED_RED_3};
int yellowLeds[YELLOWS] = {PIN_LED_YELLOW_1, PIN_LED_YELLOW_2, PIN_LED_YELLOW_3};

bool redStateChange = true;
bool yellowStateChange = true;
long redStateChangeAt[REDS] =        {0, 0, 0};
long yellowStateChangeAt[YELLOWS] =  {0, 0, 0};

void setup() {
  Serial.begin(9600);
  
  pinMode(PIN_LED_RED_1, OUTPUT);
  pinMode(PIN_LED_RED_2, OUTPUT);
  pinMode(PIN_LED_RED_3, OUTPUT);
  pinMode(PIN_LED_YELLOW_1, OUTPUT);
  pinMode(PIN_LED_YELLOW_2, OUTPUT);
  pinMode(PIN_LED_YELLOW_3, OUTPUT);
}

void loop() {

  for(int i=0; i < REDS; i++) {
    if(millis() >= redStateChangeAt[i]) {
      digitalWrite(redLeds[i], redStateChange);

      if(i >= REDS - 1) {
        redStateChange = !redStateChange;
        setRedStateChanges();
      }
    }
  }

  for(int i=0; i < YELLOWS; i++) {
    if(millis() >= yellowStateChangeAt[i]) {
      digitalWrite(yellowLeds[i], yellowStateChange);

      if(i >= YELLOWS - 1) {
        yellowStateChange = !yellowStateChange;
        setYellowStateChanges();
      }
    }
  }

}

void setRedStateChanges() {
  deylayed = millis();
  
  for(int i=0; i < REDS; i++) {
    deylayed += 30 + random(110);
    redStateChangeAt[i] = deylayed;
  }
}

void setYellowStateChanges() {
  deylayed = millis();
  
  for(int i=0; i < YELLOWS; i++) {
    deylayed += 20 + random(90);
    yellowStateChangeAt[i] = deylayed;
  }
}
