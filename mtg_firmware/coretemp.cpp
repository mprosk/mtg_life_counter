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


/*=====================================================================*
    Local Header Files
 *=====================================================================*/
#include "coretemp.h"


/*=====================================================================*
    Private Function Prototypes
 *=====================================================================*/
static int temp_read(void);


/*=====================================================================*
    Public Function Implementations
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
void coretemp_init(void)
{
    // Turn on internal reference, right-shift ADC buffer
    // ADC channel = internal temp sensor
    ADMUX = 0xC8;
}


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
float coretemp_average(unsigned int samples = 1000)
{
    temp_read();    // discard first sample (never hurts to be safe)
    float average;      // create a float to hold running average
    for (int i = 1; i <= samples; i++)
    {
        // Get the next sample and calculate running average
        average += ( (temp_read() - average) / (float)i );
    }
    return average; // return average temperature reading
}


/*=====================================================================*
    Private Function Implementations
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      coretemp_read
 *
 *  DESCRIPTION
 *      Takes a temperature reading from the internal ADC
 *
 *  RETURNS
 *      Temperature reading from the ADC
 *---------------------------------------------------------------------*/
static int temp_read()
{
    ADCSRA |= _BV(ADSC);                   // Start the conversion
    while (bit_is_set(ADCSRA, ADSC));      // ADSC is cleared when the conversion finishes
    return (ADCL | (ADCH << 8)) - 342;     // Combine bytes & correct for temp offset (approximate)
}
