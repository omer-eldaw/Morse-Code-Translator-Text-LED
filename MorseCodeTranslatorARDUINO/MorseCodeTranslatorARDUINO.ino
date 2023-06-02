int buzzer = 4;
int unit_of_time = 100;
String Text = "";

void setup() {

  pinMode(buzzer, OUTPUT);

  for (int i = 0; i < Text.length(); i++) {
    String temp_string; 
    temp_string += Text[i];
    if (temp_string == ".") {
      digitalWrite(buzzer, HIGH);
      delay(unit_of_time);
      digitalWrite(buzzer, LOW);
      delay(unit_of_time);


    }
    
    else if (temp_string == "-") {
      digitalWrite(buzzer, HIGH);
      delay(unit_of_time * 3);
      digitalWrite(buzzer, LOW);
      delay(unit_of_time);

    }

    else if (temp_string == " ") {
      delay(unit_of_time * 2);
      
    }

    else if(temp_string == "|") {
      delay(unit_of_time * 6);
    };

  }

  delay(5000);
}

void loop() {

}
