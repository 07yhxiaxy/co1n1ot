/*
 * veml6630test.c
 *
 * Created: 11/7/2023 6:37:58 PM
 *  Author: 07yhx
 */ 
#include "veml6030test.h"
#include "i2cDriver/I2cDriver.h"
#include "SerialConsole.h"
#include "math.h"
#include "CliThread/CliThread.h"



static int32_t platform_write(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len);

static int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len);



stmdev_alstx_t als_ctx = {.write_reg = platform_write, .read_reg = platform_read};

uint8_t msgOutImu[64]; ///<USE ME AS A BUFFER FOR platform_write and platform_read
I2C_Data imuData; ///<Use me as a structure to communicate with the IMU on platform_write and platform_read

/**************************************************************************//**
 * @fn			static int32_t platform_write(void *handle, uint8_t reg, uint8_t *bufp,uint16_t len)
 * @brief       Function to write data to a register
 * @details     Function to write data (bufp) to a register (reg)
				
 * @param[in]   handle IGNORE
 * @param[in]   reg Register to write to. In an I2C transaction, this gets sent first
 * @param[in]   bufp Pointer to the data to be sent
 * @param[in]   len Length of the data sent
 * @return      Returns what the function "I2cWriteDataWait" returns
 * @note        STUDENTS TO FILL  
*****************************************************************************/
static int32_t platform_write(void *handle, uint8_t reg, uint8_t *bufp,uint16_t len)
{
	//YOUR JOB: Fill out the structure "imuData" to send to the device
	//TIP: Use the array "msgOutImu" to copy the data to be sent. Remember that the position [0] of the array you send must be the register, and
	//starting from position [1] you can copy the data to be sent. Remember to adjust the length accordingly
	// Assuming the existence of a struct I2C_Data and a buffer msgOutImu
	// Check if the total length exceeds buffer size
	//if (len + 1 > sizeof(msgOutImu)) {
	//    return ERR_INVALID_ARG;
	//}

	// First byte is the register address
	msgOutImu[0] = reg;
	for(int i =0; i<len; i++){
		msgOutImu[i+1] = bufp[i];
	}
	// Copy the data to the buffer starting from position 1
	memcpy(&msgOutImu[1], bufp, len);

	// Set up the I2C data structure for transmission
	imuData.address = VEML6030_I2C_ADDR_WRITE ;
	imuData.msgOut = &msgOutImu;
	imuData.lenOut = len + 1; // Length includes the register address byte

	// Call the I2C write function
	return I2cWriteDataWait(&imuData, 100 );

}

/**************************************************************************//**
 * @fn			static  int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len)
 * @brief       Function to read data from a register
 * @details     Function to read data (bufp) from a register (reg)
				
 * @param[in]   handle IGNORE
 * @param[in]   reg Register to read from. In an I2C transaction, this gets sent first
 * @param[out]   bufp Pointer to the data to write to (write what was read)
 * @param[in]   len Length of the data to be read
 * @return      Returns what the function "I2cReadDataWait" returns
 * @note        STUDENTS TO FILL  
*****************************************************************************/
static  int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len)
{
	//YOUR JOB: Fill out the structure "imuData" to send to the device
	//TIP: Check the structure "imuData" and notice that it has a msgOut and msgIn parameter. How do we fill this to our advantage?
    // Check if the total length exceeds buffer size
    //if (len + 1 > sizeof(msgOutImu)) {
	//    return ERR_INVALID_ARG; 
    //}

    // First byte is the register address
    msgOutImu[0] = reg;

    // Set up the I2C data structure for read operation
    imuData.address = VEML6030_I2C_ADDR_READ ;
    imuData.msgOut = &msgOutImu; // Register address to read from
    imuData.lenOut = 1; // Only sending the register address
    imuData.msgIn = bufp; // Buffer to store the read data
    imuData.lenIn = len; // Length of data to read

    // Call the I2C read function
    return I2cReadDataWait(&imuData,5,100);

}

stmdev_alstx_t * GetAlsStruct(void){
	return &als_ctx;
}

/**
  * @brief  Read generic device register
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  reg   register to read
  * @param  data  pointer to buffer that store the data read(ptr)
  * @param  len   number of consecutive register to read
  * @retval          interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t veml6030_read_reg(stmdev_alstx_t *ctx, uint8_t reg,
                         uint8_t *data,
                         uint16_t len)
{
  int32_t ret;

  ret = ctx->read_reg(ctx->handle, reg, data, len);

  return ret;
}

/**
  * @brief  Linear acceleration output register.
  *         The value is expressed as a 16-bit word in two’s complement.[get]
  *
  * @param  ctx      read / write interface definitions
  * @param  buff     buffer that stores data read
  * @retval             interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t veml6030_als_raw_get(stmdev_alstx_t *ctx, int16_t *val)
{
  uint8_t buff[10];
  int32_t ret;

  ret = veml6030_read_reg(ctx, VEML6030_ALS, buff, 10);
  val[0] = (int16_t)buff[1];
  val[0] = (val[0] * 256) + (int16_t)buff[0];
  val[1] = (int16_t)buff[3];
  val[1] = (val[1] * 256) + (int16_t)buff[2];
  val[2] = (int16_t)buff[5];
  val[2] = (val[2] * 256) + (int16_t)buff[4];

  return ret;
}