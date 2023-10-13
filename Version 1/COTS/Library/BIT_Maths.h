/*
 * BIT_Maths.h
 *
 *  Created on: Sep 14, 2023
 *      Author: pc castle
 */

#ifndef INC_LIB_BIT_MATHS_H_
#define INC_LIB_BIT_MATHS_H_

#define SET_BIT(REG,BIT_NUM) (REG|=1<<BIT_NUM)
#define CLR_BIT(REG,BIT_NUM) REG&=~(1<<BIT_NUM)
#define TOGGLE_BIT(REG,BIT_NUM) REG^=(1<<BIT_NUM)
#define GET_BIT(REG,BIT_NUM) (1&(REG>>BIT_NUM))
#endif /* INC_LIB_BIT_MATHS_H_ */
