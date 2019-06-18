# contador-de-likes

Device that displays the number of likes of a Facebook page.

## Dependencies

### Server

Go to the `server/` direcotry and do

```
npm install
```

to install all dependencies.

### Client

* [particle-cli](https://docs.particle.io/tutorials/developer-tools/cli/#installing).

### Harware

The box is made of laser-cut 1/8 inch wood. The SVG file can be found in
`hardware/box.svg`. And the modifiable OpenSCAD file can be found in
`hardware/box.scad`.

The following is the list of electronic materials:

* 1 x [Particle Photon](https://store.particle.io/collections/wifi)
* 2 x [Adafruit 1.2" 4-Digit 7-Segment Display w/I2C Backpack](https://www.adafruit.com/product/1270)
* 1 x Micro USB cable
* Jumper cables

## Configuring

### Server

1. Copy `config.example.json` to `config.json`.
2. Edit `config.json` so that it has your page access token, the id of the
page, and the port number it is going to run on.

### Client

1. Copy `webhook.example.json` to `webhook.json`.
2. Edit `webhook.json` so that it has the URL to the server under the `url`
property.
3. Run `particle webhook create webhook.json` to create the webhook.

## Running

### Server

```
node server/main.js
```

or install [forever](https://www.npmjs.com/package/forever) and run

```
forever server/main.js
```

### Client

Go to the `client/` directory and compile with

```
particle compile photon
```

That will generate a firmware file. Then install that file to the Photon with

```
particle flash [PHOTON_NAME] [GENERATED_FIRMWARE_FILE.bin]
```

## License

Copyright (C) 2019  El Garage Project Hub, Javier Rizzo-Aguirre

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
