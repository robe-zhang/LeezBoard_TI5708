/*
 * Copyright (c) 2013, Texas Instruments Incorporated - http://www.ti.com/
 *   All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *      * Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *      * Redistributions in binary form must reproduce the above copyright
 *        notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 *      * Neither the name of Texas Instruments Incorporated nor the
 *        names of its contributors may be used to endorse or promote products
 *        derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */
/**
 *   @file  qmss_device.c
 *
 *   @brief   
 *      This file includes the appropriate device specific QMSS configuration
 *      struct, Qmss_GlobalConfigParams
 *
 */


#if defined (TI_C6678) || defined (TI_C6670) || defined (TI_C6657)
#include <ti/drv/qmss/qmss_drv.h>
#if defined (TI_C6678)
#include <ti/drv/qmss/device/c6678/src/qmss_device.c>
#elif defined (TI_C6657)
#include <ti/drv/qmss/device/c6657/src/qmss_device.c>
#elif defined (TI_C6670)
#include <ti/drv/qmss/device/c6670/src/qmss_device.c>
#endif
#elif defined (TI_C6636)
#include <ti/drv/qmss/qmss_drv.h>
#include <ti/drv/qmss/device/k2h/src/qmss_device.c>
#elif defined (TI_66AK2G)
#elif defined (TI_AM572)
#else
#error "Device not supported"
#endif


