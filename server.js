var express = require('express');
var bodyParser = require('body-parser');
var methodOverride = require('method-override');
var mongoose = require('mongoose');
var Schema = mongoose.Schema;
var restify = require('express-restify-mongoose');
var cors = require('cors');

 
mongoose.connect('mongodb://localhost/database');
 
var MarkerSchema = new Schema({
  loc: [],
  formatted_address: {
    type: String,
    index: 'text'
  },
  gender: Number,
  rooms: {
    max_people: Number,
    rent: Number,
  security: Number
  },
  galleryurl: String,
  services: {
    food: {
      breakfast: Number,
      lunch: Number,
      dinner: Number
    },
    housekeeping: {
      remark: String,
      cost: Number
    },
    parking: String,
    laundry: String
  },
  rules:{
      drinking: Number,
      smoking: Number
  }
});
MarkerSchema.index({ loc: '2d' });
var Marker = mongoose.model('Marker', MarkerSchema);


var app = express();
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(methodOverride());
app.use(cors());

 
var router = express.Router();
restify.serve(router, Marker);
//restify.serve(router, InvoiceModel);
app.use(router);
 
app.listen(8080, function() {
    console.log("Express server listening on port 8080");/*
    Marker.find({ loc : { '$near' : [78.881213, 28.366455] } }, console.log);
    Marker.find({ loc : { '$near' : [78.881213, 28.366455] } }).limit(5).exec(console.log);*/
     

     /*mongoose.connection.db.executeDbCommand({ 
  geoNear : 'Marker',  // the mongo collection
  near : [78.881213, 28.366455], // the geo point
  spherical : true,  // tell mongo the earth is round, so it calculates based on a 
                     // spherical location system
  distanceMultiplier: 6371, // tell mongo how many radians go into one kilometer.
  maxDistance : 1/6371, // tell mongo the max distance in radians to filter out
}, function(err, result) {
  console.log(result.documents[0].results);
}); */
});