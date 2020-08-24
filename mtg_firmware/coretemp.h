/***********************************************************************
 *
 *  Arduino Core Temperature
 *
 *  DESCRIPTION
 *      Provides convenience functions for reading the AVR's core temperature
 *      Note that the absolute temperatures returned by these functions
 *      are not necessarily accurate. These values should be used to gauge
 *      relative temperature of the core over time, not an absolute measurement
 *
 *  REFERENCES
 *      Based on the example posted at https://forum.arduino.cc/index.php?topic=8140.0
 * 
 ***********************************************************************/

#if !defined(INC_CORETEMP_H)
#define INC_CORETEMP_H

/*=====================================================================*
    Required Header Files
 *=====================================================================*/
#include <arduino.h>


/*=====================================================================*
    Public Functions
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      coretemp_init
 *
 *  DESCRIPTION
 *      Initializes the ADC to perform core temperature readings
 *
 *  RETURNS
 *      None
 *---------------------------------------------------------------------*/
void coretemp_init(void);

/*---------------------------------------------------------------------*
 *  NAME
 *      coretemp_average
 *
 *  DESCRIPTION
 *      Calculates the avarge core temperature across 'samples' number
 *      of readings. The interal temperatre sensor is fairly noisy,
 *      so a good deal of averaging is needed.
 *
 *  RETURNS
 *      Average core temperature
 *---------------------------------------------------------------------*/
float coretemp_average(unsigned int samples = 1000);

#endif /* !defined(INC_CORETEMP_H) */
