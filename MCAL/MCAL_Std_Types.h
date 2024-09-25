/*
 * MCAL_Std_Types.h
 *
 *  Created on: Sep 20, 2024
 *      Author: Mohamed Elahmady
 */

/* Section 0 : File Guard */

#ifndef MCAL_MCAL_STD_TYPES_H_
#define MCAL_MCAL_STD_TYPES_H_

/* Section 1 : Includes */

#include "MCAL_Std_Libraries.h"
#include "Compiler.h"

/* Section 2 : Macros Declarations */

#define LOW_V          0x00
#define HIGH_V         0x01

#define OFF_ST         0x00
#define ON_ST          0x01

#define IDLE           0x00
#define ACTIVE         0x01

#define CFG_DISABLE    0x00
#define CFG_ENABLE     0x01

#define CPU_T8 8
#define CPU_T16 16
#define CPU_T32 32
#define CPU_T64 64

#define CPU_ARCH (CPU_T8)

/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */

#if (CPU_ARCH == CPU_T8)
//typedef bool boolean; // bit = 1 bit

typedef unsigned char uint8;
typedef unsigned short uint16; // short == int = 16 bit
typedef unsigned long uint32; // long == long long = 32 bit

typedef signed char sint8;
typedef signed short sint16; // short == int = 16 bit
typedef signed long sint32; // long == long long = 32 bit

typedef float float32; // float == double == long double = 32

#define HWREG8(_x)         (*((volatile uint8 *)(_x)))

#elif (CPU_ARCH == CPU_T16)
typedef unsigned char boolean;

typedef unsigned char uint8;
typedef unsigned short uint16; // short == int = 16 bit
typedef unsigned long uint32;
typedef unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16; // short == int = 16 bit
typedef signed long sint32;
typedef signed long long sint64;

typedef float float32;
typedef double float64;

#define HWREG16(_x)         (*((volatile uint16 *)(_x)))

#elif (CPU_ARCH == CPU_T32)
typedef unsigned char boolean;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32; // long == int = 32 bit
typedef unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32; // long == int = 32 bit
typedef signed long long sint64;

typedef float float32;
typedef double float64;

#define HWREG32(_x)         (*((volatile uint32 *)(_x)))

#elif (CPU_ARCH == CPU_T64)
typedef unsigned char boolean;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32; // int == long = 32 bit
typedef unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32; // int == long = 32 bit
typedef signed long long sint64;

typedef float float32;
typedef double float64;
typedef long double float128;

#define HWREG64(_x)         (*((volatile uint64 *)(_x)))

#endif

typedef enum{
    E_NOT_OK = 0,
    E_OK     = 1
}Std_ReturnType;

/* Section 5 : Functions Declarations */





#endif /* MCAL_MCAL_STD_TYPES_H_ */
