## Purpose
The purpose of this project was to collect strain data from our suspension to justify and verfy the switch from steel suspension arms to carbon fiber suspenion arms. The team could've just bought generically sized carbon tubes that could be justified with math but that would be hard to defend to judge in our compeition and we would most likely be spending more money than needed to. Precise infomation is important to make sure the car can support its own weight, survive a crash with a cone, and keep the driver safe. There were multiple reasons this was done including weight and advances in team usage of composite materials. This was a collaboration between the frame engineer and I.

## Process
### Set up
Before data could be analyzed, a strain gauge set up had to be built to actually take data. Rather than using load cells, we used a single strain gauge and an amplfier module per arm to record the strain being felt across that arm. 6 in total were used for the front and 5 for the back, with one arduino being used (gauges were swapped during testing). The gauges were ran to a box that was shoved next to the seat.

![arudinoSetup](https://user-images.githubusercontent.com/112229422/214453553-5c55d050-05e6-4e04-b7dc-7ec955da7481.jpg)

![strainGaugeSetup](https://user-images.githubusercontent.com/112229422/214453567-61be00a8-940d-49e5-abd6-3127b85988cb.jpg)


### Arudino Code
The code for the arduino is attached in this repository and went through a few changes (which unfortunately ARENT in this repo). The forces being exerted onto the arms happen extremely quickly so to log this moment, the data need to be extremely granular. The first rendition read each sensor and wrote sequentially to the file, which only lead to a data rate of 60hz. This wasn't nearly high enough for picking up spikes in forces. Instead, sensors are read in a loop to a buffer and then the entire buffer is written to the file when full. This led to a data rate of over 300hz, which is perfect for analysis.

### Data Collection
The car was put through multiple tests in an open parking lot that included acceleration, braking, hard turning, spinning out, and hitting a cone (for the front suspension only). Between individual tests, the data was pulled and the file name was changed to what test was being logged.
