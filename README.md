# protestsign

An electronic protest sign. #resist

## About

Since I forsee the need for lots of protesting in the future, I decided to make a reusable electronic protest sign. All messages are stored as a list in a text file on a micro SD card, so there's no need to reprogram the microcontroller to update the messages. If you buy an OTG micro SD card reader, you can even edit your messages on the go from your phone! Change the position of the dipswitch to display a new message.

## Instructions

Solder according to the schematic. The LED matrix should come with connectors. Make an extension cord long enough to hold the control board in your pocket or hand while you are holding the sign up.

Upload ProtestSign to the microcontroller. Copy messages.txt to a micro SD card and insert into the micro SD card slot.

Create your sign! I cut a 14"x14" square out of foam board with a box cutter. The grid lines made it easier to cut. Measure and mark so your LED matrix will be centered. Then attach velcro squares to the foam board and LED matrix back to mount it. This way you can remove the LED matrix in case it rains.

You may also wish to attach a handle or post to the sign. Many protests disallow wooden or metal sticks, so be sure to use some sturdy cardboard.

## Parts List

* [M0 Adalogger](https://www.adafruit.com/product/2796)
* [Perma Proto](https://www.adafruit.com/product/1608)
* [JST cable with switch](https://www.adafruit.com/product/3064)
* [2500 mAh LiPo battery](https://www.adafruit.com/product/328)
* Micro SD card
* [8*32 WS2812b LED array](https://www.aliexpress.com/item/8-8-16-16-8-32-Pixel-256-Pixels-WS2812B-Digital-Flexible-LED-Programmed-Panel-Screen/32584178296.html)
* [Dipswitch](https://www.digikey.com/product-detail/en/cts-electrocomponents/206-8/CT2068-ND/20760)
* [8x 10k ohm resistors ](https://www.digikey.com/product-detail/en/stackpole-electronics-inc/CF14JT10K0/CF14JT10K0CT-ND/1830374)
* [4700 uF capacitor](https://www.digikey.com/product-detail/en/nichicon/UVR0J472MHD/493-1010-ND/588751)
* [470 ohm resistor](https://www.digikey.com/product-detail/en/stackpole-electronics-inc/CF14JT470R/CF14JT470RCT-ND/1830342) (for LED data line)
* Foamboard - available at craft stores. Try to get the kind with the grid on it.
* [Velcro squares](http://www.joann.com/velcro-brand-sticky-back-squares/prd3165.html#q=Sticky+Velcro&start=1)


## Schematic

![Schematic](https://github.com/brightcolorfulflickers/protestsign/blob/master/schematic/protestsign.png)

## Photos

![Sign](https://github.com/brightcolorfulflickers/protestsign/blob/master/photos/sign.jpg)
![Controls](https://github.com/brightcolorfulflickers/protestsign/blob/master/photos/controls.jpg)
![Protoboard](https://github.com/brightcolorfulflickers/protestsign/blob/master/photos/proto1.jpg)
![Microcontroller](https://github.com/brightcolorfulflickers/protestsign/blob/master/photos/proto2.jpg)