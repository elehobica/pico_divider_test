# Raspberry Pi Pico divider Test

## Overview
Test code to asynchronous access to SIO divider through C++ code.
To check 64bit division in main code with float division in interrupt code.

## Supported Board and Peripheral Devices
* Raspberry Pi Pico

## How to build
* See ["Getting started with Raspberry Pi Pico"](https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf)
* Build is confirmed only in Developer Command Prompt for VS 2019 and Visual Studio Code on Windows enviroment
* Put "pico-sdk", "pico-examples", "pico-extras" and "pico-playground" on the same level with this project folder.
```
> git clone -b master https://github.com/raspberrypi/pico-sdk.git
> cd pico-sdk
> git submodule update -i
> cd ..
> git clone -b master https://github.com/raspberrypi/pico-examples.git
> 
> git clone https://github.com/raspberrypi/pico-extras.git
> cd pico-extras
> git submodule update -i
> cd ..
> git clone https://github.com/raspberrypi/pico-playground.git
> 
> git clone -b main https://github.com/elehobica/pico_divider_test.git
```
* Lanuch "Developer Command Prompt for VS 2019"
```
> cd pico_divider_test
> mkdir build
> cd build
> cmake -G "NMake Makefiles" ..
> nmake
```
* Put "pico_divider_test.uf2" on RPI-RP2 drive

