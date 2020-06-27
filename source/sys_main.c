/** @file sys_main.c 
*   @brief Application main file
*   @date 11-Dec-2018
*   @version 04.07.01
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* 
* Copyright (C) 2009-2018 Texas Instruments Incorporated - www.ti.com 
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */
/* USER CODE END */

/* Include Files */
#include "mibspi.h"
#include "sys_common.h"

/* USER CODE BEGIN (1) */
/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */
/* USER CODE END */

int main(void)
{
    uint16 r = 0x0000;
    uint16 theta = 0x0001;
    uint16 dc = 0x0002;
    uint16 delay = 0x0003;
    uint16 verify = 0x0000;

    //uint16 checksum = r + theta + dc + delay;
    uint16 checksum = 0x0000;

    //uint16 txBuffer[] = { r, theta, dc, delay, checksum };
    uint16 txBuffer[6];
    uint16 rxBuffer[6];

    mibspiInit();

    while(1) {
        checksum++;
        txBuffer[0] = 0;
        txBuffer[1] = 0;
        txBuffer[2] = 0;
        int bad = 1;
        bad = 0;
        if (bad) {
            txBuffer[3] = 0x0069;
        }
        else {
            txBuffer[3] = checksum;
        }
        txBuffer[4] = checksum;
        txBuffer[5] = 0;

        //txBuffer[] = { checksum, 0, 0, 0, checksum };
        mibspiSetData(mibspiREG1, 0, txBuffer);
        mibspiTransfer(mibspiREG1, 0);
        while(!(mibspiIsTransferComplete(mibspiREG1, 0)));
        mibspiGetData(mibspiREG1, 0, rxBuffer);
    }
}


/* USER CODE BEGIN (4) */
/* USER CODE END */
