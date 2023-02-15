# AHOTS SYNTESIZER

![](https://github.com/ABICoop/Ahots-Syntesizer/blob/main/portada.png?raw=true)

## Ahots sintetizagailu bat sortzeko jarraitu behar diren pausoak.
Proiektu honetan ikasiko degu nola sortu ahots eta teklatuz modulatutako ahots sintetizagailu bat. Teensy 3.2 eta Teensy 4.0 hardware-a erabiliz lortuko dugu sintetizagailua martxan jartzea.

Ahots sintetizagailu bat sortzearen ideia etorri zen etorkizunerako lan pentsatze moduan. Nola pertsona batzuek lan egiten dute soinuak sortzez eta sintetizadoreekin aldatzeaz. Nori ez zaio inoiz etorri burura DJ modukoa izan nahi zuela? Proiektu honekin zure lehenengo pausuak eman ahal izango dituzu musika elektronikaren munduan oso kostu gutxian eta errestasun askorekin.

Martxan jarri ahal izateko gure ahots sintetizagailua, hurrengo material behar dira:

***

> **TXIPAK**                     
* [INA217](https://www.amazon.es/Reland-Sun-INA217P-INA217-INA217AIP/dp/B09M3473CX/ref=sr_1_2?__mk_es_ES=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=1EB6WGADDAC3R&keywords=ina217&qid=1676304989&sprefix=ina217%2Caps%2C91&sr=8-2) 
* [NE5534P](https://www.amazon.es/HUABAN-Amplificador-operativo-NE5534-unidades/dp/B0BGKPV8YF/ref=sr_1_1?__mk_es_ES=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=AB7LONQZ8L7R&keywords=ne5534&qid=1676305036&sprefix=ne5534%2Caps%2C90&sr=8-1)

***

> **ERRESISTENTZIAK**
* **100 KΩ**  x3
* **220 Ω**  x2
* **2K2 Ω**  x2
* **1 KΩ**  x2
* **100 Ω**  x1
* **10 KΩ**  x2
* **220 Ω**  x2
* **36 KΩ**  x2

***

> **KONDENTSADOREAK**

* **10 uF**  x2
* **1 nF**  x1
* **10 nF**  x2
* **47 nF**  x1

***

> **POTENTZIOAMETROAK ETA DESLIZAGAILUAK**

* **10 KΩ**  x8 (Potentziometro)
* **10 KΩ**  x4 (Deslizagailu)
* **22 KΩ**  x1 (Potentziometro)
* **5 KΩ**  x1 (Potentziometro)

***

> **KOMPONENTEAK**
* [Arduino kable ar/eme](https://www.amazon.com/DEPEPE-2-54mm-Headers-Arduino-Prototype/dp/B074HVBTZ4?dchild=1&keywords=female+header&qid=1614277638&sr=8-3&linkCode=sl1&tag=opegreene-20&linkId=75c0eb8c0478cfef148c03a78898a051&language=en_US&ref_=as_li_ss_tl)
* [Arduino konektoreak](https://www.amazon.com/Elegoo-EL-CP-004-Multicolored-Breadboard-arduino/dp/B01EV70C78?crid=2TGFZ04R0CTBC&dchild=1&keywords=jumper+wires+female+to+male&qid=1616433451&sprefix=jumper+wire,aps,426&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEyU1IwMjFYUUQzQTEwJmVuY3J5cHRlZElkPUEwNjY4NjU2RzRDWkE1QVFHMFdSJmVuY3J5cHRlZEFkSWQ9QTA5NDUzMjExRUtQVk9KOTU5MVg5JndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ%3D%3D&linkCode=sl1&tag=opegreene-20&linkId=2b274fdd7e99e5950ab9fd82304d5d3c&language=en_US&ref_=as_li_ss_tl)
* [Switch](https://www.amazon.es/Aussel-posiciones-interruptor-palanca-Arduino/dp/B077D9FRGL/ref=sr_1_5?keywords=switch+arduino&qid=1676486772&sprefix=switch+ard%2Caps%2C96&sr=8-5)

***

> **HERRAMIENTAK**
* [Soldatzeko makina](https://www.google.com/shopping/product/5042715519988754151?q=estacion+de+soldadura&prds=epd:17283412033935127216,eto:17283412033935127216_0,rsk:PC_3058408035792851722&sa=X&ved=0ahUKEwi769iqtIH2AhUGSfEDHTTRCMsQ9pwGCAU)
* [Kortanteak edo alikateak](https://www.google.com/shopping/product/1?q=cortante&prds=epd:8859887341376829913,eto:8859887341376829913_0,pid:8859887341376829913&sa=X&ved=0ahUKEwjgp7jYtIH2AhWxRPEDHVwxBD8Q9pwGCAc)
* [Estañua](https://es.rs-online.com/web/p/estano-e-hilo-de-soldar/1047189?cm_mmc=ES-PLA-DS3A-_-google-_-CSS_ES_ES_Herramienta_El%C3%A9ctrica_y_Soldadura_Whoop+(2)-_-(ES:Whoop!)+Esta%C3%B1o+e+Hilo+de+Soldar-_-1047189&matchtype=&pla-305619873070&gclid=Cj0KCQiAu62QBhC7ARIsALXijXTX-TMjnpBkwoCMX4DuGWD5Kg1hb9i8SoM2XOcIjuM4Jp8HE7iA6VYaAvr2EALw_wcB&gclsrc=aw.ds) 
* [Polimetroa](https://www.amazon.es/KAIWEETS-Mult%C3%ADmetro-Continuidad-Resistencia-Miniestuche/dp/B08CX9W7G3/ref=sr_1_1_sspa?__mk_es_ES=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=265JQZ45KZGYR&keywords=polimetro&qid=1676486961&sprefix=polimetro%2Caps%2C98&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)

***
## AHOTS SINTETIZAGAILUAREN MUNTAIA
Sintentizagailu hau sortu ahal izateko, **PCB** bat diseinatu degu eta goian aipatu diren komponente guztiak soldatu beharko dira.

bai `Proteus 8` bai `Arduino`, fitxategiak deskargatzeko egongo dira. Muntaketa eta diseinurako, irudi honetan oinarritu gara, konexioak nola antolatuta dauden ikus baitaiteke.

>**PROTEUS**
* [**AHOTS SINTETIZAGAILUA PCB**](https://github.com/ABICoop/Ahots-Syntesizer/tree/main/PCB-design)

>**ARDUINO**
* [**AHOTS SINTETIZAGAILUA PROGRAMA**](https://github.com/ABICoop/Ahots-Syntesizer/tree/main/Arduino-code)

![](https://github.com/ABICoop/Ahots-Syntesizer/blob/main/images/eskema-orokorra.jpg)

Komponenteen kokaketa **PCB** orokorraren diseinuan.

![](https://github.com/ABICoop/Ahots-Syntesizer/blob/main/PCB-design/pcb-design.PNG?raw=true)

Komponenteen kokaketa mikroaren **PCB** diseinuan.

![](https://github.com/ABICoop/Ahots-Syntesizer/blob/main/PCB-design/mikro-PCB.PNG)
***
Zirkuitua estaltzeko **8 mm** inguruko metakrilatoa erabili dugu. Karkasaren diseinua **Adobe Ilustrator** aplikazioan egin zen eta hurrengo programa/neurriak atera ziren:

* [**Erabilitako Adobe Ilustrator programa**](https://github.com/ABICoop/Ahots-Syntesizer/blob/main/METAKRILATO.ai)

Egindako Adobe Ilustratorraren argazkia:

![](https://github.com/ABICoop/Ahots-Syntesizer/blob/main/images/Adobe-karkasa.PNG)

>**METAKRILATOREAREN NEURRIAK**
  * **9 x 18 cm** x2
  * **8 x 27 cm** x2
  * **27 x 18 cm** x2

Gure kasuan, Adobe Ilustratorrek ematen zigun artxiboa .**AI**, bateragarria zen mozteko erabiltzen zen makinarekin. Ebaketak egiteko, laser mozgailu bat erabili genuen, Tabakalerako kultur zentroak eskaini ziguna.

Tabakaleran erabilitako makinaren argazkia:

![](https://media.discordapp.net/attachments/1074728580958924951/1075479417121415339/laser-makina.png?width=946&height=640)

Hau ez da gure prototipoa baina etorkizunean guk egindakoaren argazkia jarriko dugu.

![](https://media.discordapp.net/attachments/1074728580958924951/1075481188766056478/metakrilatoa.jpg)
***

## ARDUINO PROGRAMA

Ahots sintetizadore honetarako software libre bat erabili degu, Arduino deituta. **`Teensyduino`** libreriak sartu behar izan diogu Teensy hardwarea funtzionatu ahal izateko.

>**ARDUINO**

* [**Web Orria**](https://www.arduino.cc/en/software)

Liburutegiak deskargatu ahal izateko hurrengo linkean sartu behar da eta gure ordenagailuaren arabera deskargatuko degu **Teensyduino installer**.
![](https://github.com/ABICoop/Ahots-Syntesizer/blob/main/images/Teensyduino-installer.png)

>**LIBRERIAK**
* [**TEENSYDUINO**](https://www.pjrc.com/teensy/td_download.html)

Behin gure bertsioa deskargatuta daukagula, `Teensyduino Installerrak` esaten digun pausuak jarraitu behar dira. Behin pausuak bukatu ditugula horrelako pantaila bat agertu beharko luke.

![](https://github.com/ABICoop/Ahots-Syntesizer/blob/main/images/teensyduino_installer_1.png)
![](https://github.com/ABICoop/Ahots-Syntesizer/blob/main/images/teensyduino_installer_2.png)

Ondoren, txartelen kudeatzaile bat gehitzea falta da. Horretarako, **`archivo`** atalean sartu gera eta barruan **`preferencias`** sakatuko degu 
 , nahi bada **`Ctrl+Coma`** komandoa erabili ahal da errazago. Behin hori eginda **`gestor de tarjetas`** lekuan gure **`URL`** jarriko degu eta **`ok`** sakatu.

> **TXARTELA KUDEAKETA**
* [**TEENSY TXARTELA**](https://www.pjrc.com/teensy/package_teensy_index.json)

![](https://www.esploradores.com/wp-content/uploads/2016/09/2-2-1024x496.png)

***

**`AHOTS SINTETIZAGAILUA ARDUINO PROGRAMA`** [**Github**](https://github.com/ABICoop/Ahots-Syntesizer/tree/main/Arduino-code)

Programa deskargatu eta gero komprobatzen degu **`herramientas`** atalean, gure plaka **`Teensy 4.0`** dela.
***
![](https://github.com/ABICoop/Ahots-Syntesizer/blob/main/images/plaka-aukeratu.png)

Gure proiektuak audioarekin zerikusia daukanez Teensy Audio Design Tool-a erabili behar izan dugu. Teensy 4.1 gainean Audio Shield bat gehitu diogunez behar-beharrezkoa den modulo bat gehitu behar diogu gure programari beti, modulo hau Sgtl5000 da non Audio Shield-a kontrolatzen duen. 

Bestalde honez gain beste modulo asko erabil ditzazkegu, honekin batera modulo bakoitzaren gainean klick egiten dugunero web orriaren eskubi aldean zutabe bat irekiko zaigu aukeratutako moduluaren funtzio eta adibideekin, hau oso erabilgarria da gero proiektuan ze parametro aldatu behar ditugun jakiteko. 

![](https://media.discordapp.net/attachments/1074728580958924951/1075486023347339334/image.png?width=960&height=484)

Ondoren ikus dezakezuen argazkia gure proiektuko Audio Design Tool-a da.

![](https://media.discordapp.net/attachments/1074728580958924951/1075482773105684630/image.png?width=960&height=485)
![](https://media.discordapp.net/attachments/1074728580958924951/1075483044481339473/image.png?width=960&height=481)

Textu honen bitartez gure proiektuaren programak nola funtzionatzen duen azalduko dizuegu. Eman genietuen lehen pausuak VCO bat gehitzea izan zen, **VCO = "Voltage Controlled Oscilator"** Sistesi kentzaile bidez sorturikako soinu bat da non guk aukeratu dezakegun uhin mota. `VCO-ren Frekuentzia knob_A4 potentziometro` bitartez kontrolatzen dugu. 

Hau egin ondoren LFO zatiarekin sartu ginen **LFO= "Low Frequency Oscilator"** Seinale sortzaile moduan erabiltzenda eta aurrekoa modulatzeko balio du, honen `Frekuentzi eta Anplitudearen kontrolak knob_A1 eta knob_A2 potentziometroekin` kontrola dezakegu. Behin VCO LFO-kin batera modulatzean 12 noten kontrola edukitzea pentsatu genuen eta hau egiteko switch batez lagundu ginen, hau da, switch-a alde batean dagoenean lehen esanda bezala funtzonatzen du, aldiz beste aldera eramatean **knob_A5 bitartez VCO-ren frekuentzia** `12 nota desberdinetan entzun dezakegu potentziometroaren 1023/12 eginez`. 

VCF-ren txanda zen **VCF= "Voltage Controlled Filter"** sarreran lortzen dugun soinuaren tentsioz kontrolaturiko `filtroa honetarako knob_A0` potentziometroa erabili genuen, non `knob_A2 potentziometroaren arabera filtratu genezaken`. 

**Midi teklatuari dagokionez "USBHost_t36.h"** libreria erabili genuen USBmidi bitartez konektatzen zelako gure teklatua. Hemen emandako lehen pausua notaren balioa (note) frekuentzi bihurtzea zen, horretarako   
**"float Freq = 440.0 * powf(2.0, (float)(note - 69) * 0.08333333);
globalFreq = Freq;** 
erabili genuen ondoren bariable global batera pasatzeko. Teklatuarekin egin beharreko hurrengo pausoa honen bolumenaren kontrola zen envelope izeneko filtro batez **ADSR= " Attack Decay Sustain Release"**. Teklatuaren bi parametroak kontuan izanik, **"myNoteOn" eta "myNoteOff"** Attack Decay nota hastean sartzea izan zen eta aldiz Sustain Release nota bukaeran musikalki zentzu hori duelako, lehen bezala parametro bakoitza potentziometro batekin kontrolatuz.
***
