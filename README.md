A proof-of-concept messy implementation of OV2640 picture grabbing on a STM32 MCU without using the hardware DCMI interface
================================================================================

The following implementation is only a proof-of-concept that a OV2640
(or any other similar camera) can be easily connected to a MCU even without
the right hardware interface. Most F4 indeed does have the DCMI interface for
interfacing with such cameras, it was used only because the F4discovery
board was handy.

My spaghetti code is dedicated to the public domain and I really hope that
nobody will ever use it. Some foreign parts use different licensing.

Full description including the hardware connections is available at
[http://qyx.krtko.org/projects/ov2640_stm32/](http://qyx.krtko.org/projects/ov2640_stm32/)
