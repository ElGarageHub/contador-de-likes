/*
   This file is part of contador-de-likes.

   contador-de-likes is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   contador-de-likes is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with contador-de-likes.  If not, see <http://www.gnu.org/licenses/>.
*/

'use strict';

const fs = require('fs');
let config = null;
let FB = require('fb');

fs.readFile('config.json', 'utf8', (err, data) => {
  if(err) throw err;
  config = JSON.parse(data);
  FB.setAccessToken(config.accessToken);
  FB.api(config.pageId + '?fields=id,name,fan_count,link', function(res) {
    if(!res || res.error) {
      console.log('Error: ' + res.error);
      return;
    }
    console.log(res);
  });
});

