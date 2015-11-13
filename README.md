# UBX_Parser
C++ parser for binary UBX GPS messages with Arduino example

Clone / unzip this folder into your Arduino libraries folder, and do

\#include \<UBX_Parser.h\> 

in your source code and then subclass the UBX_Parser class for your application.  See examples/UBX_Reader/UBX_Reader.ino for an example.

Currently supports NAV_POSLLH, NAV_DOP, and NAV_VELNED messages. Tested on Arduino Mega 2560, Arduino Due, and Teensy 3.2.
