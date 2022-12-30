# Szklarnia-ESP8266-Greenhouse-ESP8266-ESP8266
Projekt szklarni ESP8266 z stroną www stworzoną przez Wi-Fi. / Project of the ESP8266 greenhouse with a website created by Wi-Fi. /ESP8266 温室プロジェクト。Wi-Fi 経由で接続されたウェブサイト。

*Read this in other languages: [Polish](README.md), [English]( README.eng.md)*

## Spis treści
- [Opis idei/celu](#Opis-idei/celu)
- [Schematy działania](#Schematy-działania)
- [Szklarnia](#Szklarnia)
- [Ewaluacja](#Ewaluacja)

      
## Opis idei/celu
*KOMPONENTY*

Projekt zostanie stworzony przy pomocy modułów. Zostaną do tego celu użyte :
- MODUŁ WIFI ESP8266,
- Arduino Uno
- Czujnik temperatury i wilgotności - DHT11,
- Moduł czujnik wilgotności gleby,
- Koszyk baterii 2XAA, 3xAA, 4xAA.
- Wentylator LD3007MS,
- Mini pompa wodna z kablem USB DC 5V 2-3L/Min,
- Czujnik poziomu wody,
- Koszyk baterii 3XAA R6,
- Moduł Robogeek S0022 detektor wody,
- Czujnik drgań,
- Dioda.

*OPIS*
>Projekt posiadał moduł WIFI ESP8266 do sterowania komponentami, czujnik temperatury                   i  wilgotności do badania temperatury i poziomu wilgotności na terenie szklarni, czujnik drgania           i wibracji w razie przesunięcia mechanicznego mobilnej szklarni podłączony jest on do Arduino Uno   i osobno umieszczony na dole szklarni. Arduino Uno podpięte jest do koszyka baterii 3xAA.. Przesunięcie jest sygnalizowane zaświeceniem się diody. Moduł wilgotności gleby do badania wody w glebie potrzebnej do monitorowania nawodnienia gleby. Cała elektronika zostanie zasilona koszykiem baterii 2xAA. Projekt zawiera pompę wodną do nawadniania i wentylator podpięty do osobnego koszyka baterii 4xAA. Czujnik poziomu deszczu znajduję się na górze szklarni nad pojemnikiem z wodą. W pojemniku również umieszczony jest czujnik poziomu wody. W celu odczytu danych z sensorów, włączeniu pompy i wentylatora została napisana strona internetowa.

---

## Schematy działania

![obraz](https://user-images.githubusercontent.com/108947060/209952018-98f2194f-009c-4f7c-85f8-09e81af9380c.png)

![obraz](https://user-images.githubusercontent.com/108947060/209952053-f9221b98-d4b9-46f2-b5ae-0a0130e04454.png)

---

## Opis działania

>Szklarnia posiada czujniki, które są programowane        i czytane przez ESP8266. Została stworzona strona internetowa pokazująca: temperaturę w *C                i wilgotność powietrza w %( DHT11), wilgotność gleby w %( LM393), poziom wody w pojemniku na deszczówkę ( Czujnik poziomu wody), sensor deszczu pokazująca informację czy pada czy nie        ( Sensor deszczu), pompę i wiatrak uruchamiane na guzik na stronie. Osobno został stworzony czujnik wibracji na arduino umieszczony na dole szklarni. 

---

## Szklarnia

![obraz](https://user-images.githubusercontent.com/108947060/209952455-4cd262cb-840c-497a-8e25-d0444e99de38.png)

![obraz](https://user-images.githubusercontent.com/108947060/209952545-e6c79d9a-e504-46f8-86cc-14d01cc2b2db.png)

---

## Ewaluacja
1. Tematem projektu było stworzenie szklarni monitorowanej z użyciem ESP8266 i pomocniczych sensorów.
2. Szklarnia została stworzona z użyciem wszystkich sensorów z opisu projektu włącznie z wiatrakiem i pompą pomocniczą do opieki nad rośliną.
3. Zrealizowano 95% założonych celów szklarni ,włącznie ze stworzeniem możliwości przez Wi-fi odczytu danych z sensorów
4. Zasilanie szklarni zostało zmienione z wcześniejszymi założeniami na 3 koszyki baterii, jeden osobny do pompy i wiatraka, jeden do ESP8266 i jeden do Arduino Uno.
5. Szklarnia spełnia warunek przenoszalności, jest możliwość zmieniania jej położenia bez problemu (z tolerancją błędu).
6. Szklarnia przeszła 3 testy użytku spięciowej, w celu uniknięcia spalenia sensorów z powodu obciążenia.

---

!!! KOD NIE ZAWIERA BIBLIOTEK I PRZYPISAŃ DO PINÓW !!!
