# wfilter
A web keyword firewall(filter), which is based on DPDK and Aho-Corasick string matching.
i

#### Compile denpendcy
mongoc-1.0 lib
bson-1.0 lib
ahocorasick src

To link lib, need change make of $RTE_SDK/mk/rte.app.mk
LDLIBS += -L/usr/lib64 -lmongoc-1.0 -lbson-1.0


#### Test topology

 A ----- wfilter ----- B


### A (Windows/192.168.6.1):

#### CONFIG
arp -s 192.168.233.23 00-0C-29-B8-EB-C8 192.168.6.1
route add 192.168.233.23 mask 255.255.255.255 192.168.6.1

#### SHOW
> route print
IPv4 Route Table
===========================================================================
Active Routes:
Network Destination        Netmask          Gateway       Interface  Metric
   192.168.233.23  255.255.255.255         On-link       192.168.6.1     21


> arp -a
Interface: 192.168.6.1 --- 0x19
  Internet Address      Physical Address      Type
  192.168.233.23        00-0c-29-b8-eb-c8     static


### B (Linux/192.168.233.23):
TBD

#### SHOW
[donge@localhost ~]$ route 
Kernel IP routing table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
192.168.6.1     *               255.255.255.255 UH    0      0        0 eth1

[donge@localhost ~]$ arp
Address                  HWtype  HWaddress           Flags Mask            Iface
192.168.6.1              ether   00:50:56:c0:00:02   CM                    eth1



