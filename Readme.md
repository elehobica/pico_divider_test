# Raspberry Pi Pico divider Test

## Overview
Test code to asynchronous access to SIO divider.
To check following functions which are both included in main and interrupt function.
* 64bit divide
* float divide

## Supported Board and Peripheral Devices
* Raspberry Pi Pico

## How to build
* See ["Getting started with Raspberry Pi Pico"](https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf)
* Build is confirmed only in Developer Command Prompt for VS 2019 and Visual Studio Code on Windows enviroment
* Put "pico-sdk", "pico-examples", "pico-extras" and "pico-playground" on the same level with this project folder.
```
> git clone -b master https://github.com/raspberrypi/pico-sdk.git
> cd pico-sdk
> git submodule update -i
> cd ..
> git clone -b master https://github.com/raspberrypi/pico-examples.git
> 
> git clone https://github.com/raspberrypi/pico-extras.git
> cd pico-extras
> git submodule update -i
> cd ..
> git clone https://github.com/raspberrypi/pico-playground.git
> 
> git clone -b main https://github.com/elehobica/pico_divider_test.git
```
* Lanuch "Developer Command Prompt for VS 2019"
```
> cd pico_divider_test
> mkdir build
> cd build
> cmake -G "NMake Makefiles" ..
> nmake
```
* Put "pico_divider_test.uf2" on RPI-RP2 drive

## Failure example
```
START
ERROR [calc_64bit][136744975] samplesPlayed = 33375364, millis_ref = 756811, millis = 329709
ERROR [calc_64bit][172198336] samplesPlayed = 42086964, millis_ref = 954353, millis = 935928
ERROR [calc_64bit][247011501] samplesPlayed = 60456996, millis_ref = 1370907, millis = 1340813
ERROR [calc_64bit][311120985] samplesPlayed = 76175736, millis_ref = 1727341, millis = 1715638
dummy = -1183355269
END
```