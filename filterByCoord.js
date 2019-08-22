
function filterByCoord(){
  
  var lat = document.getElementById("lat").value;
  var lng = document.getElementById("lng").value;
  var radius = document.getElementById("radius").value;

  var kmInLat = 0.0268880;
  var help = lat*(Math.PI/180);
  help = Math.cos(help);
  var kmInLng = 1 /(111.320 * help );
  kmInLng = kmInLng.toFixed(6);
  
if((lat >= -90 && lat <= 90) && (lng >= -180 && lng <= 180) )
{

var radiusLat = kmInLat*radius;
var radiusLng = kmInLng*radius;
radiusLat = radiusLat.toFixed(6);
radiusLng = radiusLng.toFixed(6);

var helper = parseFloat(lat)+parseFloat(radiusLat);
var helper2= parseFloat(lat)-parseFloat(radiusLat);
var helper3 = parseFloat(lng)+parseFloat(radiusLng);
var helper4 = parseFloat(lng)-parseFloat(radiusLng);

helper = helper.toFixed(6);
helper2 = helper2.toFixed(6);
helper3 = helper3.toFixed(6);
helper4 = helper4.toFixed(6);

 var map = new google.maps.Map(document.getElementById('map'), {
          center: new google.maps.LatLng(42.694767, 23.315017),
          zoom: 13
        });
        var infoWindow = new google.maps.InfoWindow;
        deleteMarkers();
 downloadUrl('outputxml.php', function(data) {
            var xml = data.responseXML;
            var markers = xml.documentElement.getElementsByTagName('marker');
            var maxID = 0;
            Array.prototype.forEach.call(markers, function(markerElem) {
              var id = markerElem.getAttribute('id');
              var name = markerElem.getAttribute('name');
              var address = markerElem.getAttribute('address');
              var type = markerElem.getAttribute('type');
              var point = new google.maps.LatLng(
                  parseFloat(markerElem.getAttribute('lat')),
                  parseFloat(markerElem.getAttribute('lng')));

              var latitude = markerElem.getAttribute('lat');
              var longitude = markerElem.getAttribute('lng');
              
              var infowincontent = document.createElement('div');
              var strong = document.createElement('strong');
              strong.textContent = name
              infowincontent.appendChild(strong);
              infowincontent.appendChild(document.createElement('br'));

              var text = document.createElement('text');
              text.textContent = point
              infowincontent.appendChild(text);
              
              if((latitude <= helper && latitude >= helper2) &&
              (longitude <= helper3 && longitude >= helper4 ) )
              {
              maxID++;
                var icon = customLabel[type] || {};
             marker = new google.maps.Marker({
                map: map,
                position: point,
                label: icon.label
              });
                marker.addListener('click', function() {
                infoWindow.setContent(infowincontent);
                infoWindow.open(map, marker);
              });
               }
              
            });
            
            
            var content = "Markers filtered by coordinates are :  " + maxID
            document.getElementById("text").innerHTML=content;
          });

}
else
{
	alert("Please enter valid values for lat [-90;90] or lng [-180;180] !");
}

}
