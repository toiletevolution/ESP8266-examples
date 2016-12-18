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

サンプルコード：

simple_toiletevolution ディレクトリの config.h.example を config.h にコピーして、利用環境に応じた値を設定します。
プログラムの書き込みには Arduino IDE が必要です。

ESPr Developer を Arduino 化するための記事は以下の参考サイトを参照ください。

- [Arduino IDEで開発する方法](http://trac.switch-science.com/wiki/esp_dev_arduino_ide)
- [ESP-WROOM-02開発ボードの使い方をザッと紹介](https://www.mgo-tec.com/blog-entry-ss-wroom-howto01.html)
