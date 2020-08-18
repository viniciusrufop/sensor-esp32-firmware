# Sistema de leitura de sensores - Firmware

## Sistema que faz a leitura de sensores e envia os dados para uma API que posteriormente salva em um Banco de Dados


# Passos de configuração

Renomear o arquivo `env.h.example` dentro de `src` para `env.h`.

Abrir arqivo `src/env.h` e alterar os valores das variáveis `NOME_REDE`, `SENHA_REDE` de acordo com sua rede Wi-Fi, alterar a variável `HOST_SERVER` com o ip em que a API foi inicializada.

# Compilar

Para compilar o projeto e carrega-lo em uma placa de desenvolvimento ESP32, basta utilizar o editor de texto `VS Code` instalar a extensão [PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide), carregar um projeto existente e selecionar a pasta onde foi feito o git clone deste repositório.

### Passos que talvez sejam necessários
Instalar alguns pacotes

`sudo apt install python-is-python3`

`sudo apt-mark hold python2 python2-minimal python2.7 python2.7-minimal libpython2-stdlib libpython2.7-minimal libpython2.7-stdlib`

`sudo apt install python3-serial`

### Lembrete
Quando utilizar a conexão Wi-Fi do ESP32 a leitura analógica dos pinos ADC2 não funciona, é necessário utilizar os pinos ADC1.

`ADC2 is used with WiFi. Therefor analogRead() on ADC2 pins fails. ADC1 channels are save to use ⇒ GPIO32, 33, 34, 35, 36, 39.`
