var express = require('express');
var bodyParser = require('body-parser');
var methodOverride = require('method-override');
var mongoose = require('mongoose');
var Schema = mongoose.Schema;
var restify = require('express-restify-mongoose');
var cors = require('cors');

 
mongoose.connect('mongodb://localhost/db_tripostay_1');
 
var MarkerSchema = new Schema({
  loc: [],
  formatted_address: {
    type: String,
    index: 'text'
  },
  rev_geo_address: {
    type: String,
    index: 'text'
  },
  gender: String,
  room: {
    max_people: Number,
    rent: Number,
    security: Number
  },
  galleryurl: String,
  services: {
    food: {
      breakfast: String,
      lunch: String,
      dinner: String,
      cost: Number
    },
    housekeeping: {
      available: String,
      cost: Number
    },
    parking: String,
    laundry: String
  },
  rules:{
      drinking: String,
      smoking: String
  }
});
MarkerSchema.index({ loc: '2d' });

var Marker = mongoose.model('Marker', MarkerSchema);


var app = express();
app.use(function(req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  next();
});
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(methodOverride());
app.use(cors());
app.options('*', cors());
 
var router = express.Router();
restify.serve(router, Marker);
//restify.serve(router, InvoiceModel);
app.use(router);

app.get('/near/:lng/:lat', function(req, res) {
      Marker.find({ loc : { '$near' : [parseFloat(req.params.lng), parseFloat(req.params.lat)] } }).limit(10).exec(function(err, data){
        if(err){
          res.send(500, "something went wrong");
        }
        else{
          res.json(data);
        }
      });
      //console.log("heare");
});

app.post('/mirror', function(req, res) {
      console.log(req);
      //console.log("heare");
      res.json("See console");
});
 
app.listen(8080, function() {
console.log("Express server listening on port 8080");
});

/*
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