## Failure example
* pico-sdk: 1.2.0 (bfcbefafc5d2a210551a4d9d80b4303d4ae0adf7)
```
START
ERROR [calc_64bit][8838] samplesPlayed = 213319408, millis_ref = 4837175, millis = 2369891
ERROR [calc_64bit][31437] samplesPlayed = 216528704, millis_ref = 4909948, millis = 4879805
ERROR [calc_64bit][56537] samplesPlayed = 305666656, millis_ref = 6931217, millis = 6906248
ERROR [calc_64bit][82250] samplesPlayed = 363115520, millis_ref = 8233912, millis = 4068260
ERROR [calc_64bit][89880] samplesPlayed = 315003872, millis_ref = 7142945, millis = 3571472
ERROR [calc_64bit][100252] samplesPlayed = 265318736, millis_ref = 6016298, millis = 5990036
ERROR [calc_64bit][112126] samplesPlayed = 234576144, millis_ref = 5319187, millis = 2659593
ERROR [calc_64bit][133160] samplesPlayed = 339558464, millis_ref = 7699739, millis = 3801173
ERROR [calc_64bit][153979] samplesPlayed = 304004096, millis_ref = 6893517, millis = 3446758
ERROR [calc_64bit][156126] samplesPlayed = 185244816, millis_ref = 4200563, millis = 2100281
ERROR [calc_64bit][189172] samplesPlayed = 349184704, millis_ref = 7918021, millis = 3959010
ERROR [calc_64bit][194261] samplesPlayed = 145804080, millis_ref = 3306215, millis = 3291507
ERROR [calc_64bit][206908] samplesPlayed = 56640140, millis_ref = 1284357, millis = 593482
ERROR [calc_64bit][211865] samplesPlayed = 102926840, millis_ref = 2333942, millis = 2313850
ERROR [calc_64bit][213062] samplesPlayed = 66043320, millis_ref = 1497581, millis = 748790
ERROR [calc_64bit][228708] samplesPlayed = 38921512, millis_ref = 882574, millis = 441286
ERROR [calc_64bit][237550] samplesPlayed = 329126944, millis_ref = 7463196, millis = 3682902
ERROR [calc_64bit][240116] samplesPlayed = 85194584, millis_ref = 1931850, millis = 965924
ERROR [calc_64bit][249735] samplesPlayed = 142914032, millis_ref = 3240681, millis = 1620340
ERROR [calc_64bit][253457] samplesPlayed = 256888848, millis_ref = 5825144, millis = 2912571
ERROR [calc_64bit][274650] samplesPlayed = 357888960, millis_ref = 8115396, millis = 8088161
ERROR [calc_64bit][278183] samplesPlayed = 191734576, millis_ref = 4347723, millis = 2173861
ERROR [calc_64bit][313968] samplesPlayed = 284597120, millis_ref = 6453450, millis = 6437988
ERROR [calc_64bit][322355] samplesPlayed = 105977456, millis_ref = 2403117, millis = 2381206
ERROR [calc_64bit][332303] samplesPlayed = 338126336, millis_ref = 7667264, millis = 7634719
ERROR [calc_64bit][339125] samplesPlayed = 217424944, millis_ref = 4930271, millis = 4922735
ERROR [calc_64bit][366179] samplesPlayed = 207753680, millis_ref = 4710968, millis = 4682011
ERROR [calc_64bit][370858] samplesPlayed = 242991120, millis_ref = 5510003, millis = 2755001
ERROR [calc_64bit][406654] samplesPlayed = 325574560, millis_ref = 7382643, millis = 7361337
ERROR [calc_64bit][437605] samplesPlayed = 91487872, millis_ref = 2074555, millis = 988581
ERROR [calc_64bit][457126] samplesPlayed = 277004320, millis_ref = 6281277, millis = 3091942
ERROR [calc_64bit][462011] samplesPlayed = 14922866, millis_ref = 338387, millis = 333033
ERROR [calc_64bit][485654] samplesPlayed = 268062816, millis_ref = 6078522, millis = 6053916
ERROR [calc_64bit][514862] samplesPlayed = 67469208, millis_ref = 1529914, millis = 764957
ERROR [calc_64bit][517673] samplesPlayed = 178204608, millis_ref = 4040921, millis = 4019308
ERROR [calc_64bit][531498] samplesPlayed = 264454640, millis_ref = 5996704, millis = 5980239
ERROR [calc_64bit][536009] samplesPlayed = 300052992, millis_ref = 6803923, millis = 3353265
ERROR [calc_64bit][543609] samplesPlayed = 104305184, millis_ref = 2365197, millis = 2362246
ERROR [calc_64bit][550049] samplesPlayed = 187016224, millis_ref = 4240731, millis = 2120365
ERROR [calc_64bit][559229] samplesPlayed = 223811984, millis_ref = 5075102, millis = 5060686
ERROR [calc_64bit][563131] samplesPlayed = 101522872, millis_ref = 2302106, millis = 2297932
ERROR [calc_64bit][595422] samplesPlayed = 90197816, millis_ref = 2045302, millis = 1022650
ERROR [calc_64bit][632770] samplesPlayed = 127618960, millis_ref = 2893854, millis = 2888718
ERROR [calc_64bit][709814] samplesPlayed = 63387972, millis_ref = 1437369, millis = 1406812
ERROR [calc_64bit][715482] samplesPlayed = 320777248, millis_ref = 7273861, millis = 3636930
ERROR [calc_64bit][729894] samplesPlayed = 67805024, millis_ref = 1537529, millis = 768764
ERROR [calc_64bit][738920] samplesPlayed = 10640051, millis_ref = 241271, millis = 71939
ERROR [calc_64bit][755383] samplesPlayed = 271235072, millis_ref = 6150455, millis = 3026531
ERROR [calc_64bit][760666] samplesPlayed = 301559456, millis_ref = 6838083, millis = 3419041
ERROR [calc_64bit][766695] samplesPlayed = 351432800, millis_ref = 7968998, millis = 7949426
ERROR [calc_64bit][775461] samplesPlayed = 205658928, millis_ref = 4663468, millis = 2331733
ERROR [calc_64bit][816729] samplesPlayed = 146718848, millis_ref = 3326958, millis = 1663479
ERROR [calc_64bit][819465] samplesPlayed = 221268704, millis_ref = 5017431, millis = 2508715
ERROR [calc_64bit][825123] samplesPlayed = 229035408, millis_ref = 5193547, millis = 5185445
ERROR [calc_64bit][849034] samplesPlayed = 329090016, millis_ref = 7462359, millis = 7433963
ERROR [calc_64bit][856837] samplesPlayed = 138222224, millis_ref = 3134291, millis = 3107241
ERROR [calc_64bit][864836] samplesPlayed = 175641120, millis_ref = 3982792, millis = 3957475
ERROR [calc_64bit][908031] samplesPlayed = 158463952, millis_ref = 3593287, millis = 3566115
ERROR [calc_64bit][910397] samplesPlayed = 325259680, millis_ref = 7375503, millis = 7357767
ERROR [calc_64bit][922495] samplesPlayed = 324032512, millis_ref = 7347676, millis = 7343854
ERROR [calc_64bit][924665] samplesPlayed = 221076912, millis_ref = 5013082, millis = 4996908
ERROR [calc_64bit][956361] samplesPlayed = 345625088, millis_ref = 7837304, millis = 3869956
ERROR [calc_64bit][962410] samplesPlayed = 260048128, millis_ref = 5896783, millis = 2899695
ERROR [calc_64bit][974317] samplesPlayed = 342733120, millis_ref = 7771726, millis = 7752487
ERROR [calc_64bit][977839] samplesPlayed = 221044720, millis_ref = 5012352, millis = 2506175
ERROR [calc_64bit][983882] samplesPlayed = 350303936, millis_ref = 7943400, millis = 7936627
ERROR [calc_64bit][994196] samplesPlayed = 287421248, millis_ref = 6517489, millis = 6502776
ERROR [calc_64bit][996169] samplesPlayed = 40332404, millis_ref = 914567, millis = 408587
ERROR [calc_64bit][1012006] samplesPlayed = 30615586, millis_ref = 694231, millis = 674795
ERROR [calc_64bit][1054067] samplesPlayed = 284821472, millis_ref = 6458537, millis = 6440532
ERROR [calc_64bit][1060872] samplesPlayed = 282199680, millis_ref = 6399086, millis = 6378038
ERROR [calc_64bit][1077362] samplesPlayed = 197623200, millis_ref = 4481252, millis = 2240625
ERROR [calc_64bit][1081635] samplesPlayed = 87800320, millis_ref = 1990937, millis = 1978508
ERROR [calc_64bit][1090402] samplesPlayed = 341280896, millis_ref = 7738796, millis = 7736021
ERROR [calc_64bit][1114104] samplesPlayed = 367727488, millis_ref = 8338492, millis = 4169245
ERROR [calc_64bit][1125761] samplesPlayed = 107555000, millis_ref = 2438889, millis = 2431860
ERROR [calc_64bit][1128081] samplesPlayed = 354726240, millis_ref = 8043679, millis = 8019535
ERROR [calc_64bit][1128849] samplesPlayed = 308528032, millis_ref = 6996101, millis = 3498050
ERROR [calc_64bit][1187283] samplesPlayed = 114915728, millis_ref = 2605799, millis = 1254203
ERROR [calc_64bit][1190979] samplesPlayed = 25632904, millis_ref = 581245, millis = 552766
ERROR [calc_64bit][1197293] samplesPlayed = 22232132, millis_ref = 504130, millis = 203369
ERROR [calc_64bit][1200101] samplesPlayed = 244578064, millis_ref = 5545988, millis = 5525505
ERROR [calc_64bit][1229217] samplesPlayed = 245074368, millis_ref = 5557242, millis = 2778620
ERROR [calc_64bit][1236801] samplesPlayed = 214752176, millis_ref = 4869664, millis = 4859663
ERROR [calc_64bit][1243992] samplesPlayed = 24816128, millis_ref = 562724, millis = 543505
ERROR [calc_64bit][1256301] samplesPlayed = 317926720, millis_ref = 7209223, millis = 7209091
ERROR [calc_64bit][1309185] samplesPlayed = 229131728, millis_ref = 5195731, millis = 2597865
ERROR [calc_64bit][1322191] samplesPlayed = 102192400, millis_ref = 2317288, millis = 1158643
ERROR [calc_64bit][1340853] samplesPlayed = 78544168, millis_ref = 1781047, millis = 890523
ERROR [calc_64bit][1341495] samplesPlayed = 133871016, millis_ref = 3035624, millis = 3025139
ERROR [calc_64bit][1353347] samplesPlayed = 106933056, millis_ref = 2424786, millis = 1212392
ERROR [calc_64bit][1378229] samplesPlayed = 24274182, millis_ref = 550435, millis = 275217
ERROR [calc_64bit][1379284] samplesPlayed = 118789784, millis_ref = 2693646, millis = 2690310
ERROR [calc_64bit][1389399] samplesPlayed = 165828032, millis_ref = 3760273, millis = 1880136
ERROR [calc_64bit][1405324] samplesPlayed = 284256064, millis_ref = 6445716, millis = 6434121
ERROR [calc_64bit][1431350] samplesPlayed = 34890992, millis_ref = 791179, millis = 788805
ERROR [calc_64bit][1439981] samplesPlayed = 133704672, millis_ref = 3031852, millis = 3023253
ERROR [calc_64bit][1474375] samplesPlayed = 297512160, millis_ref = 6746308, millis = 3373153
ERROR [calc_64bit][1482556] samplesPlayed = 173756688, millis_ref = 3940061, millis = 3936110
ERROR [calc_64bit][1484109] samplesPlayed = 339122688, millis_ref = 7689857, millis = 7678784
ERROR [calc_64bit][1484309] samplesPlayed = 311366688, millis_ref = 7060469, millis = 7036410
ERROR [calc_64bit][1507591] samplesPlayed = 40442696, millis_ref = 917068, millis = 409838
ERROR [calc_64bit][1517806] samplesPlayed = 4698281, millis_ref = 106537, millis = 86036
ERROR [calc_64bit][1520084] samplesPlayed = 237176224, millis_ref = 5378146, millis = 5376048
ERROR [calc_64bit][1525889] samplesPlayed = 265203632, millis_ref = 6013688, millis = 5988731
ERROR [calc_64bit][1534255] samplesPlayed = 241174608, millis_ref = 5468812, millis = 5454149
ERROR [calc_64bit][1544758] samplesPlayed = 147532976, millis_ref = 3345419, millis = 3343877
ERROR [calc_64bit][1551572] samplesPlayed = 25202972, millis_ref = 571496, millis = 285747
ERROR [calc_64bit][1571681] samplesPlayed = 359087712, millis_ref = 8142579, millis = 8134521
ERROR [calc_64bit][1608177] samplesPlayed = 252435440, millis_ref = 5724160, millis = 2862079
ERROR [calc_64bit][1618101] samplesPlayed = 352530496, millis_ref = 7993889, millis = 7961872
dummy = -1842581252
END
```