/*
  * UBX_Reporter: A simple demo of the UBX_Parser class on Arduino.
  *
  * UBX_Parser.h - A header-only C++ class for parsing UBX messages from Ublox GPS
  *
  * Copyright (C) 2015 Simon D. Levy
  *
  * This code is free software: you can redistribute it and/or modify
  * it under the terms of the GNU Lesser General Public License as 
  * published by the Free Software Foundation, either version 3 of the 
  * License, or (at your option) any later version.
  * 
  * This code is distributed in the hope that it will be useful,     
  * but WITHOUT ANY WARRANTY without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  * 
  * You should have received a copy of the GNU Lesser General Public License 
  * along with this code.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <UBX_Parser.h>

class MyParser : public UBX_Parser {

    void handle_NAV_POSLLH(unsigned long iTOW, 
            long lon, 
            long lat, 
            long height, 
            long hMSL, 
            unsigned long hAcc, 
            unsigned long vAcc) {

        Serial.print("NAV-POSLLH: iTOW=");
        Serial.print(iTOW);
        Serial.print("ms lat=");
        Serial.print(lat/1e7,7);
        Serial.print("deg lon=");
        Serial.print(lon/1e7,7);
        Serial.print("deg height=");
        Serial.print(height);
        Serial.print("mm hMSL=");
        Serial.print(hMSL);
        Serial.print("mm hAcc=");
        Serial.print(hAcc);
        Serial.print("mm vAcc=");
        Serial.print(vAcc);
        Serial.println("mm");
    }  

    void handle_NAV_DOP(unsigned long iTOW, 
            unsigned short gDOP,
            unsigned short pDOP,
            unsigned short tDOP,
            unsigned short vDOP,
            unsigned short hDOP,
            unsigned short nDOP,
            unsigned short eDOP) {

        Serial.print("NAV-DOP: iTOW=");
        Serial.print(iTOW);
        Serial.print("ms gDOP=");
        Serial.print(gDOP/100., 2);
        Serial.print(" pDOP=");
        Serial.print(gDOP/100., 2);
        Serial.print(" tDOP=");
        Serial.print(tDOP/100., 2);
        Serial.print(" vDOP=");
        Serial.print(vDOP/100., 2);
        Serial.print(" hDOP=");
        Serial.print(hDOP/100., 2);
        Serial.print(" nDOP=");
        Serial.print(nDOP/100., 2);
        Serial.print(" eDOP=");
        Serial.println(eDOP/100., 2);
    }

    virtual void handle_NAV_VELNED(unsigned long iTOW,
            long velN,
            long velE,
            long velD,
            unsigned long speed,
            unsigned long gSpeed,
            long heading,
            unsigned long sAcc,
            unsigned long cAcc)
    {
        Serial.print("NAV-VELNED: iTOW=");
        Serial.print(iTOW);
        Serial.print("ms velN=");
        Serial.print(velN);
        Serial.print("cm/s");
        Serial.print("ms velE=");
        Serial.print(velE);
        Serial.print("cm/s");
        Serial.print("ms velD=");
        Serial.print(velD);
        Serial.print("cm/s speed=");
        Serial.print(speed);
        Serial.print("cm/s gSpeed=");
        Serial.print(gSpeed);
        Serial.print("cm/s heading=");
        Serial.print(heading/1e5, 5);
        Serial.print("deg sAcc=");
        Serial.print(sAcc);
        Serial.print("cm/s cAcc=");
        Serial.print(cAcc/1e5, 5);
        Serial.println("deg");
     }


    /* Un-comment this to report IDs of messages available but not yet handled.
    void reportUnhandled(char msgid) {
        Serial.print("Got message ID ");
        Serial.println(msgid&0xFF, HEX);
    }
    */
};

MyParser parser;

void setup() {

    Serial1.begin(57600);

    Serial.begin(9600);
}

void loop() {

    if (Serial1.available()) {

        parser.parse(Serial1.read());
    }

}
