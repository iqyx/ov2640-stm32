#!/bin/bash
#enocd -s /usr/share/openocd/scripts/ -f interface/c232hm.cfg -f target/stm32f1x.cfg -f openocd_flash.cfg
openocd  -s /usr/share/openocd/scripts/ -f openocd_flash.cfg
