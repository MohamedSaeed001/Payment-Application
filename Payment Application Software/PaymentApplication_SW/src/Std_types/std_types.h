 /******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: std_types.h
 *
 * Author: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Boolean Data Type */
typedef unsigned char boolean;

/* Boolean Values */
#define FALSE       (0u)
#define TRUE        (1u)

#define NULL_PTR    ((void*)0)
#define NULL_CH     ('\0')

typedef unsigned char           uint8_t;
typedef unsigned long           uint32_t;
typedef float                   float32_t;
/*typedef signed char             sint8_t;
typedef unsigned short          uint16_t;
typedef signed short            sint16_t;
typedef unsigned long           uint32_t;
typedef signed long             sint32_t;
typedef unsigned long long      uint64_t;
typedef signed long long        sint64_t;
typedef float                   float32_t;
typedef double                  float64_t;
*/
#endif /* STD_TYPE_H_ */
