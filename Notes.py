import sounddevice
from numpy import *
import time
import serial

fs=8000.0;
t= arange(.25*fs)/fs
C = sin(2*pi*523*t);
D = sin(2*pi*587*t);
E = sin(2*pi*659*t);
F = sin(2*pi*688*t);
G = sin(2*pi*784*t);
A = sin(2*pi*880*t);
B = sin(2*pi*988*t);
Z = sin(2*pi*1047*t);



port = serial.Serial("COM5",baudrate=9600,timeout=1);

running = True
while (running):
    rec = port.read()
    if (rec=='C'):
        sounddevice.play(C,samplerate=8000,blocking=True)
    elif  (rec=='D'):
        sounddevice.play(D,samplerate=8000,blocking=True)
    elif (rec=='E'):
        sounddevice.play(E,samplerate=8000,blocking=True)
    elif  (rec=='F'):
        sounddevice.play(F,samplerate=8000,blocking=True)
    elif (rec=='G'):
        sounddevice.play(G,samplerate=8000,blocking=True)
    elif  (rec=='A'):
        sounddevice.play(A,samplerate=8000,blocking=True)
    elif (rec=='B'):
        sounddevice.play(B,samplerate=8000,blocking=True)
    elif  (rec=='Z'):
        sounddevice.play(Z,samplerate=8000,blocking=True)
