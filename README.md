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

## Configuring

### Server

1. Copy `config.example.json` to `config.json`.
2. Edit `config.json` so that it has your page access token, the id of the
page, and the port number it is going to run on.

## Running

### Server

```
node server/main.js
```

or install forever and run

```
forever server/main.js
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
