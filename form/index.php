<?php echo '<pre>';
$data = $_POST;
$json_string = json_encode($data, JSON_PRETTY_PRINT);
echo $json_string;
echo '</pre>';
?>

<html>
    <head>
        <script type="text/javascript" src="https://maps.googleapis.com/maps/api/js"></script>

        <link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css" rel="stylesheet" integrity="sha256-MfvZlkHCEqatNoGiOXveE8FIwMzZg4W85qfrfIFBfYc= sha512-dTfge/zgoMYpP7QbHy4gWMEGsbsdZeCXz7irItjcC3sPUFtf0kuFbDz/ixG7ArTxmDjLXDmezHubeNikyKGVyQ==" crossorigin="anonymous">
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js" integrity="sha256-Sk3nkD6mLTMOF0EOpNtsIry+s1CsaqQC1rVLTAy+0yc= sha512-K1qjQ+NcF2TYO/eI3M6v8EiNYZfA95pQumfvcVrTHtwQVDG+aHRqLi/ETn2uB+1JqwYqVG3LIvdm9lj6imS/pQ==" crossorigin="anonymous"></script>
        <title>Save Marker Example</title>

    </head>
    <body>
    <div class="container">
        <h1>Data Entry Portal for Tripostay.com</h1>
        <form method="post" action=<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?> enctype='application/json'>
        <div class = "row">
            <h2>Enter the following details:</h2>
            <div class = "form-group">
                    <label>Formatted Address:</label>
                    <input name="formatted_address" type="text" class="form-control" >
            </div>
            <div class = "form-group">
                    <label>Gender:</label>
                    <input name="Gender" type="text" class="form-control" >
            </div>
            <div class = "form-group">
                    <h3>Room Details</h3>
                    <label>Occupants</label>
                    <input name="room[max_people]" type="text" class="form-control" >
                    <label>Rent</label>
                    <input name="room[rent]" type="text" class="form-control" >
                    <label>Security Deposit Amount</label>
                    <input name="room[security]" type="text" class="form-control" >
            </div>
        </div>
        <div class="row">
            <h2>Choose Location on Map</h2>
            <div class="col-md-6">
                <div id="map" style="width:100%; height:300px;" ></div>
            </div>
            <div class="col-md-1"></div>
            <div class="col-md-4">
                <h2>Chosen Location</h2>
                <div class = "form-group">
                    <label for="lat">Lat:</label>
                    <input type="text" class="form-control" id = "lat" name="loc[1]" readonly="yes">
                </div>
                <div class = "form-group">        
                    <label for="lng">Lng:</label> 
                    <input type="text" class="form-control" id = "lng" name="loc[0]" readonly="yes">
                </div>
                <div class = "form-group">
                    <label for="rev_geo_address">Reverse Geocoding Data:</label> 
                    <input type="text" id="rev_geo_address" name ="rev_geo_address" class="form-control" readonly="yes">
                </div>
            </div>
        </div>
        <div class="row"><br></div>
        <div class="row">
            <input type="submit" class="btn btn-primary btn-block">
        </div>
        </form>
        <script type="text/javascript" src="map.js"></script>
    </body>
</html>