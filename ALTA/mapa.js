alert("Mapa carregado!");

// Cria o mapa
var mapa = L.map('map').setView([-29.168, -51.179], 12);

// Carrega o mapa
L.tileLayer(
'https://server.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer/tile/{z}/{y}/{x}',
{
    attribution: 'Tiles © Esri'
}).addTo(mapa);

// Sensor 1
L.marker([-29.168,-51.179])//latitude e longitude
.addTo(mapa)

.bindPopup(

"<b>Sensor 1</b><br>" +

"Nível: 18 cm<br>" +

"Status: 🟡 Atenção"

);

// Sensor 2
L.marker([-29.182,-51.160])

.addTo(mapa)

.bindPopup(

"<b>Sensor 2</b><br>" +

"Nível: 9 cm<br>" +

"Status: 🔴 Emergência"

);