# UBX_Parser
C++ parser for binary UBX GPS messages with Arduino example

Clone / unzip this folder into you Arduino libraries folder, and do

\#include \<UBX_Parser.h\> 

in your source code and then subclass the UBX_Parser class for your application.  See examples/UBX_Reader/UBX_Reader.ino for an example of how to 

Currently supports NAV_POSLLH, NAV_DOP, and NAV_VELNED messages on eight-bit Arduinos (Uno, Mega, etc.) I am working on porting it to 32-bit platforms (Due, Teensy).
