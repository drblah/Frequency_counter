Frequency_counter
=================

Ever needed a simple frequency counter? Upload this to your Arduino!

The input is on pin 2 by default.

Open a serial terminal to the Arduino to get the measured frequency.

Tweaks
=================
Measuring a low frequency signal (<100Hz) might cause the Arduino to hang. This happens because it is stuck sampling
the high and low periods of the signal. To avert this you can reduce the number of samples it takes of each high or low signal state.
The downside of lowering the number of samples is that you get more noise on higher frequency measurements.

Limitations
=================
This is not a very precise way to measure the frequency of a signal, so don’t expect miracles.
I have been able to measure signals up to about 19-20 KHz with this program. Anything above that gives false readings.