#ifndef HARDWARE_INTERFACE_HARDWARE_INTERFACE_H_
#define HARDWARE_INTERFACE_HARDWARE_INTERFACE_H_

#include <stdint.h>
#include "../../USB_DEVICE/App/usbd_cdc_if.h"
#include "../../Drivers/SbW_Protocol/SbW_protocol.h"

void SBW_Protocol_Reply(uint8_t *data, uint16_t len);
void App_User_Callback(SBW_Err_Codes_t Error_Code);

#endif /* HARDWARE_INTERFACE_HARDWARE_INTERFACE_H_ */
