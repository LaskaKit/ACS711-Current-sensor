# ACS711 čidlo proudu

![ACS711 čidlo proudu](https://github.com/LaskaKit/ACS711-Current-sensor/blob/main/img/ACS711_monitor.jpg)

Potřebujete měřit procházející proud vaším zařízením? Pak se podívejte na náš modul s čidlem proudu ACS711 ve verzi 31AB, který je schopen měřit proud až do 31 A. 
Nesmírnou výhodou tohoto čidla je jednoduchý výstup s přepočtem 45 mV/A, tedy jej můžete měřit běžným AD převodníkem třeba s Arduino Uno nebo ESP32. Další výhodou tohoto modulu je, že si na desce nevytváříte další úbytek kvůli měřícímu rezistoru.
A to jen díky použitému čidlu, který používá pro měření proud [hallovo čidlo](https://blog.laskarduino.cz/hallovo-cidlo-funkce-princip-pouziti/) umístěné uvnitř čipu. Díky tomu se výkon zbytečně nepálí na měřícím rezistoru. Ten by i při malé hodnotě odporu vyzazoval úbytek napětí a s tím spojený i ztrátový výkon.

## Tento modul je osazen čidlem ACS711X31AB
Výstupní napětí bez procházejícího proudu je kolem 1,7V (napájecí napětí 3,3V). To znamená, že proud můžete měřit v obou směrech. Napětí na výstupu čidla (VIOUT) je pak vyšší či nižší - podle polarity.
Převodní poměr čidla ve verzi x31AB je 45mV/1A. Tedy co 1A, to o 45mV vyšší (či nižší) napětí na výstupu (VIOUT).
Výstup je samozřejmě zatížen i šumem, v katalogovém listu je uvedena hodnota 8 mV bez filtru. Na našem modulu pro měření proudu najdete kondenzátor, který tento šum redukuje. 
Napájecí napětí čidla je od 3 do 5,5V. Hodí se tak jak Arduino Uno, tak i pro Mega či desky s ESP8266 nebo ESP32.

Abyste mohli měřit takový proud a zároveň minimalizovali ztráty na konektorech, je třeba kvalitního připojení k čidlu. Využít můžete buď svorky nebo také pokovené díry, ke kterým můžete vodiče přišroubovat. 

## Zapojení
Jako výstup pak slouží čtyřpinový hřebínek na kterém najdete napájení (3,3V) výstup z čidla (VIOUT) a také i alarmový výstup FAULT, který indikuje měřený proud mimo rozsah (nadproud).

## Příklad
Připravili jsme pro vás i [vzorový příklad - github](https://github.com/LaskaKit/ACS711-Current-sensor/tree/main/SW) použití tohoto čidla s naší vývojovou deskou [ESP32 LPkit](https://www.laskarduino.cz/laskakit-esp32-lpkit-pcb-antenna/).
V tomto příkladu nejprve změříme zprůměrovanou klidovou hodnotu výstupního napětí a poté v nekonečně smčce měříme změnu výstupní napětím s ohledem na procházející proud. 

![Výstup ACS711 v Arduino IDE](https://github.com/LaskaKit/ACS711-Current-sensor/blob/main/img/ACS711_plotter.JPG)

Měřená hodnota je vždy průměrována - tím eliminujeme jak šum ze samotného čidla, tak i šum AD převodníku. Dosahujeme tak přesnějšího měření. 

![Modul s ACS711](https://github.com/LaskaKit/ACS711-Current-sensor/blob/main/img/3.jpg)

![Modul s ACS711](https://github.com/LaskaKit/ACS711-Current-sensor/blob/main/img/5.jpg)
