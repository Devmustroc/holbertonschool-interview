#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];

if (!movieId) {
  console.log('Usage: /0-starwars_characters.js <MOVIE_ID>');
  process.exit(1);
}

const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;

request(url, async function (error, response, body) {
  if (error) console.log(error);
  if (response.statusCode === 404) {
    console.log('This movie ID does not exist');
    process.exit(1);
  }
  const characters = JSON.parse(body).characters;
  for (let i = 0; i < characters.length; i++) {
    await getCharacterName(characters[i]).then((result) => {
      console.log(result);
    }).catch((error) => {
      console.log(error);
    });
  }
});

function getCharacterName (url) {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (error) reject(error);
      const character = JSON.parse(body).name;
      resolve(character);
    });
  });
}
