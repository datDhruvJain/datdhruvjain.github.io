[learned from here](https://www.youtube.com/watch?v=4t4kBkMsDbQ&list=PLrBcUKpfKClycxF87WU9Gb_wlKEfd1yo7&index=31)

to scan for all devices connected to the network
```shell
nmap -sP network_addresss

# eg
nmap -sP 192.168.1.0/24
```
if all devices are not being reported, try again as root

to scan for open ports:
```shell
nmap -sT -p ports_to_scan network

# eg
nmap -sT -p 80,443 192.168.1.0/24
```
here T stands for TCP connect(full open scan) using a threeway handshake.

TCP -> transport control protocol and here is how it works:
1. syn -> the client sends a message to the server asking are you up? are you listening? are you up for connection?
2. syn ack -> this is sent by the server to the client in repsponse to the syn message. A successful reply is "yes i am up for connecting and listening"
3. ack -> is a message sent from the client after recieveing the the syn ack saying "yes let's do this let's connect"

to connect via a TCP connection, you need to complete the above three way handshake

#### Running nmap in stealth mode
```shell
sudo nmap -sS -p 80,443 network

# eg
sudo nmap -sS -p 80,443 192.168.1.0/24
```
stealty because it only send a syn message and waits for the syn ack messege

### Search for operating system of the target
```shell
sudo nmap -O host_ip

# eg
sudo nmap -O 192.168.1.111
```
The -A flag, which stands for aggressive mode does OS detection, version detection, script scanning and traceroute.

### Using a Decoy
```shell
sudo nmap -sS -D decoy_ip_addr host_ip_addr

# eg
sudo nmap -sS -D 192.168.1.2 192.168.1.119
```

### Using a script
nmap can use custom scripts, check out https://nmap.org/nsedoc/ for a list of premade scripts. below is an example of nmap running ALL scripts from the vuln category
```shell
nmap --script vuln target_ip

# eg
sudo nmap --script vuln 192.168.1.112
```
