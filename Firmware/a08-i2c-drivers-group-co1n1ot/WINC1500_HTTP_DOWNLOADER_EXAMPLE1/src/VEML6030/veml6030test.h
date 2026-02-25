/*
 * veml6630test.h
 *
 * Created: 11/7/2023 7:52:11 PM
 *  Author: 07yhx
 */ 


#ifndef VEML6030TEST_H_
#define VEML6030TEST_H_

#include "main.h"
#include <stdbool.h>

#include <stdint.h>

#ifdef __cplusplus
#define EXPORT extern "C"
#else
#define EXPORT
#endif

// VEML6030 I2C address
#define VEML6030_I2C_ADDR_READ 0x91
#define VEML6030_I2C_ADDR_WRITE 0x90
#define VEML6030_ALS   0x04

typedef int32_t (*stmdev_write_ptr)(void *, uint8_t, const uint8_t *, uint16_t);
typedef int32_t (*stmdev_read_ptr)(void *, uint8_t, uint8_t *, uint16_t);

typedef struct
{
	/** Component mandatory fields **/
	stmdev_write_ptr  write_reg;
	stmdev_read_ptr   read_reg;
	/** Customizable optional pointer **/
	void *handle;
} stmdev_alstx_t;

stmdev_ctx_t * GetAlsStruct(void);

#endif /* VEML6030TEST_H_ */