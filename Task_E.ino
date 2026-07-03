
 
int buzzerPIN = 8;
int numSegments = 7;
int segPINS[] = {2,3,4,5,6,7,9};//a,b,c,d,e,f,g
 
// The pattern for each digit. 1 = segment ON, 0 = segment OFF.
byte digits[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},   // 0
    {0, 1, 1, 0, 0, 0, 0},   // 1
    {1, 1, 0, 1, 1, 0, 1},   // 2
    {1, 1, 1, 1, 0, 0, 1},   // 3
    {0, 1, 1, 0, 0, 1, 1},   // 4
    {1, 0, 1, 1, 0, 1, 1},   // 5
    {1, 0, 1, 1, 1, 1, 1},   // 6
    {1, 1, 1, 0, 0, 0, 0},   // 7
    {1, 1, 1, 1, 1, 1, 1},   // 8
    {1, 1, 1, 1, 0, 1, 1},   // 9
};

void showDigit(int n){
  for(int i = 0;i < numSegments;i++){
     digitalWrite(segPINS[i],digits[n][i]);
  }
}
 
void setup() {
    Serial.begin(9600);
 
    pinMode(buzzerPIN, OUTPUT);         
 
    for (int i = 0; i < numSegments; i++) {
        pinMode(segPINS[i], OUTPUT);      
    }
 
    Serial.println("=== Beeping Countdown initalization  ===");
 
    int count = 9;
    while (count != 0){
        Serial.print("Counting: ");
        Serial.println(count);
        showDigit(count);
        tone(buzzerPIN,950,200);
        delay(1000);
        count=count-1;
    }
 
        showDigit(0);
      tone(buzzerPIN,1000, 1500);     
        Serial.println("===coundown successful===");
}

void loop(){

}

