
## Client socket example
``` python
import socket

targer_host = "www.google.com"
target_port = 80

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((targer_host, target_port))

client.send(b"GET / HTTP/1.1\r\nHOST: google.com\r\n\r\n")

response = client.recv(4096)

print(response.decode())
client.close()
```
