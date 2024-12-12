#ifndef SBW_PROTOCOL_SBW_PROTOCOL_H_
#define SBW_PROTOCOL_SBW_PROTOCOL_H_

#include <stdint.h>

typedef enum SBW_Err_Codes {
	SBW_ERROR_NoERROR,
	SBW_ERROR_CRC,

} SBW_Err_Codes_t;

typedef struct SBW_Protocol {
	uint8_t Stream_ON :1;
	uint8_t Frame_Len;

	struct Hw_Interface {
		void (*Send_Reply)(uint8_t *data, uint16_t len);
		void (*User_Callback)(SBW_Err_Codes_t Error_Code);
	} HW_Interface_t;
} SBW_Protocol_t;

void SBW_Request_Received_CB(SBW_Protocol_t *S, uint8_t *data, uint16_t len);
void SBW_Reply_Transmit(SBW_Protocol_t *S, uint8_t *data, uint16_t len);
#endif /* SBW_PROTOCOL_SBW_PROTOCOL_H_ */
