function initialize()
{
  UpdateClock(); 
}

function UpdateClock() 
{
  var now = new Date(); 
  var hrs = now.getHours();
  var min = now.getMinutes();
  var sec = now.getSeconds();
  var hs = "";
  var ms = "";
  var ss = "";
  var d = 128;
  for (i = 7; i>=0; i--) {
    hs = hs + String.fromCharCode(48 + ((hrs & d) > 0));
    ms = ms + String.fromCharCode(48 + ((min & d) > 0));
    ss = ss + String.fromCharCode(48 + ((sec & d) > 0));
    d >>= 1;
  }
  document.getElementById("clock").innerHTML = hs + ":" + ms + ":" + ss;
  newtime = window.setTimeout("UpdateClock();", 1000); // update clock display once per second
}
