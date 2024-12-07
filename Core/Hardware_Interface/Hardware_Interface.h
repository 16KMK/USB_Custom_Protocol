/*
 * Hardware_Interface.h
 *
 *  Created on: Dec 7, 2024
 *      Author: ramys
 */

#ifndef HARDWARE_INTERFACE_HARDWARE_INTERFACE_H_
#define HARDWARE_INTERFACE_HARDWARE_INTERFACE_H_

#include <stdint.h>
#include "../../USB_DEVICE/App/usbd_cdc_if.h"

void SbW_Protocol_Reply(uint8_t *data, uint16_t len);


#endif /* HARDWARE_INTERFACE_HARDWARE_INTERFACE_H_ */
