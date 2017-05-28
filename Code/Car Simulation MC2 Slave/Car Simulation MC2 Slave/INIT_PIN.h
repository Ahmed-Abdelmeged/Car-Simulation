/*
 * INIT_PIN.h
 *
 * Created: 29/06/37 02:21:27 م
 *  Author: Ahmed
 */ 


#ifndef INIT_PIN_H_
#define INIT_PIN_H_

#define SET_BIT(REG,BIT_NUM) (REG = REG | (1 << BIT_NUM))
#define CLEAR_BIT(REG,BIT_NUM) (REG = REG & (~(1 << BIT_NUM)))
#define TOGGLE_BIT(REG,BIT_NUM) (REG = REG ^ (1 << BIT_NUM))
#define ROR(REG,BIT_NUM) (REG = (REG >> BIT_NUM) | (REG << (8-BIT_NUM))
#define ROL(REG,BIT_NUM) (REG = (REG << BIT_NUM) | (REG >> (8-BIT_NUM)))
#define BIT_IS_SET(REG,BIT_NUM) (REG & (1<<BIT_NUM))
#define BIT_IS_CLEAR(REG,BIT_NUM) (!(REG & (1<<BIT_NUM)))






#endif /* INIT_PIN_H_ */