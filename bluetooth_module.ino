#define MOTOR_A_a 3
#define MOTOR_A_b 11
#define MOTOR_B_a 5
#define MOTOR_B_b 6
#define MOTOR_SPEED 150
unsigned char m_a_spd = 0, m_b_spd = 0;
boolean m_a_dir = 0, m_b_dir = 0;
void setup()
{
  pinMode(MOTOR_A_a, OUTPUT);
  pinMode(MOTOR_A_b, OUTPUT);
  pinMode(MOTOR_B_a, OUTPUT);
  pinMode(MOTOR_B_b, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello!");
}
void loop()
{
  unsigned char bt_cmd = 0;
  if (Serial.available())
  {
    bt_cmd = Serial.read();
    rc_ctrl_val(bt_cmd);
  }
  motor_drive();
}
void rc_ctrl_val(unsigned char cmd)
{
  if (cmd == 'w')
  {
    m_a_dir = 0;
    m_b_dir = 0;
    m_a_spd = MOTOR_SPEED;
    m_b_spd = MOTOR_SPEED;
  }
  else if (cmd == 'a')
  {
    m_a_dir = 1;
    m_b_dir = 0;
    m_a_spd = MOTOR_SPEED;
    m_b_spd = MOTOR_SPEED;
  }
  else if (cmd == 'd')
  {
    m_a_dir = 0;
    m_b_dir = 1;
    m_a_spd = MOTOR_SPEED;
    m_b_spd = MOTOR_SPEED;
  }
  else if (cmd == 's')
  {
    m_a_dir = 1;
    m_b_dir = 1;
    m_a_spd = MOTOR_SPEED;
    m_b_spd = MOTOR_SPEED;
  }
  else if (cmd == 'x')
  {
    m_a_dir = 0;
    m_b_dir = 0;
    m_a_spd = 0;
    m_b_spd = 0;
  }
}
void motor_drive()
{
  if (m_a_dir == 0)
  {
    digitalWrite(MOTOR_A_a, LOW);
    analogWrite(MOTOR_A_b, m_a_spd);
  }
  else
  {
    analogWrite(MOTOR_A_a, m_a_spd);
    digitalWrite(MOTOR_A_b, LOW);
  }
  if (m_b_dir == 1)
  {
    digitalWrite(MOTOR_B_a, LOW);
    analogWrite(MOTOR_B_b, m_b_spd);
  }
  else
  {
    analogWrite(MOTOR_B_a, m_b_spd);
    digitalWrite(MOTOR_B_b, LOW);
  }
}
