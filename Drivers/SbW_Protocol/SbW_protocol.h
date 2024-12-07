/*
 * SbW_protocol.h
 *
 *  Created on: Dec 7, 2024
 *      Author: ramys
 */

#ifndef SBW_PROTOCOL_SBW_PROTOCOL_H_
#define SBW_PROTOCOL_SBW_PROTOCOL_H_

#include <stdint.h>

typedef enum SbW_Err_Codes{
	SbW_ERROR_NoERROR,
	SbW_ERROR_CRC,

}SbW_Err_Codes_t;

typedef struct SbW_Protocol{
	uint8_t Stream_ON:1;

	struct Hw_Interface{
		void (*Send_Reply)(uint8_t *data, uint16_t len);
		void (*User_Callback)(SbW_Err_Codes_t Error_Code);
	}HW_Interface_t;
}SbW_Protocol_t;

void SbW_Request_Recieved_CB(SbW_Protocol_t *S,uint8_t *data, uint16_t len);

#endif /* SBW_PROTOCOL_SBW_PROTOCOL_H_ */
