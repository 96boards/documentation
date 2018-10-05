---
title: BPi96 BC95 Connect to Network
permalink: /documentation/iot/bpi96/guides/connect-network.html
---

# Command Format

| Action            | Command                 |
|:-----------------:|:-----------------------:|
| Test Command Read | ```AT+<cmd>=?```        |
| Read Command      | ```AT+<cmd>?```         |
| Set Command       | ```AT+<cmd>=p1,p2,p3``` |
| Execution Command | ```AT+<cmd>```          |

# Search for Network and Connect

1. ```AT+NBAND?``` Query Band
2. ```AT+CFUN?``` value :1
3. ```AT+CIMI``` Query IMSI number
4. ```AT+CSQ``` Query the signal strength
5. ```AT+NUESTATS``` Query module status
6. ```AT+CGATT?``` Back + CGATT: 1 indicates that the attachment is successful, with a delay of about 30s
7. ```AT+CEREG?``` Search for network status, 1 for Internet, 2 for Network
8. ```AT+CSCON?``` Query the connection status, 1 CONNECT, 0 IDLE

# Manually Configure Network

1. ```AT+CFUN=1```
2. ```AT+CIMI``` Execute CFUN = 1, wait for 4 seconds to query IMSI, if it
can be found that the card has been identified; If not, please check
the card is inserted and confirm whether it is a USIM card.
3. ```AT+NBAND?``` Query frequency band information.
4. ```AT+CEREG=1``` Set to automatically register network registration
status, when the module registered on the network, will report
URC.
4. ```AT+CGDCONT=1,“IP”,“APN”``` The APN is configured locally (or not
configured) for local access.
5. ```AT+COPS=1,2,"46000"``` Specify PLMN search, PLMN configuration.
6. ```AT+CSQ``` Query signal strength.
7. ```AT+NUESTATS``` Query module status
8. ```AT+CGATT?``` Back + CGATT: 1 indicates that the attachment is
successful, with a delay of about 30s
9. ```AT+CEREG?``` Search for network status, 1 for Internet, 2 for
Network
10. ```AT+CSCON?``` Query the connection status, 1 CONNECT, 0 IDLE

# Network connectivity status chart

1. Connect status (+ CSCON: 0, 1, the module is in this state after network
injection), the duration of this state is configured by the base station,
and and can be controlled by the device between the range of 1-3600 seconds, the default being
20s.
2. Idle state (+ CSCON: 0,0), this state lasts the time to dispose by the
key network, by Active timer (T3324) Come
Control, the range of 0-11160s, the default 10s.
3. PSM state (Judgment by power consumption, the maximum power consumption
5uA), the duration of the state by the core network configuration, set by
the TAU Timer (T3412) to control the range of 0h-310h, the default 24h.
