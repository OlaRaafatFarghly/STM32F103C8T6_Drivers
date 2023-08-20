/*
 * MRCC_interface.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Ola Raafat
 */

#ifndef MCAL_MRCC_MRCC_INTERFACE_H_
#define MCAL_MRCC_MRCC_INTERFACE_H_

void MRCC_vInit(void);

void MRCC_vEnableClock(u8 peripheral);

void MRCC_vDisableClock(u8 peripheral);


#endif /* MCAL_MRCC_MRCC_INTERFACE_H_ */
