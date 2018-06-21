#ifndef __GPIOPadsControl_h__
#define __GPIOPadsControl_h__

#include <stdint.h>
#include <stdbool.h>

#if RASPBERRYPI_MODEL == 1
// for RaspberryPi1 seriese
#define PADS_BASE   (0x20000000+0x00100000)
#else
// for RaspberryPi2 or 3 seriese
#define PADS_BASE   (0x3F000000+0x00100000)
#endif

typedef enum _GPIODriveLevel {
    GPIODriveLevel_2mA = 0,
    GPIODriveLevel_4mA = 1,
    GPIODriveLevel_6mA = 2,
    GPIODriveLevel_8mA = 3,
    GPIODriveLevel_10mA = 4,
    GPIODriveLevel_12mA = 5,
    GPIODriveLevel_14mA = 6,
    GPIODriveLevel_16mA = 7
} GPIODriveLevel;

int SetGPIODriveLevel( GPIODriveLevel drive );
int SetGPIOHysteresis( bool flag );

#endif
