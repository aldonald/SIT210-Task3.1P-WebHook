// Source code is based on example testing sketch for DHT humidity/temperature sensors

#include "Adafruit_DHT.h"

#define DHTPIN A0

#define DHTTYPE DHT22		// DHT 22 (AM2302)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(9600); 
	Serial.println("Test has started");
	dht.begin();
}

void loop() {

// Read temperature as Celsius
	float t = dht.getTempCelcius();
  
// Check if read failed and don't try to print result.
	if (isnan(t)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}
	
	String temp = String(t);
	
	Particle.publish("temp", temp, PRIVATE);

// Printing to serial monitor to bug test the code.
	Serial.print("Temp: "); 
	Serial.print(temp);
	Serial.println("*C ");
	Serial.println(Time.timeStr());
	
	// Wait 30 seconds between measurements.
	delay(30000);
}


