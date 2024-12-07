/*
 * Hardware_Interface.c
 *
 *  Created on: Dec 7, 2024
 *      Author: ramys
 */


#include "Hardware_Interface.h"


void SbW_Protocol_Reply(uint8_t *data, uint16_t len){
	CDC_Transmit_FS(data, len);
}
