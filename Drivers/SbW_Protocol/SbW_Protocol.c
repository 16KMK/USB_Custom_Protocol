#include "SbW_protocol.h"

/**
 * @fn uint16_t CRC16(uint8_t*, uint16_t)
 * @brief
 * Computes the CRC value of a certain data frame and returns it
 * @param data ptr to the data buffer
 * @param len number of bytes for the CRC to be calculated for
 * @return CRC byte value
 */
static uint16_t CRC16(uint8_t *data, uint16_t len) {
	uint16_t CRC = 0;
	for (uint16_t x = 0; x < len; x++) {
		CRC += data[x];
	}
	return CRC;
}

void SbW_Request_Received_CB(SbW_Protocol_t *S, uint8_t *data, uint16_t len) {
	uint16_t CRC_Result = CRC16(data, len - 2);

	//check the data integrity
	if (CRC_Result
			!= (((uint16_t) data[len - 2] << 8) | (uint16_t) data[len - 1])) {
		//CRC Error
		S->HW_Interface_t.User_Callback(SbW_ERROR_CRC);
		//return CRC_Result; //ignoring this frame
	}
	//NoError
	S->R_W = data[1] >> 7;
	S->CMD = data[1] & 0b01111111;

	switch (S->CMD) {
	case 0x01: //1st command Get/Set Sampling Frequency
		S->HW_Interface_t.User_Callback(SbW_ERROR_NoERROR);
		if (S->R_W) //Read
		{
			len = 7;
			data[2] = 2; //data length =2
			data[3] = (uint8_t) (S->SamplingFreq >> 8);
			data[4] = (uint8_t) S->SamplingFreq;
		} else //Write
		{
			len = 5;
			S->SamplingFreq = ((uint16_t) data[3] << 8) | (uint16_t) data[4];
			data[2] = 0;
		}
		//send back the reply to the PC
		//S->HW_Interface_t.Send_Reply(data, len);
		break;
	case 0x02:		//2nd command Get/Set Frame Length
		S->HW_Interface_t.User_Callback(SbW_ERROR_NoERROR);
		if (S->R_W) //Read
		{
			len = 6;
			data[2] = 1; //data length =1
			data[3] = S->Frame_Len; //Get Frame Length
			//data[4]|data[5] for CRC_Result
		} else //Write
		{
			len = 5;
			S->Frame_Len = data[3];
			data[2] = 0;
			//data[3]|data[4] for CRC_Result
		}
		break;
	default:
		return;
	}

	CRC_Result = CRC16(data, len - 2);
	data[len - 2] = (uint8_t) (CRC_Result >> 8);
	data[len - 1] = (uint8_t) (CRC_Result);
	S->HW_Interface_t.Send_Reply(data, len);
}
void SbW_Reply_Transmit(SbW_Protocol_t *S, uint8_t *data, uint16_t len) {

}
