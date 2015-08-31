var express = require('express');
var bodyParser = require('body-parser');
var methodOverride = require('method-override');
var mongoose = require('mongoose');
var Schema = mongoose.Schema;
var restify = require('express-restify-mongoose');
var cors = require('cors');

 
mongoose.connect('mongodb://user:passw0rd@waffle.modulusmongo.net:27017/abeqoS9i');
 
var MarkerSchema = new Schema({
  location: { 
    type: [Number],  // [<longitude>, <latitude>]
    index: '2d'
  },
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
MarkerSchema.index({location: '2d', formatted_address: "text"});
var MarkerModel = mongoose.model('Marker', MarkerSchema);


var app = express();
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(methodOverride());
app.use(cors());

 
var router = express.Router();
restify.serve(router, MarkerModel);
//restify.serve(router, InvoiceModel);
app.use(router);
 
app.listen(8080, function() {
    console.log("Express server listening on port 8080");
});