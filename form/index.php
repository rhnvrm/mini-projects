<html>
    <head>
        <script type="text/javascript" src="https://maps.googleapis.com/maps/api/js"></script>
        <script src="https://code.jquery.com/jquery-1.10.2.js"></script>
        <link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css" rel="stylesheet" integrity="sha256-MfvZlkHCEqatNoGiOXveE8FIwMzZg4W85qfrfIFBfYc= sha512-dTfge/zgoMYpP7QbHy4gWMEGsbsdZeCXz7irItjcC3sPUFtf0kuFbDz/ixG7ArTxmDjLXDmezHubeNikyKGVyQ==" crossorigin="anonymous">
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js" integrity="sha256-Sk3nkD6mLTMOF0EOpNtsIry+s1CsaqQC1rVLTAy+0yc= sha512-K1qjQ+NcF2TYO/eI3M6v8EiNYZfA95pQumfvcVrTHtwQVDG+aHRqLi/ETn2uB+1JqwYqVG3LIvdm9lj6imS/pQ==" crossorigin="anonymous"></script>
        <title>Data Entry Portal for Tripostay.com</title>

    </head>
    <body <?php 

    if(isset($_POST["gender"])){
        echo "onload='submitData()'";
    }

?>
>
    <div class="container">
        <h1 class="pager">Data Entry Portal for <span class = "glyphicon glyphicon-home" aria-hidden="true">tripostay.com</span></h1>
        <form method="post" id="myForm" action="/" enctype="application/json">
        <div class = "row">
            <h2>Enter the following details:</h2>
            <div class = "form-group">
                    <label>Formatted Address:</label>
                    <input name="formatted_address" type="text" class="form-control" >
            </div>
            <div class = "form-group">
                    <label>Gender:</label>
                        <select name ="gender" class="form-control">
                        <option>Male</option>
                        <option>Female</option>
                        <option>Male/Female</option>
                    </select>
            </div>
           <!-- <iframe id="myIframe" src = "http://imgur.com" height = "500px" width="100%" ></iframe> -->
            <div class = "form-group">
                    <label>Gallery URL</label>
                    <input name="galleryurl" type="text" class="form-control" >              
            </div>
            <div class = "form-group">
                    <h3>Room Details</h3>
                    <label>Occupants</label>
                    <select name ="room[max_people]" class="form-control">
                      <option>1</option>
                      <option>2</option>
                      <option>3</option>
                      <option>4</option>
                      <option>5</option>
                    </select>
                    <!--<input name="room[max_people]" type="text" class="form-control" >-->
                    <label>Rent Amount</label>
                    <input name="room[rent]" type="number" class="form-control" >
                    <label>Security Deposit Amount</label>
                    <input name="room[security]" type="number" class="form-control" >
            </div>
            <div class = "form-group">
                    <h3>Services</h3>
                    <h4>Food</h4>
                    <label>Breakfast</label>
                    <select name ="services[food][breakfast]" class="form-control">
                      <option>Yes</option>
                      <option>No</option>
                    </select>
                    <label>Lunch</label>
                    <select name ="services[food][lunch]" class="form-control">
                      <option>Yes</option>
                      <option>No</option>
                    </select>
                    <label>Dinner</label>
                    <select name ="services[food][dinner]" class="form-control">
                      <option>Yes</option>
                      <option>No</option>
                    </select>
                    <label>Cost</label>
                    <input name="services[food][cost]" type="number" class="form-control" >
                    
                    <h4>Housekeeping</h4>
                    <label>Cost</label>
                    <input name="services[housekeeping][cost]" type="number" class="form-control" >
                    <label>Available</label>
                    <select name ="services[housekeeping][available]" class="form-control">
                      <option>Yes</option>
                      <option>No</option>
                    </select>

                    <h4>Misc Services</h4>
                    <label>Parking</label>
                    <select name ="services[parking]" class="form-control">
                      <option>Yes</option>
                      <option>No</option>
                    </select>
                    <label>Laundry</label>
                    <select name ="services[laundry]" class="form-control">
                      <option>Yes</option>
                      <option>No</option>
                    </select>

            </div>
            <div class = "form-group">
                    <h3>Rules</h3>
                    <label>Drinking</label>
                    <select name ="rules[drinking]" class="form-control">
                      <option>Yes</option>
                      <option>No</option>
                    </select>
                    <label>Smoking</label>
                    <select name ="rules[drinking]" class="form-control">
                      <option>Yes</option>
                      <option>No</option>
                    </select>                
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
                    <input type="number" class="form-control" id = "lat" name="loc[1]" readonly="yes">
                </div>
                <div class = "form-group">        
                    <label for="lng">Lng:</label> 
                    <input type="number" class="form-control" id = "lng" name="loc[0]" readonly="yes">
                </div>
                <div class = "form-group">
                    <label for="rev_geo_address">Reverse Geocoding Data:</label> 
                    <input type="text" id="rev_geo_address" name ="rev_geo_address" class="form-control" readonly="yes">
                </div>
            </div>
        </div>
        <div class="row"><br></div>
        <div class="row">
            <input id="submit" value="Submit" type="submit" class="btn btn-primary btn-block">
        </div>
        </form>
        <script type="text/javascript">

        function submitData() {
         
            var formData = 
               
                <?php 
                    $data = $_POST;
                    $json_string = json_encode($data, JSON_PRETTY_PRINT);
                    echo $json_string;
                ?>

            ;


            alert("Added!");
            $.ajax({
              type: "POST",
              url: "http://129.199.199.233:8080/api/v1/Markers",
              data: JSON.stringify(formData),
              success: function(){
                console.log("Added!");
              },
              dataType: "json",
              contentType : "application/json"
            });
        }

        </script>
        <script type="text/javascript" src="map.js"></script>
    </body>
</html>