#ifndef SbW_PROTOCOL_SbW_PROTOCOL_H_
#define SbW_PROTOCOL_SbW_PROTOCOL_H_

#include <stdint.h>

typedef enum SbW_Err_Codes {
	SbW_ERROR_NoERROR,
	SbW_ERROR_CRC,
} SbW_Err_Codes_t;

typedef struct SbW_Protocol {
	uint8_t Stream_ON :1;
	uint8_t Frame_Len;
	uint16_t SamplingFreq;

	uint8_t R_W:1;
	uint8_t CMD;

	struct Hw_Interface {
		void (*Send_Reply)(uint8_t *data, uint16_t len);
		void (*User_Callback)(SbW_Err_Codes_t Error_Code);
	} HW_Interface_t;
} SbW_Protocol_t;

void SbW_Request_Received_CB(SbW_Protocol_t *S, uint8_t *data, uint16_t len); //to send the received data from the USB to the protocol
//This function will be called back in CDC_Receive_FS to pass the data to the Software driver to do its purpose for this function
void SbW_Reply_Transmit(SbW_Protocol_t *S, uint8_t *data, uint16_t len); //to reply to the USB from the protocol
#endif /* SbW_PROTOCOL_SbW_PROTOCOL_H_ */
