


/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/c15fb26a-1c76-4ce4-8f18-d52812631621 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  String message;
  CloudIlluminance lightValue;
  bool light;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include <hp_BH1750.h>
hp_BH1750 sensor;
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  // set the address and initialize the sensor
  sensor.begin(BH1750_TO_GROUND);
  
  // start the first measurement
  sensor.start();
  
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  onLightChange();
}


/*
  Since Light is READ_WRITE variable, onLightChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLightChange()  {
  // Add your code here to act upon Light 
  if(sensor.hasValue())
  {
    // input light intensity
    lightValue = sensor.getLux();
    
    // if light intensity is greater than 400, blonk led
    if(lightValue > 400)
    {
      // terraium is exposed to sunlight
      light = true;

      Serial.println("The sunlight is avalaible.Light Intensity: ");
      Serial.println(lightValue);
    }
    
    // else turn led off
    else
    {
      // terrarium is not exposed to sunlight
      light = false;
      Serial.println("The sunlight is not available.Light Intensity: ");
      Serial.println(lightValue);      
    }  
    delay(5000);
    // start next measurement
    sensor.start();
  }
  
}
/*
  Since Sunlight is READ_WRITE variable, onSunlightChange() is
  executed every time a new value is received from IoT Cloud.
*/

/*
  Since Message is READ_WRITE variable, onMessageChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMessageChange()  {
  // Add your code here to act upon Message change
}

/*
  Since LightSensor is READ_WRITE variable, onLightSensorChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLightSensorChange()  {
  // Add your code here to act upon LightSensor change
}

/*
  Since LightValue is READ_WRITE variable, onLightValueChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLightValueChange()  {
  // Add your code here to act upon LightValue change
}
