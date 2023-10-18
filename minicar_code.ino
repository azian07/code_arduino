#define MOTOR_A_a 3 // 모터A의 +출력핀은 3번핀입니다
#define MOTOR_A_b 11 // 모터A의 -출력핀은 11번핀입니다
#define MOTOR_B_a 5 // 모터B의 +출력핀은 5번핀입니다
#define MOTOR_B_b 6 // 모터B의 -출력핀은 6번핀입니다
#define MOTOR_SPEED 150 // 모터의 기준속력입니다 (0~255)

void setup() {
  // 모터 제어 핀들을 출력으로 설정합니다.
  pinMode(MOTOR_A_a, OUTPUT);
  pinMode(MOTOR_A_b, OUTPUT);
  pinMode(MOTOR_B_a, OUTPUT);
  pinMode(MOTOR_B_b, OUTPUT);
  Serial.begin(9600); // 시리얼 통신 초기화
  Serial.println("Hello!"); // 터미널 작동 확인용 문자열
}

void loop() {
  // 앞으로 움직임
  
  moveForward();
}

void moveForward() {
  digitalWrite(MOTOR_A_a, LOW); // 모터A+ LOW
  analogWrite(MOTOR_A_b, MOTOR_SPEED); // 모터A-의 속력을 PWM 출력
  digitalWrite(MOTOR_B_a, LOW); // 모터B+ LOW
  analogWrite(MOTOR_B_b, MOTOR_SPEED); // 모터B-의 속력을 PWM 출력
}
