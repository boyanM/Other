function NAME_OF_THE_TYPE(){
          
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

              var infowincontent = document.createElement('div');
              var strong = document.createElement('strong');
              strong.textContent = name
              infowincontent.appendChild(strong);
              infowincontent.appendChild(document.createElement('br'));

              var text = document.createElement('text');
              text.textContent = point
              infowincontent.appendChild(text);
              
              if(type == "NAME_OF_THE_TYPE"){
                maxID=maxID+1;
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
            
            var content = "Markers of type restaurant are :  " + maxID;
        
           document.getElementById("text").innerHTML=content;
          });
}
