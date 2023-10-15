char s[29] = "ETIANMSURWDKGOHVF L PJBXCYZQ";

void setup(){
    Serial.begin(9600);
}

void loop() {
  Serial.println("Please enter your string: ");
  // Loop which waits for user to enter string in Serial Monitor
  while (Serial.available() == 0) {
  }
  String input = Serial.readString();

  input.trim();
  Serial.println(input);
  int parent = 0;
  for (int i = 0; i <= input.length(); i++) {
    if(input[i] == '.'){
            parent = (2*parent) + 1;
        }
        else if(input[i] == '-'){
            parent = (2*parent) + 2;

        }
        else{
            Serial.print(s[parent-1]);
            parent =0;
        }
  }
}