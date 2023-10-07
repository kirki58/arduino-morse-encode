#define buzzer 12
#define led 8

String code;
int len;
static String morse_encode_char(char c){
     switch (c) {
    case 'a':
        return String(".-");
    case 'b':
        return String("-...");
    case 'c':
        return String("-.-.");
    case 'd':
        return String("-..");
    case 'e':
        return String(".");
    case 'f':
        return String("..-.");
    case 'g':
        return String("--.");
    case 'h':
        return String("....");
    case 'i':
        return String("..");
    case 'j':
        return String(".---");
    case 'k':
        return String("-.-");
    case 'l':
        return String(".-..");
    case 'm':
        return String("--");
    case 'n':
        return String("-.");
    case 'o':
        return String("---");
    case 'p':
        return String(".--.");
    case 'q':
        return String("--.-");
    case 'r':
        return String(".-.");
    case 's':
        return String("...");
    case 't':
        return String("-");
    case 'u':
        return String("..-");
    case 'v':
        return String("...-");
    case 'w':
        return String(".--");
    case 'x':
        return String("-..-");
    case 'y':
        return String("-.--");
    case 'z':
        return String("--..");
    case '1':
        return String(".----");
    case '2':
        return String("..---");
    case '3':
        return String("...--");
    case '4':
        return String("....-");
    case '5':
        return String(".....");
    case '6':
        return String("-....");
    case '7':
        return String("--...");
    case '8':
        return String("---..");
    case '9':
        return String("----.");
    case '0':
        return String("-----");
    default:
        return String(" ");
    }
}

String morse_encode(String str){
    String res = "";
    for (size_t i = 0; i < str.length(); i++)
    {
        res += morse_encode_char(str[i]);
        res += String("");
    }
    return res;
}


void led_dash(int pin){
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin,LOW);
  delay(1000);
}
void led_dot(int pin){
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin,LOW);
  delay(500);
}
void setup(){
    pinMode(8, OUTPUT);
    pinMode(12, OUTPUT);
    code = morse_encode("hey");
    len = code.length();
}
void loop(){
    for(int i = 0; i<len; i++){
      if(code[i] == '-'){
        led_dash(led);
      }
      else if(code[i] == '.'){
        led_dot(led);
      }
      else{
        delay(50);
      }
    }
    exit(0);
}
