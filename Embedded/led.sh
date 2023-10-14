#!/bin/sh
if [ ! -d /sys/class/gpio/gpio44 ]; then
    echo 44 > /sys/class/gpio/export;
fi
if [ ! -d /sys/class/gpio/gpio45 ]; then
    echo 45 > /sys/class/gpio/export;
fi

echo out > /sys/class/gpio/gpio44/direction;
echo out > /sys/class/gpio/gpio45/direction;

for ((i=0; i<10; i++)); do
    echo 1 > /sys/class/gpio/gpio44/value;
    echo 0 > /sys/class/gpio/gpio45/value;
    sleep 1;
    echo 0 > /sys/class/gpio/gpio44/value;
    echo 1 > /sys/class/gpio/gpio45/value;
    sleep 1;
done
echo 0 > /sys/class/gpio/gpio44/value;
echo 0 > /sys/class/gpio/gpio45/value;
