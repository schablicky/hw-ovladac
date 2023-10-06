#include #include
const int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;

int pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void setup() {
	Serial.begin(9600);
	irrecv.enableIRIn();
	irrecv.blink13(true);

for (int i = 0; i < 10; i++)
{
	pinMode(pins[i], OUTPUT);
	digitalWrite(pins[i], LOW);
}

}

void loop() {
if (irrecv.decode(&results)){
Serial.println(results.value, HEX);
irrecv.resume();

for (int i = 0; i < 10; i++)
{
pinMode(pins[i], OUTPUT);
digitalWrite(pins[i], LOW);
}

switch (results.value)
{
	case 0x9C584175:
		digitalWrite(pins[0], HIGH);
		break;
	case 0x1767AF71:
		digitalWrite(pins[1], HIGH);
		break;
	case 0x318A151:
		digitalWrite(pins[2], HIGH);
		break;
	case 0xFCA418D1:
		digitalWrite(pins[3], HIGH);
		break;
	case 0xAFD97D5:
		digitalWrite(pins[4], HIGH);
		break;
	case 0xE7AF0F51:
		digitalWrite(pins[5], HIGH);
		break;
	case 0x474E8371:
		digitalWrite(pins[6], HIGH);
		break;
	case 0xB21EF5AD:
		digitalWrite(pins[7], HIGH);
		break;
	case 0xC07874B1:
		digitalWrite(pins[8], HIGH);
		break;
	case 0x55B9A80D:
		digitalWrite(pins[9], HIGH);
		break;
		}
	}
}