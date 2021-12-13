# robosys2021_device_driver
 - RaspberryPi4を使用しステッピングモーターを制御するデバイスドライバを作成しました。
 ## 動作環境
 - Ubuntu 20.04.3 LTS
 - RaspberryPi4
 ## 使用したもの
 - RaspberryPi4
 - 電源用USBケーブル　TypeC
 - ジャンパ線
 - ステッピングモーター(Quimat Nema 17)
 - ステッピングモーター制御IC(A4988)
 ## 回路・配線図
 ![image](https://user-images.githubusercontent.com/76610691/145844705-f6cec416-b1f7-42e3-a58b-fd348eca9e08.png)
 
 ![20211213_193723](https://user-images.githubusercontent.com/76610691/145852927-78086c1d-b005-4771-b367-2d71ebd48efe.jpg)
 ## 実行方法
 ### セットアップ
 ```
  $ git clone https://github.com/KoheiYanagisawa/robosys2021_device_driver.git
 
  $ cd robosys2021_device_driver
 
  $ ./setup.bash
 ```
 
 ### インストール
 ```
  $ make
 
  $ sudo insmod stepper_motor.ko
 ```
  
 ### アンインストール・デバイスファイルの削除
 ```
  $ sudo rmmod stepper_motor
  
  $ make clean
 ```
  
 ### 実行
 - 書き込み権限付与
 ```
  $ sudo chmod 666 /dev/stepper_motor0
 ```
 
 - 正転
 ```
  $ echo  > /dev/stepper_motor0
 ```
 
 - 逆転
 ```
  $ echo 0 > /dev/stepper_motor0
 ```
 ## 実際に動かした様子
 https://youtu.be/SwtZJ-ZUWlo
