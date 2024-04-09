import serial
import time

port = "COM3"  # Changez-le en fonction de votre configuration

ser = serial.Serial(port, 9600)  # 9600 est la vitesse de communication, ajustez-la si nécessaire

time.sleep(2)

while True:
    try:
        ser.write(b'L1\n')  # Envoie "L1"
        time.sleep(0.5)  # Attendre 500ms
        ser.write(b'L2\n')  # Envoie "L2"
        time.sleep(0.5)  # Attendre 500ms
        ser.write(b'L3\n')  # Envoie "L3"
        time.sleep(0.5)  # Attendre 500ms
        ser.write(b'L4\n')  # Envoie "L4"
        time.sleep(0.5)  # Attendre 500ms

    except KeyboardInterrupt:
        print("Interruption du programme par l'utilisateur.")
        break
ser.close()
