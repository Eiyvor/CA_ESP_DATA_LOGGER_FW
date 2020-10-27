#include "PMS.h"
#include<SoftwareSerial.h>
#include"gsm.h"

// SoftwareSerial swSerial;
// HardwareSerial Serial2(2);
PMS pms(Serial2);
PMS::DATA data;

String dust_pm_1_0;
String dust_pm_2_5;
String dust_pm_10_;

void pms90003m_init(void){

// swSerial.begin(9600, SWSERIAL_8N1, 4, 15, false, 256);
Serial2.begin(9600,SERIAL_8N1,4,15);
   

}

uint16_t dust_sensor_show_data(void){
    // mqtt_send_to_broker(dust_pm_1_0, dust_pm_2_5, dust_pm_10_);
                if(pms.read(data)){
                Serial.println("Dust Concentration");
                Serial.println("PM1.0 :"+String(data.PM_AE_UG_1_0) + "(ug/m3)");
                Serial.println("PM2.5 :"+String(data.PM_AE_UG_2_5) + "(ug/m3)");
                Serial.println("PM10 :"+String(data.PM_AE_UG_10_0) + "(ug/m3)");
                dust_pm_1_0 = String(data.PM_AE_UG_1_0)+"(ug/m3)";
                dust_pm_2_5 = String(data.PM_AE_UG_2_5)+"(ug/m3)";
                dust_pm_10_ = String(data.PM_AE_UG_10_0)+"(ug/m3)";
                mqtt_send_to_broker(dust_pm_1_0, dust_pm_2_5, dust_pm_10_);
                
}
 
return data.PM_AE_UG_10_0;

}
