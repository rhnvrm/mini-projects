
//Set up some of our variables.
var map; //Will contain map object.
var marker = false; ////Has the user plotted their location marker? 
        
//Function called to initialize / create the map.
//This is called when the page has loaded.
function initMap() {
 
    //The center location of our map.
    var centerOfMap = new google.maps.LatLng(28.454128087733384, 77.03450202941895);
 
    //Map options.
    var options = {
      center: centerOfMap, //Set center.
      zoom: 13, //The zoom value.
      mapTypeId: google.maps.MapTypeId.ROADMAP
    };
 
    //Create the map object.
    map = new google.maps.Map(document.getElementById('map'), options);
 
    var geocoder = new google.maps.Geocoder;

    //Listen for any clicks on the map.
    google.maps.event.addListener(map, 'click', function(event) {                
        //Get the location that the user clicked.
        var clickedLocation = event.latLng;
        //If the marker hasn't been added.
        if(marker === false){
            //Create the marker.
            marker = new google.maps.Marker({
                position: clickedLocation,
                map: map,
                draggable: true //make it draggable
            });
            //Listen for drag events!
            google.maps.event.addListener(marker, 'dragend', function(event){
                markerLocation();
            });
        } else{
            //Marker has already been added, so just change its location.
            marker.setPosition(clickedLocation);
        }
        //Get the marker's location.
        markerLocation();
        geocodeLatLng(geocoder, map);
    });
}
        
//This function will get the marker's current location and then add the lat/long
//values to our textfields so that we can save the location.
function markerLocation(){
    //Get location.
    var currentLocation = marker.getPosition();
    //Add lat and lng values to a field that we can save.
    document.getElementById('lat').value = currentLocation.lat(); //latitude
    document.getElementById('lng').value = currentLocation.lng(); //longitude
}

function geocodeLatLng(geocoder, map) {
  var latlngStr = [document.getElementById('lat').value, document.getElementById('lng').value]
  var latlng = {lat: parseFloat(latlngStr[0]), lng: parseFloat(latlngStr[1])};
  geocoder.geocode({'location': latlng}, function(results, status) {
    if (status === google.maps.GeocoderStatus.OK) {
      if (results[1]) {
        document.getElementById('rev_geo_address').value = results[1].formatted_address;
      } else {
        window.alert('No results found in Geocoder');
      }
    } else {
      window.alert('Geocoder failed due to: ' + status);
    }
  });
}
        
        
//Load the map when the page has finished loading.
google.maps.event.addDomListener(window, 'load', initMap);