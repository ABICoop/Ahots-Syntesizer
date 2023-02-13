# AHOTS SYNTESIZER

![](https://github.com/ABICoop/Ahots-Syntesizer/blob/main/portada.png?raw=true)

## Pasos a seguir para crear una estación meteorológica
Para este proyecto  vamos a aprender cómo hacer una estación meteorológica inalámbrica alimentada mediante  energía solar , con  el uso de un módulo Wifi ESP32 y algunos sensores  lograremos tener información en tiempo real . 

La ventaja de tener una estación meteorológica es que no necesita  estar conectada a una fuente de corriente constante por lo que ahorraremos mucha energía y además puede establecerse en lugares remotos , otra ventaja que tiene es que podemos comprar estos componentes a un precio reducido con lo cual recortamos muchos gastos y hace que se muy asequible .

Para hacer posible esta estación meteorológica vamos a necesitar los siguientes componentes:

***

> **CHIPS**                     
* [BME280](https://www.amazon.com/Dmyond-Atmospheric-Pressure-Temperature-Humidity/dp/B07XKSBQ9B?dchild=1&keywords=bme280&qid=1614277072&sr=8-3&linkCode=sl1&tag=opegreene-20&linkId=a7bc2117d73d0f7eb2ab3e97b1371d81&language=en_US&ref_=as_li_ss_tl) 
* [DS18B20](https://www.amazon.com/DS18B20-Temperature-Waterproof-Digital-Thermal/dp/B085WBVZHN?dchild=1&keywords=ds18b20&qid=1616433136&sr=8-6&linkCode=sl1&tag=opegreene-20&linkId=2f1de982125dca6b81fe4edc64fe6d13&language=en_US&ref_=as_li_ss_tl)
* [BH1750](https://www.amazon.com/HiLetgo-GY-302-BH1750-Intensity-Illumination/dp/B00M0F29OS?dchild=1&keywords=bh1750&qid=1616433104&sr=8-2&linkCode=sl1&tag=opegreene-20&linkId=be4f1b2d58fde9fd54e054d229d9b78b&language=en_US&ref_=as_li_ss_tl)
* [ESP32 Dev Kit V1 - 30 Pins](https://es.aliexpress.com/item/1005001757645011.html?spm=a2g0o.productlist.0.0.416151a1NUw6RO&algo_pvid=2d24cfce-1aa1-4b7b-86fc-22c4ee90f801&algo_exp_id=2d24cfce-1aa1-4b7b-86fc-22c4ee90f801-4&pdp_ext_f=%7B%22sku_id%22%3A%2212000017777037101%22%7D&aff_fcid=eb314f78fed945459619d5a477146561-1639645107023-02758-_AMwZBY&tt=CPS_NORMAL&aff_fsk=_AMwZBY&aff_platform=portals-tool&sk=_AMwZBY&aff_trace_key=eb314f78fed945459619d5a477146561-1639645107023-02758-_AMwZBY&terminal_id=415eac4692da4a489d70c72e94ebc887&afSmartRedirect=n)
* [TP4056](https://es.aliexpress.com/item/1005001562314459.html?spm=a2g0o.productlist.0.0.86152f4a42r7EJ&algo_pvid=7204546f-dddb-490a-b085-c94f3ce809a7&algo_exp_id=7204546f-dddb-490a-b085-c94f3ce809a7-0&pdp_ext_f=%7B%22sku_id%22%3A%2212000016601477686%22%7D&aff_fcid=d7f1e4fed45f490a92a2ba37d64bc182-1639645323510-03922-_AKp5rg&tt=CPS_NORMAL&aff_fsk=_AKp5rg&aff_platform=portals-tool&sk=_AKp5rg&aff_trace_key=d7f1e4fed45f490a92a2ba37d64bc182-1639645323510-03922-_AKp5rg&terminal_id=415eac4692da4a489d70c72e94ebc887&afSmartRedirect=n)
* [GY1145](https://www.amazon.com/Comimark-SI1145-Visible-Sensor-Breakout/dp/B07WVJDNGF?dchild=1&keywords=gy1145&qid=1616433052&sr=8-1&linkCode=sl1&tag=opegreene-20&linkId=72763b55e8145cef9f5c7e9d2336e2f2&language=en_US&ref_=as_li_ss_tl)
* [DT1042-04SO](https://www.amazon.com/DT1042-04SO-7-Suppressor-Uni-Dir-Automotive-SOT-26/dp/B07NLKFPK7?dchild=1&keywords=DT1042-04SO&qid=1616075302&sr=8-1&linkCode=sl1&tag=opegreene-20&linkId=c03b68dee3ea2cbeb39aaa523880d33d&language=en_US&ref_=as_li_ss_tl)

***

> **RESISTENCIAS**
* **1 KΩ**  x2
* **4,7 KΩ**  x3
* **10 KΩ**  x1
* **27 KΩ**  x1
* **100 KΩ**  x1

***

> **TRANSISTORES**
* [MCP1700-3.3V](https://www.amazon.com/10PCS-MCP1702-3302E-3-3V-92-3-MCP1702/dp/B01IL71VPG?dchild=1&keywords=mcp1700-3302&qid=1614277291&sr=8-4&linkCode=sl1&tag=opegreene-20&linkId=89c88726b69e06bf794512e70581719d&language=en_US&ref_=as_li_ss_tl)

***

> **CONDENSADORES**

* **0.1 uF**  x2
* **1 uF**  x2
* **100 uF**  x1

***

> **COMPONENTES**
* [Wind & Rain Sensor](https://www.amazon.com/Weather-Meter-Kit-Anemometer-terminated/dp/B084DBXMPX?dchild=1&keywords=sparkfun+wind+and+rain+sensor&qid=1614277130&sr=8-3&linkCode=sl1&tag=opegreene-20&linkId=e9a2daa6282aa56d751c4b69fbfd81cf&language=en_US&ref_=as_li_ss_tl)
  * Wind Speed ( Sparkfun Weather Meter )
  * Wind Direction ( Sparkfun Weather Meter )
  * Rain Gauge ( Sparkfun Weather Meter )
* [RJ11 conector x2](https://es.aliexpress.com/item/32957716969.html?spm=a2g0s.9042311.0.0.27424c4d513tXw&aff_fcid=52b899ea0b6c4a678bc521281ab2bf25-1639645949792-07044-_99QkyW&tt=CPS_NORMAL&aff_fsk=_99QkyW&aff_platform=portals-tool&sk=_99QkyW&aff_trace_key=52b899ea0b6c4a678bc521281ab2bf25-1639645949792-07044-_99QkyW&terminal_id=415eac4692da4a489d70c72e94ebc887&afSmartRedirect=n)
* [Cables macho/hembra arduino](https://www.amazon.com/DEPEPE-2-54mm-Headers-Arduino-Prototype/dp/B074HVBTZ4?dchild=1&keywords=female+header&qid=1614277638&sr=8-3&linkCode=sl1&tag=opegreene-20&linkId=75c0eb8c0478cfef148c03a78898a051&language=en_US&ref_=as_li_ss_tl)
* [Jumper Cap  x1](https://www.amazon.com/ZYAMY-2-54mm-Standard-Circuit-Connection/dp/B077957RN7?dchild=1&keywords=jumper+pin&qid=1616432164&sr=8-1&linkCode=sl1&tag=opegreene-20&linkId=5086f72049eec52712f57d9ffbb27f1c&language=en_US&ref_=as_li_ss_tl)
* [Panel Solar 5V / 1.2Watt (110x69 mm)](https://www.amazon.com/uxcell-Small-Module-Polysilicon-Charger/dp/B07JM399X1?dchild=1&keywords=1.25+watt+solar+panel&qid=1616076033&sr=8-13&linkCode=sl1&tag=opegreene-20&linkId=c9b43e5f37894f72fd0ddea9d781e194&language=en_US&ref_=as_li_ss_tl)
* [Batería de 18650 ](https://es.aliexpress.com/item/1005001388830999.html?spm=a2g0o.productlist.0.0.740342b3KlfwgI&algo_pvid=eeccd76b-a0c9-4308-be87-2145b5a29524&algo_exp_id=eeccd76b-a0c9-4308-be87-2145b5a29524-1&pdp_ext_f=%7B%22sku_id%22%3A%2212000015910666652%22%7D&aff_fcid=4f509cebbb4847d2a80a0569f167e655-1639646213008-01116-_ACssmU&tt=CPS_NORMAL&aff_fsk=_ACssmU&aff_platform=portals-tool&sk=_ACssmU&aff_trace_key=4f509cebbb4847d2a80a0569f167e655-1639646213008-01116-_ACssmU&terminal_id=415eac4692da4a489d70c72e94ebc887&afSmartRedirect=n)
* [Soporte de batería 18650](https://www.amazon.com/abcGoodefg-1Slotx3-7V-Battery-Plastic-Storage/dp/B075N69BMN?crid=1M1A0HB6DLHJF&dchild=1&keywords=18650+battery+holder&qid=1614277877&sprefix=18650+battery+holde,aps,366&sr=8-5&linkCode=sl1&tag=opegreene-20&linkId=c922677798d4036b3bc49ae5ca12e4c4&language=en_US&ref_=as_li_ss_tl)
* [Cables de arduino](https://www.amazon.com/Elegoo-EL-CP-004-Multicolored-Breadboard-arduino/dp/B01EV70C78?crid=2TGFZ04R0CTBC&dchild=1&keywords=jumper+wires+female+to+male&qid=1616433451&sprefix=jumper+wire,aps,426&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEyU1IwMjFYUUQzQTEwJmVuY3J5cHRlZElkPUEwNjY4NjU2RzRDWkE1QVFHMFdSJmVuY3J5cHRlZEFkSWQ9QTA5NDUzMjExRUtQVk9KOTU5MVg5JndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ%3D%3D&linkCode=sl1&tag=opegreene-20&linkId=2b274fdd7e99e5950ab9fd82304d5d3c&language=en_US&ref_=as_li_ss_tl)
* [Switch](https://www.amazon.com/Uxcell-a12013100ux0116-Position-Vertical-Switch/dp/B007QAJUUS?dchild=1&keywords=slide+switch&qid=1614278255&sr=8-4&linkCode=sl1&tag=opegreene-20&linkId=1693a2512245fea292e5e97a5a6073c2&language=en_US&ref_=as_li_ss_tl)

***

> **HERRAMIENTAS**
* [Estación de soldar](https://www.google.com/shopping/product/5042715519988754151?q=estacion+de+soldadura&prds=epd:17283412033935127216,eto:17283412033935127216_0,rsk:PC_3058408035792851722&sa=X&ved=0ahUKEwi769iqtIH2AhUGSfEDHTTRCMsQ9pwGCAU)
* [Tenazas](https://www.google.com/shopping/product/13360539414276992579?q=tenazas&prds=epd:10786235037946669078,eto:10786235037946669078_0,rsk:PC_616138079748265835&sa=X&ved=0ahUKEwi3quvFtIH2AhU4SPEDHX9oBzAQ9pwGCAU)
* [Cortante o Alicates](https://www.google.com/shopping/product/1?q=cortante&prds=epd:8859887341376829913,eto:8859887341376829913_0,pid:8859887341376829913&sa=X&ved=0ahUKEwjgp7jYtIH2AhWxRPEDHVwxBD8Q9pwGCAc)
* [Pistola de calor](https://www.lidl.es/es/pistola-digital-de-aire-caliente-2000-w/p31928?channable=4068d169640033363436383953&mktc=shopping_shop&gclid=Cj0KCQiAu62QBhC7ARIsALXijXQWMDUuuRz8qikWoShtcUb2DY4KFPrZqDnHcYnNVfwMxjrXzqm2eM8aAkJkEALw_wcB)
* [impresora 3D](https://www.banggood.com/es/Artillery-GeniusPro-and-Genius-3D-Printer-220+220+250mm-Print-Size-with-Ultra-Quiet-Stepper-Motor-TFT-Touch-Screen-Support-Filament-Runout-DetectionandPower-Failure-Function-p-1568218.html?utm_source=googleshopping&utm_medium=cpc_organic&gmcCountry=ES&utm_content=minha&utm_campaign=minha-es-es-pc&currency=EUR&cur_warehouse=CN&createTmp=1&ID=480356311367&utm_source=googleshopping&utm_medium=cpc_bgs&utm_content=dcr&utm_campaign=dcr-pla-es-es-go-0806-pc&ad_id=537777119720&gclid=Cj0KCQiAu62QBhC7ARIsALXijXTLy_i-BRHot9BOb7e63OKWBGdWPPbUybBhSH1Mct2bpDRzxPrxccwaAldQEALw_wcB)
* [Estaño](https://es.rs-online.com/web/p/estano-e-hilo-de-soldar/1047189?cm_mmc=ES-PLA-DS3A-_-google-_-CSS_ES_ES_Herramienta_El%C3%A9ctrica_y_Soldadura_Whoop+(2)-_-(ES:Whoop!)+Esta%C3%B1o+e+Hilo+de+Soldar-_-1047189&matchtype=&pla-305619873070&gclid=Cj0KCQiAu62QBhC7ARIsALXijXTX-TMjnpBkwoCMX4DuGWD5Kg1hb9i8SoM2XOcIjuM4Jp8HE7iA6VYaAvr2EALw_wcB&gclsrc=aw.ds) 

***
## MONTAJE DE LA ESTACIÓN METEOROLÓGICA
Para la creación de esta estación hemos diseñado nuestra **PCB** en la cual habrá que soldar todos los componentes mencionados arriba.

tanto los archivos de `Proteus 8`como  `Gerber X` estarán disponibles para descargar. Para el montaje y diseño nos hemos basado en esta imagen en la que se puede ver como están dispuestas las conexiones .

>**PROTEUS**
* [**ESTACION METEOROLOGICA PROGRAMA**](https://github.com/V1c7hor/Estacion-Meteorologica/tree/main/PROTEUS)

>**GERBER X**
* [**ESTACION METEOROLOGICA GERBER X**](https://github.com/V1c7hor/Estacion-Meteorologica/tree/main/GERBER%20X)

![](https://github.com/V1c7hor/Estacion-Meteorologica/blob/main/Captura%20meteorologica.JPG?raw=true)

Disposición de los componentes en la **PCB** .

![](https://github.com/V1c7hor/Estacion-Meteorologica/blob/main/PROTEUS/PROTEUS%20CONEXIONES.JPG?raw=true)
***
Para el recubrimiento de la PCB hemos utilizado una impresora 3D para este proceso, en nuestro caso es la **Artillery Genius** y hemos utilizado estos esquemas de thingiverse para ello:

>**THINGIVERSE**
* [**Piezas 3D**](https://www.thingiverse.com/thing:4805867/files)
  * **PCB_Mount_Frame** x1
  * **Bottom_Mount** x1
  * **M6_Rod_x_4** x4
  * **Top_Cover__for_Solar_Panel_Mount** x1
  * **Middle_Rings_x_12** x12
  * **Bottom_Plate** x1
  * **Screen_Top_Cover** x1

En nuestro caso el archivo de thingiverse es **.STL** por lo cual no es compatible con nuestra impresora 3D para ello hemos descargado un software libre llamado **Ultimaker Cura** para hacer que este proceso , este programa lo que hace es cambiar el archivo de **.STL** a .**gcode** el cual si es compatible para nuestra impresora. Descargar la versión  mas conveniente para vuestro ordenador ya sea **Windows** , **linux** o **Mac**. 

> **ULTIMAKER CURA**
* [**Pagina Web**](https://ultimaker.com/es/software/ultimaker-cura)

Una vez descargado el programa abriremos el archivo **.STL** y en la parte de abajo a la derecha donde pone **`slice`** le damos y nos pondrá el nuevo archivo **gcode** además de la duración que tardaremos en imprimir la pieza . Después de esto cogeremos un **USB** y pondremos en la impresora .
Nos saldrá un menú como este en nuestra impresora al encenderla ,le daremos a **`Print`** y elegiremos el archivo que queramos imprimir.

![](https://raw.githubusercontent.com/wgcv/RAWR-TFT-Firmware-Artillery3D/docs/img/readme-statusscreen2.jpg)

Una vez impresas todas  las piezas las montaremos hasta tener este resultado:
Para la parte superior de la estación pondremos la placa solar en la parte superior y la pegaremos con silicona , también pegaremos en el la parte superior el chip **`GY1145`** .

![](https://content.instructables.com/ORIG/F69/A4DQ/KNG1C24N/F69A4DQKNG1C24N.jpg?auto=webp&frame=1&width=300&height=370&fit=bounds&md=352c8ed63f35b84d831084b5c881088b)
![](https://content.instructables.com/ORIG/FSM/EF5L/KMJ66N80/FSMEF5LKMJ66N80.jpg?auto=webp&frame=1&width=364&height=400&fit=bounds&md=67eb137b64ccd5b2920f499085a050e6)
![](https://content.instructables.com/ORIG/FWQ/CMIU/KMJ66M4D/FWQCMIUKMJ66M4D.jpg?auto=webp&frame=1&width=350&height=350&fit=bounds&md=a5bdcd12eaaab64c00c07865274fc026)

***

## PROGRAMA ARDUINO

Para el programar de esta estación meteorológica hemos utilizado un programa de software libre llamado Arduino . Para que el  **`ESP32 Dev Kit V1`**  funcione correctamente vamos a tener que instalar varias librerías.

>**ARDUINO**

* [**Pagina Web**](https://www.arduino.cc/en/software)

Para descargar librerías iremos a los enlaces de abajo y donde pone **CODE** haremos click y descargaremos el archivo **`.ZIP`**
![](https://tutorialesgeeks.com/wp-content/uploads/2021/06/1624025504_840_Como-descargar-archivos-y-ver-codigo-desde-GitHub.png)

>**LIBRERIAS**
* [**ESP32**](https://github.com/espressif/arduino-esp32)
* [**BME280**](https://github.com/finitespace/BME280)
* [**Adafruit**](https://github.com/adafruit/Adafruit_SI1145_Library)
* [**BH1750**](https://github.com/claws/BH1750)
* [**One Wire**](https://github.com/PaulStoffregen/OneWire)
* [**Dallas Temperature**](https://github.com/milesburton/Arduino-Temperature-Control-Library)

Una vez descargada la librería **`.ZIP`**  abriremos Arduino y nos iremos al apartado de programa , dentro de este seleccionaremos incluir librería y de daremos click en añadir librerías .zip como se puede ver en la imagen de abajo. Se nos abrirá una ventana le daremos a **`este equipo`** y luego a **`descargas`** y seleccionamos nuestro archivo **`.ZIP`** para poder instalarlo . 

![](https://programarfacil.com/wp-content/uploads/2018/04/7-2-16.png)
![](https://programarfacil.com/wp-content/uploads/2018/04/7-2-17.png)

Después de esto faltaría añadir un gestor de tarjetas para esto nos iremos a **`archivo`** y dentro seleccionaremos la opción de **`preferencias`** 
 , también si se prefiere se puede usar el comando **`Ctrl+Coma`**  . Una vez echo esto donde pone gestor de tarjetas añadiremos el enlace **URL** y le daremos al **`ok`** .

> **GESTOR DE TARJETAS**
* [**ESP32**](https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json)

![](https://www.esploradores.com/wp-content/uploads/2016/09/2-2-1024x496.png)

***

**`Programa de Arduino Estación Meteorológica`** [**Github**](https://github.com/V1c7hor/Estacion-Meteorologica/blob/main/Weather_Station_VA.ino)

Seguidamente de descargar el programa vamos a **`herramientas`** y nos aseguramos de que la placa es la **`ESP32 Dev Module`**
***
![](https://www.prometec.net/wp-content/uploads/2018/02/arduino-ide.png)

Luego de hacer este paso dentro del código de Arduino insertaremos tanto nuestro **Wifi** nombre y contraseña y nuestro **`Write API key`** que se explicara como sacar ese codigo en el apartado de la conexión Thingspeak . 
  
![foto](https://github.com/V1c7hor/Estacion-Meteorologica/blob/main/arduino%20captura.png?raw=true)

***

## CONEXION CON THINGSPEAK

Para este paso nos crearemos nuestra cuenta en thingspeak . Después de crear la cuenta nos iremos a **`channel`** y dentro seleccionaremos **`Mychannel`** , aquí crearemos nuestros fields en los que pondremos las caracteristicas de cada sensor del 1 al 8 como se muestra debajo.

>**THINGSPEAK**
* [**Pagina Web**](https://thingspeak.com/) 

![](https://inwfile.com/s-fu/mhzeyl.jpg)

En la que tendremos que poner los siguientes datos :

**1. Temperature**
 
**2. Humidity**

**3. Pressure**
   
**4. UV Index** 

**5. Wind Speed**

**6. Wind Direction**

**7. Rain Fall** 

**8. Battery Voltage**

Una vez echo esto iremos arriba al apartado **`API KeY`** y copiaremos el **`Write API key`** para luego ponerlo en el programa de Arduino y así hacer la comunicación.

![](https://github.com/V1c7hor/Estacion-Meteorologica/blob/main/estacion%20mm.JPG?raw=true)

Con esto ya estaría funcional nuestra estación meteorológica.

***
