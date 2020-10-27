#include "ClosedCube_HDC1080.h"
#include<Wire.h>

#define gas_sensor 34
#define CO_sensor 35
#define gas_sensor_digitalIN 32
#define CO_sensor_digitalIN 33


ClosedCube_HDC1080 hdc1080;

void sensor_init(void){

            hdc1080.begin(0x40);
            pinMode(gas_sensor_digitalIN,INPUT);
            pinMode(CO_sensor_digitalIN,INPUT);
}

float read_temperature(void){

            float temp = hdc1080.readTemperature();
            return temp;
}
float read_humidity(void){

            float humid = hdc1080.readHumidity();
            return humid;

}
