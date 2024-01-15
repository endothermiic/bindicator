# bindicator

How to use/implement: 
1. Go to [this](https://www.toronto.ca/services-payments/recycling-organics-garbage/houses/collection-schedule/) website to determine which district you live in. 
2. Select which district you live in on the LCD.
3. Congrats! Your bindicator is now configured. The LCD should display which day of the week the bins will be collect (T, W, R or F) along with the current date. Click the button to see which bin (garbage, recycling or compost) should be put out (blue = recycling, yellow = garbage, green = compost). 

Files: 
* pickup-data-orig.json: original data file
* data-parser.py: python script that parses the input data and creates a new cpp-style file that declares the relevant info condensed as arrays (memory of microcontroller is very constrained) - each schedule has its own array is 52 x 1, four-digit integer illustrating whether the bin (organics, garbage, recycling or yard waste) is being picked up (1) or not (0). E.g. one entry might by 1001 indicating that organics and yard waste is being picked up that day. 
* LiquidCrystal_I2C: Public library for the 1602I2C Arduino LCD configuration; may need to install Wire.h and Print.h libraries as well is not already installed (this can be done in the Arduino IDE)

Limitations: this only works for residential homes under Toronto's daytime collection schedule (this limitation is in place because this is the only data made public by the city of Toronto). Datasets taken from Toronto's [Open Data Catalogue ](https://open.toronto.ca/dataset/solid-waste-pickup-schedule/)
