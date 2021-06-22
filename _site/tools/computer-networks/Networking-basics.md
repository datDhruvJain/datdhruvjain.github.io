[learned from here](https://www.youtube.com/watch?v=rIZ61PyDkH8&list=PLR0bgGon_WTKY2irHaG_lNRZTrA7gAaCj&index=2&t=0s)

### The OSI model of networking (PHN T SPA) (phantom spa?)

<details markdown ='1'>
<summary>Layer 1 - Physical Layer (lowest, physical bits)</summary>

* includes cables/bites ie pinouts, voltages cable specification and NIC(network interfacing cards)

* it's not code anymore, it's physical voltages
  
  </details>

<details markdown='1'>
<summary>Layer 2 - Data Link</summary>

- package bittes/ data into frames

- MAC address (which are unique)

- all layer 2 is doing is getting data from one point to another
  
  </details>

<details markdown='1'>
<summary>Layer 3 - Networking Layer</summary>

- reffered to as the "IP" layer

- transfers logical address to physical

- performs networking routing

- for eg router
  
  </details>

<details markdown='1'>
<summary>Layer 4 - Transport</summary>

- management and control

- transfer of data: TCP,UDP

- split communication coming from higher layer into packages
  
  </details>

<details markdown='1'>
<summary>Layer 5 - Session</summary>

- traffic control (establish, manage terminate connections) and coordination
  
  </details>

<details markdown='1'>
<summary>Layer 6 - Presentation</summary>

- formatting, like xml etc

- encryption/decryption
  
  </details>

<details markdown='1'>
<summary>Layer 7 - Application (Highest, user intereacts with this)</summary>

- network access, enables apps to access the internet

- SMTP, HTTP, FTP etc
  
  </details>

For a computer sending the message, it goes from `7 -> 1`, for a computer recieveing the message it goes from `1 -> 7`

## IPv-4 and IPv-6

IPv4 have 32 bit addresses, 4 sets of 8 binaies. it has a possibilty of connecting only 4 Billion devices, we have alot more devices in the world and this is a limiting factor

IPv6
