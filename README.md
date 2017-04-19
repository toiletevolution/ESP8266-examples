# Toilet Evolition ESP8266 Examples

このリポジトリは Toilet Evolution サーバーへ接続してトイレの空き状況を監視するクライアントデバイスのサンプルプログラム集です。

https://toiletevolution.space

## simple_toiletevolution

人感センサーとESP8266を使ったシンプルな構成例です。

1部屋に1個室で、個室ドアが常に閉じているような場合を想定しています。
常に閉じている（入退室のみ開閉する）ドアの場合、開閉センサーを用いることができないので、人感センサーを利用します。

実際に利用したデバイス：

- [ESPr Developer](https://www.switch-science.com/catalog/2500/)
- [PIRモーションセンサ](https://www.switch-science.com/catalog/2145/)
- USB電源ケーブル

接続図サンプル：

[Fritzingファイル](simple_toiletevolution.fzz)

## _2door-1pir-sample

開閉センサー2つと人感センサー1つ、ESP8266を使った3個室を測定する構成例です。

1部屋に3個室で、開閉式のドアを持つ2つの個室と、個室ドアが常に閉じている個室が1つのような場合を想定しています。
常に閉じている（入退室のみ開閉する）ドアの場合、開閉センサーを用いることができないので、人感センサーを利用します。
開閉式のドアの場合は、開閉センサーを利用します。

実際に利用したデバイス：

- [ESPr Developer](https://www.switch-science.com/catalog/2500/)
- [PIRモーションセンサ](https://www.switch-science.com/catalog/2145/)
- [ケース入りリードスイッチ（磁石付セット）](http://akizukidenshi.com/catalog/g/gP-04025/)
- USB電源ケーブル

接続図サンプル：

[Fritzingファイル](_2door-1pir-sample.fzz)

## サンプルコード：

各サンプルディレクトリの config.h.example を config.h にコピーして、利用環境に応じた値を設定します。
プログラムの書き込みには Arduino IDE が必要です。

ESPr Developer を Arduino 化するための記事は以下の参考サイトを参照ください。

- [Arduino IDEで開発する方法](http://trac.switch-science.com/wiki/esp_dev_arduino_ide)
- [ESP-WROOM-02開発ボードの使い方をザッと紹介](https://www.mgo-tec.com/blog-entry-ss-wroom-howto01.html)
