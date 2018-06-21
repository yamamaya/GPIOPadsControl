GPIO PADS control library for RaspberryPi2/3

## Function reference
### SetGPIODriveLevel
```
int SetGPIODriveLevel( GPIODriveLevel drive )
```
#### Parameters:  
**drive**: 2mA-16mA, one of `GPIODriveLevel` enumerated type.

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
