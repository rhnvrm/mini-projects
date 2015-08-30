var express = require('express');
var bodyParser = require('body-parser');
var methodOverride = require('method-override');
var mongoose = require('mongoose');
var Schema = mongoose.Schema;
var restify = require('express-restify-mongoose')
 
mongoose.connect('mongodb://localhost/database');
 
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
 /*
var Invoice = new Schema({
    customer: { type: Schema.Types.ObjectId, ref: 'Customer' },
    amount: { type: Number, required: true }
});
var InvoiceModel = mongoose.model('Invoice', Invoice);
 */

var app = express();
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(methodOverride());
 
var router = express.Router();
restify.serve(router, MarkerModel);
//restify.serve(router, InvoiceModel);
app.use(router);
 
app.listen(8080, function() {
    console.log("Express server listening on port 8080");
});