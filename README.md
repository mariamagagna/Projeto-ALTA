# ALTA – Alerta de Linha de Transbordamento Ativa

O **ALTA (Alerta de Linha de Transbordamento Ativa)** é um projeto desenvolvido por alunas do **SENAI** com o objetivo de auxiliar no monitoramento do nível da água em rios e identificar situações de risco de transbordamento.

O projeto surgiu durante o componente curricular de **Internet das Coisas (IoT)** e integra hardware e software para oferecer uma solução voltada à prevenção de enchentes.

---

## Objetivo

Desenvolver um sistema capaz de monitorar o nível da água utilizando sensores ultrassônicos, exibindo as informações em uma plataforma web de forma clara e acessível para a população.

Além do monitoramento automático, o sistema permite que os usuários contribuam com informações sobre ocorrências, fortalecendo a participação da comunidade na prevenção de desastres.

---

## Funcionalidades

- Monitoramento do nível da água em tempo real.
- Mapa interativo com localização dos sensores.
- Exibição do status dos pontos monitorados.
- Área para contribuição da comunidade.
- Página informativa sobre o projeto.
- Interface intuitiva e responsiva.

---

## Tecnologias Utilizadas

### Desenvolvimento Web

- HTML5
- CSS
- JavaScript

### Programação

- Python
- Arduino (C++)

### Hardware

- Arduino Uno
- Sensor Ultrassônico HC-SR04

### Biblioteca

- Leaflet.js (mapa interativo)

---

## Estrutura do Projeto

```
Projeto-ALTA/
│
├── Inicio.html
├── Alertas.html
├── Mapa.html
├── Contribuir.html
├── Sobre.html
├── style.css
├── mapa.js
├── script.js
├── serialArduino.py
├── dados.json
└── ALTA.ino
```

---

## Como executar

1. Clone este repositório:

```bash
git clone https://github.com/mariamagagna/Projeto-ALTA.git
```

2. Abra a pasta do projeto.

3. Execute as páginas HTML utilizando o **Live Server** no Visual Studio Code.

4. Para comunicação com o Arduino, execute o arquivo:

```bash
python serialArduino.py
```

---

## Equipe

Projeto desenvolvido por:

- Maria Eduarda
- Eduarda
- Kamile

Alunas do **SENAI**, durante o componente curricular de **Internet das Coisas (IoT)**.

---

## Objetivo Social

O ALTA busca contribuir para a monitoramento de rios por meio da tecnologia, oferecendo informações que auxiliem a população e os órgãos responsáveis na tomada de decisões em situações de risco.

---

## Licença

Este projeto foi desenvolvido para fins acadêmicos.
