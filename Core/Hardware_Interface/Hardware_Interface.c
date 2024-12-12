#include "Hardware_Interface.h"

void SBW_Protocol_Reply(uint8_t *data, uint16_t len) {
	CDC_Transmit_FS(data, len);
}
;

void App_User_Callback(SBW_Err_Codes_t Error_Code) {
}
;
