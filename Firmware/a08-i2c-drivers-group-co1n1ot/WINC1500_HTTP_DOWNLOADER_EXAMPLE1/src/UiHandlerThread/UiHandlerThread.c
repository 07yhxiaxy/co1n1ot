 /**************************************************************************//**
* @file      UiHandlerThread.c
* @brief     File that contains the task code and supporting code for the UI Thread for ESE516 Spring (Online) Edition
* @author    You! :)
* @date      2020-04-09 

******************************************************************************/


/******************************************************************************
* Includes
******************************************************************************/
#include <errno.h>
#include "asf.h"
#include "UiHandlerThread/UiHandlerThread.h"
#include "SeesawDriver/Seesaw.h"
#include "SerialConsole.h"
#include "main.h"

/******************************************************************************
* Defines
******************************************************************************/

/******************************************************************************
* Variables
******************************************************************************/
uiStateMachine_state uiState;
/******************************************************************************
* Forward Declarations
******************************************************************************/

/******************************************************************************
* Callback Functions
******************************************************************************/


/******************************************************************************
* Task Function
******************************************************************************/

/**************************************************************************//**
* @fn		void vUiHandlerTask( void *pvParameters )
* @brief	STUDENT TO FILL THIS
* @details 	student to fill this
                				
* @param[in]	Parameters passed when task is initialized. In this case we can ignore them!
* @return		Should not return! This is a task defining function.
* @note         
*****************************************************************************/
void vUiHandlerTask( void *pvParameters )
{
//Do initialization code here
		uint8_t buffer[100] = {0};
		uint8_t count;
		uint8_t Keynum;
SerialConsoleWriteString("UI Task Started!");
uiState = UI_STATE_HANDLE_BUTTONS;

//Here we start the loop for the UI State Machine
while(1)
{
	switch(uiState)
	{
		case(UI_STATE_HANDLE_BUTTONS):
		{
		
			
		//Do the handle buttons code here!
		/* NOTE:
		Do not call SeesawReadKeypad(uint8_t *buffer, uint8_t count) with the argument count being zero. 
		There seems to be a bug with ASF when this is called (i2c_master_read_packet_job).
		The following guard can be used:

		if(count != 0)		{
			SeesawReadKeypad(buffer, count);
		}
		
		*/

		count = SeesawGetKeypadCount();
		if(count != 0){
			// Read keypad events
			SeesawReadKeypad(buffer, count);
			// Set all keypads to dark
			for(int i = 0; i < 16; i++){
				SeesawSetLed(i, 0, 0, 0);
			}
			// Refresh the keypad to all dark
			SeesawOrderLedUpdate();
			// If keypad is pushed, turn it on and update
			if ((buffer[0]&0b11) == 0b11){
				for (int i = 0; i < count; i++){
					Keynum = NEO_TRELLIS_SEESAW_KEY(buffer[0]>>2);
					SeesawSetLed (Keynum, 100, 100, 100);
					SeesawOrderLedUpdate();
				}
			}
		}
		
		break;
		}

		case(UI_STATE_IGNORE_PRESSES):
		{
		//Ignore me for now
			break;
		}

		case(UI_STATE_SHOW_MOVES):
		{
		//Ignore me as well
			break;
		}

		default: //In case of unforseen error, it is always good to sent state machine to an initial state.
			uiState = UI_STATE_HANDLE_BUTTONS;
		break;
	}

	//After execution, you can put a thread to sleep for some time.
	vTaskDelay(50);
}



}




/******************************************************************************
* Functions
******************************************************************************/