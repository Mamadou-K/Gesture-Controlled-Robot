// --- Motors Pins ---
const int LM_IN1 = 2;
const int LM_IN2 = 3;
const int LM_EN  = 9;
const int RM_IN1 = 4;
const int RM_IN2 = 5;
const int RM_EN  = 10;

// --- Analog Input Pins (Potentiometers) ---
const int potLR = A0;   // Controls turning direction (Left/Right)
const int potFB = A1;   // Controls movement direction (Forward/Backward)
const int potS = A2;  // Controls speed magnitude (Throttle)

// --- Control Constants ---
const int ADC_CENTER = 512;        
const int DEAD_ZONE = 50;          
const int TURN_SPEED_RATIO = 10;   

// --- Motor Specs ---
const int NL_RPM = 7500;       // No-load max RPM
const int MAX_RPM = 500;       // Maximum RPM
const int MAX_PWM = 255;       // Maximum PWM value

const int PWM_CAP = ( (long)MAX_PWM * MAX_RPM ) / NL_RPM; 

void setup() {
  Serial.begin(115200);
  pinMode(LM_IN1, OUTPUT);
  pinMode(LM_IN2, OUTPUT);
  pinMode(LM_EN, OUTPUT);
  pinMode(RM_IN1, OUTPUT);
  pinMode(RM_IN2, OUTPUT);
  pinMode(RM_EN, OUTPUT);
}

void setMotor(int speed, int in1, int in2, int en) {
  int absSpeed = abs(speed);
  
  if (speed > 0) { 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else if (speed < 0) { 
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  } else { 
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
  analogWrite(en, absSpeed); 
}

void loop() {
  int rawLR = analogRead(potLR);
  int rawFB = analogRead(potFB);
  int rawS = analogRead(potS);

  int throttle = map(rawS, 0, 1023, 0, PWM_CAP);

  // Determine Direction/Steering States ( -1=Backward, 0=Stop, 1=Forward | -1=Left, 0=Straight, 1=Right )
  int moveState = rawFB - ADC_CENTER;
  int direction = 0;
  if (moveState > DEAD_ZONE) {
    direction = 1;
  } else if (moveState < -DEAD_ZONE) {
    direction = -1;
  }

  int turnState = rawLR - ADC_CENTER;
  int steering = 0;
  if (turnState > DEAD_ZONE) {
    steering = 1;
  } else if (turnState < -DEAD_ZONE) {
    steering = -1;
  }
  
  int leftSpeed = 0;
  int rightSpeed = 0;

  const int fullSpeed = throttle;
  
  // Speed for the slower motor during a turn
  const int slowSpeed = (fullSpeed * TURN_SPEED_RATIO) / 100;

  // Combined state integer: Forward-Straight = 10 , Forward-Right = 11, Forward-Left = 9, Backward-Straight = -10, Backward-Right = -9, Backward-Left = -11, Spin-Right = 1, Spin-Left = -1
  int combined_state = direction * 10 + steering;

  switch (combined_state) {
      // --- FORWARD MOVEMENT ---
      case 10: 
          leftSpeed = fullSpeed; rightSpeed = fullSpeed;
          break;
      case 11: 
          leftSpeed = fullSpeed; rightSpeed = slowSpeed;
          break;
      case 9:  
          leftSpeed = slowSpeed; rightSpeed = fullSpeed;
          break;

      // --- BACKWARD MOVEMENT ---
      case -10: 
          leftSpeed = -fullSpeed; rightSpeed = -fullSpeed;
          break;
      case -9: 
          leftSpeed = -fullSpeed; rightSpeed = -slowSpeed;
          break;
      case -11: 
          leftSpeed = -slowSpeed; rightSpeed = -fullSpeed;
          break;
          
      // --- SPIN MOVEMENT ---
      case 1:  
          leftSpeed = fullSpeed; rightSpeed = -fullSpeed;
          break;
      case -1: 
          leftSpeed = -fullSpeed; rightSpeed = fullSpeed;
          break;
      // --- IDLE MOVEMENT ---   
      case 0:  
      default: 
          leftSpeed = 0; rightSpeed = 0;
          break;
  }
  
  setMotor(leftSpeed, LM_IN1, LM_IN2, LM_EN);
  setMotor(rightSpeed, RM_IN1, RM_IN2, RM_EN);
  
  const char* action_desc = "Idle"; 
  int throttle_rpm = map(throttle, 0, PWM_CAP, 0, MAX_RPM); // Estimated RPM

  if (combined_state != 0 && throttle > 0) {
    switch (combined_state) {
      case 10:  action_desc = "Forward-Straight"; break;
      case 11:  action_desc = "Forward-Right"; break;      
      case 9:   action_desc = "Forward-Left"; break;
      case -10: action_desc = "Backward-Straight"; break;   
      case -9:  action_desc = "Backward-Left"; break;      
      case -11: action_desc = "Backward-Right"; break;
      case 1:   action_desc = "Spin-Right"; break;      
      case -1:  action_desc = "Spin-Left"; break;
      default:  action_desc = "idle"; break;
  }
  Serial.print("Action: "); Serial.print(action_desc);
  Serial.print(" | Throttle: "); Serial.print(throttle_rpm); Serial.print(" RPM");
  Serial.print(" | Throttle (PWM): "); Serial.println(throttle);


  delay(100);
}
}
