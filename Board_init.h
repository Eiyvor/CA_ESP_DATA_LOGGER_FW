#ifndef Board_init_h
#define Board_init_h

#include"modbus.h"
#include"battery.h"
#include"pms90003m.h"
#include"MQTT.h"
#include"Sensor.h"
void board_init(void){
  
  battery_init();
  battery_confiq(1);
  sensor_init();
  modbus_init();
  pms90003m_init();
 
  

}



#endif
