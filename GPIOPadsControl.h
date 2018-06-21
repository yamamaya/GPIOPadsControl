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

typedef enum _GPIODriveStrength {
    GPIODriveStrength_2mA = 0,
    GPIODriveStrength_4mA = 1,
    GPIODriveStrength_6mA = 2,
    GPIODriveStrength_8mA = 3,
    GPIODriveStrength_10mA = 4,
    GPIODriveStrength_12mA = 5,
    GPIODriveStrength_14mA = 6,
    GPIODriveStrength_16mA = 7
} GPIODriveStrength;

int SetGPIODriveStrength( GPIODriveStrength drive );
int SetGPIOHysteresis( bool flag );

#endif
