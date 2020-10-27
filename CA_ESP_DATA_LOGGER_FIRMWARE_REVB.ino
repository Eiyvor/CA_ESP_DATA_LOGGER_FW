#include "Credentials.h"
#include "AWS_WiFi.h"
#include "gsm.h"
#include "RelayControls.h"
#include "Board_init.h"

credentials cred;

String ap_mode_ssid_ = "Cybene";
char ap_mode_ssid[35];
char* ap_mode_password = "Cybene@123";
String macID="";
String name = "CONF/SN-";
bool connected_to_internet = 0;

void setup() {

Serial.begin(115200);
board_init();
gsm_modem_init();
gsm_setup_gprs();
macID = WiFi.macAddress();
ap_mode_ssid_+= macID;
ap_mode_ssid_.toCharArray(ap_mode_ssid,35);
name+=macID;  
Serial.println(name);
cred.EEPROM_Config();

if(cred.credentials_get()){

  connected_to_internet = 1;
}
else {
  cred.setupAP(ap_mode_ssid,ap_mode_password);
  connected_to_internet = 0;
}

if(connected_to_internet){

connectToAWS();
AWS_WiFi_SubTopic(name);
AWS_WiFi_CallBack();
relay_mdns_init();
relay_server_handle();
}
//xTaskCreate(
//                    taskOtaUpdate,          /* Task function. */
//                    "TaskOtaUpdate",        /* String with name of task. */
//                    10000,            /* Stack size in bytes. */
//                    NULL,             /* Parameter passed as input of the task */
//                    1,                /* Priority of the task. */
//                    NULL);            /* Task handle. */
// 
//xTaskCreate(
//                    main_task,          /* Task function. */
//                    "main_task",        /* String with name of task. */
//                    10000,            /* Stack size in bytes. */
//                    NULL,             /* Parameter passed as input of the task */
//                    1,                /* Priority of the task. */
//                    NULL);            /* Task handle. */
// 
}
//void main_task(void *parameter){
//  
//  for(;;){
//  if(connected_to_internet){
//
//    AWS_WiFi_loop();
//    
//  }
//  if(check_gsm_mqtt_connected()){
//
//    gsm_mqtt_client();
//    
//  }
//  gsm_send_json();
//  relay_server_loop();
//  gsm_mqtt_loop();
//  }
//}
//void taskOtaUpdate(void *parameter){
//  for(;;){
//  
//    
//  }
//}
void loop() {
   if(connected_to_internet){

    AWS_WiFi_loop();
    
  }
  if(!check_gsm_mqtt_connected() && int(EEPROM.read(250)==1)){

    gsm_mqtt_client();
    
  }
  cred.server_loops();
  gsm_send_data_to_broker();
  relay_server_loop();
  gsm_mqtt_loop();
  }
