import serial
import json
import time

# Porta em que o Arduino está conectado
PORTA = "COM3"
VELOCIDADE = 9600

# Espera o Arduino iniciar
arduino = serial.Serial(PORTA, VELOCIDADE)
time.sleep(2)

print("Arduino conectado!")
print("Recebendo dados...\n")

while True:

    try:
        # Lê uma linha enviada pelo Arduino
        linha = arduino.readline().decode("utf-8").strip()

        # Converte para número
        distancia = float(linha)

        # Define o status
        if distancia > 30:
            status = "🟢 NORMAL"

        elif distancia > 20:
            status = "🟡 ATENÇÃO"

        elif distancia > 10:
            status = "🟠 ALERTA"

        else:
            status = "🔴 EMERGÊNCIA"

        # Cria um dicionário
        dados = {
            "distancia": round(distancia, 2),
            "status": status
        }

        # Salva em dados.json
        with open("../Site/dados.json", "w", encoding="utf-8") as arquivo:
            json.dump(dados, arquivo, indent=4, ensure_ascii=False)

        print(dados)

    except ValueError:
        print("Valor inválido recebido do Arduino.")

    except KeyboardInterrupt:
        print("Programa encerrado.")
        break

    except Exception as erro:
        print("Erro:", erro)