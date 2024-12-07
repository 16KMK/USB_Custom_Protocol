/*
 * SbW_Protocol.c
 *
 *  Created on: Dec 7, 2024
 *      Author: ramys
 */

#include "SbW_protocol.h"

/**
 * @fn uint8_t CRC8(uint8_t*, uint8_t)
 * @brief
 * Computes the CRC value of a certain data frame and returns it
 * @param data ptr to the data buffer
 * @param len number of bytes for the CRC to be calculated for
 * @return CRC byte value
 */
static uint8_t CRC8(uint8_t *data, uint8_t len) {
	uint8_t CRC = 0;
	for (uint16_t x = 0; x < len; x++) {
		CRC ^= data[x];
	}
	return CRC;
}

void SbW_Request_Recieved_CB(SbW_Protocol_t *S, uint8_t *data, uint16_t len) {
	uint8_t CRC_Result = CRC8(data, len - 1);

	//check the data integrity
	if (CRC_Result != data[len - 1]) {
		//CRC error
		S->HW_Interface_t.User_Callback(SbW_ERROR_CRC);
		return;
	}

	uint8_t CMD = dta[0];

	switch (CMD) {
	case 0x01:
		S->HW_Interface_t.User_Callback(SbW_ERROR_NoERROR);
		//update the stream control variable
		S->Stream_ON = data[2];
		//send bac the reply to the PC
		S->HW_Interface_t.Send_Reply(data, len);
		break;

	default:
		return;
	}

}
