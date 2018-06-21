GPIO PADS control library for RaspberryPi2/3

## Function reference
### SetGPIODriveStrength
```
int SetGPIODriveStrength( GPIODriveStrength drive )
```
#### Parameters:  
**drive**: 2mA-16mA, one of `GPIODriveStrength` enumerated type.

#### Return value:
**0**: Success  
**1**: Failure

### SetGPIOHysteresis
```
int SetGPIOHysteresis( bool flag )
```

#### Parameters:  
**flag**: true=enable hysteresis / false=disable

#### Return value:
**0**: Success  
**1**: Failure
