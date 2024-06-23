import socket
import time
from scapy.all import sr1, IP, ICMP
from datetime import datetime


DtNow = datetime.now()

with open("servidores.txt", "r") as servers_list:
    for line in servers_list:
        #socket.gethostbyname(line.strip())
        target = line.strip()
        packet = IP(dst=target)/ICMP()

        StartTime = time.time()

        response = sr1(packet, timeout=2)

        EndTime = time.time()

        if response:
            print(f"Response from {target}")
            response.show()
            with open("response.txt","a") as response_data:
                latency_ms = (EndTime - StartTime) * 1000
                data = str(DtNow.timestamp())+" "+target+" "+str(response)+" "+str(latency_ms)+"\n"
                #response_data.write(DtNow.timestamp())
                response_data.write(data)
                response_data.close()
                
                data2 = str(DtNow.timestamp())+","+target+","+str(latency_ms)+"\n"

                with open("csv_data.txt", "a") as csv_data:
                    csv_data.write(data2)
                    csv_data.close()
        else:
            print("No reponse.")

