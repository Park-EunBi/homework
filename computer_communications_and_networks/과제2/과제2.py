# TCP 에코 서버 (receive 한 것 그대로 send 하는 서버)
# 1명의 클라이언트만 서비스한다

from socket import *

port = 2500

address = ('localhost', port)


BUFSIZE = 1024

tcpServer_sock = socket(AF_INET, SOCK_STREAM)
tcpServer_sock.bind(address)  # 자신의 주소 사용
tcpServer_sock.listen(1)  # 최대 대기 클라이언트 수

table = {'1':'one', '2': 'two', '3': 'three', '4': 'four',\
'5':'five', '6': 'six', '7': 'seven', '8': 'eight',\
'9': 'nine', '10': 'ten'}

print("Waiting for clients...")

tcpClient_sock,  (r_host, r_port) = tcpServer_sock.accept()
print('connected by', tcpClient_sock, r_host, r_port)

while True:
    data = tcpClient_sock.recv(BUFSIZE)
    if not data:
        print('client disconnected')
        break

    print("Received message: ", data.decode())

    if data.decode() == 'server stop':
        break

    # 과제 부분
    recvData = data.decode()
    if recvData in table:
        ackData = '[Ack] ' + table[recvData]

    else:
        ackData = '[NACK]'

    tcpClient_sock.send(ackData.encode())

print('server stop')

tcpServer_sock.close()