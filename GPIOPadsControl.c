#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "GPIOPadsControl.h"

#define PADS_LEN    0x38

typedef union {
    uint32_t value;
    struct _bits {
        unsigned int drive:3;
        unsigned int hyst:1;
        unsigned int slew:1;
        unsigned int reserved:19;
        unsigned int passwrd:8;
    } bits;
} PADSREG;

#define PADS0    padsReg[0x2c/4]

static volatile uint32_t *padsReg = NULL;

static int InitializePADS() {
    if ( padsReg == NULL ) {
        int fdMem = open( "/dev/mem", O_RDWR | O_SYNC );
        if ( fdMem < 0 ) {
            return 1;
        }
        padsReg = (uint32_t *)mmap(
            0,
            PADS_LEN,
            PROT_READ|PROT_WRITE|PROT_EXEC,
            MAP_SHARED|MAP_LOCKED,
            fdMem,
            PADS_BASE
        );
        close( fdMem );
    }
    return 0;
}

int SetGPIODriveLevel( GPIODriveLevel drive ) {
    unsigned int v = (unsigned int)drive;
    if ( v > 7 ) {
        return 1;
    }
    if ( InitializePADS() != 0 ) {
        return 1;
    }

    PADSREG reg;
    reg.value = PADS0;
    reg.bits.passwrd = 0x5a;
    reg.bits.reserved = 0;
    reg.bits.drive = v;
    PADS0 = reg.value;

    return 0;
}

int SetGPIOHysteresis( bool flag ) {
    if ( InitializePADS() != 0 ) {
        return 1;
    }

    PADSREG reg;
    reg.value = PADS0;
    reg.bits.passwrd = 0x5a;
    reg.bits.reserved = 0;
    if ( flag ) {
        reg.bits.hyst = 1;
    } else {
        reg.bits.hyst = 0;
    }
    PADS0 = reg.value;

    return 0;
}
