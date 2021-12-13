# gtk_wiringpi_input-output
***gtk application to toggle and read gpio pin using wiringpi.***

## Usage
```bash
# install library wiringpi on pi4
cd /tmp
wget https://project-downloads.drogon.net/wiringpi-latest.deb
sudo dpkg -i wiringpi-latest.deb

# install gtk
sudo apt-get install libgtk-3-dev

#check with:
gpio -v

# build
gcc `pkg-config --cflags --libs gtk+-2.0` hello-world-gtk.c -o GTK_start -lwiringPi

# run
use vnc-viewer to run application
 ```
