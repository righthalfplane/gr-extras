# gr-extras
gr-extras is a gnuradio Out Of Tree Modules program. Currenty the only module is a impulse source program. The impulse source generates an output signal containing all of the frequencies requested. Feeding the signal through a filter to a Frequency Sink yields the frequency response of the filter. 

The versions of gnuradio are incompatable with one another, so I had to create three versions of the program - gr-extras(Mac-Ubuntu20.04), gr-extras(PI4), gr-extras(Ubuntu18.04). Be sure to build the program and select the example from the correct tree. ImpulseSource.grc is an example of showing the frequence response of various filter. Enable the filter you want to see and Disable all the rest.

# Building The Program

Go into the gr-extras folder of the correct version and issue the following command -

```
On MacOS -
cd gr-extras(Mac-Ubuntu20.04)
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/opt/local ../
make -j 6
sudo make install
gnuradio-companion

On Ubuntu 20.04,Ubuntu 18.04, and PI4
cd  gr-extras(Mac-Ubuntu20.04) or cd  gr-extras(Ubuntu18.04) cd gr-extras(PI4)
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr ../
make -j 6
sudo make install
gnuradio-companion
```



# Run The Program

gnuradio-companion
