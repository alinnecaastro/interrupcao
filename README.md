# Interrupções com Matriz
Estrutura do Projeto 
build/ → Diretório de compilação gerado pelo CMake. 
debounce.c → Arquivo que importa a interrupção e o debounce do codigo 
definicoes.h → Arquivo que importa as variaveis dos botoes, matriz,delay,led... 
numeros.c → Arquivos que importa as funções do numeros e a função que mostra os leds na matriz. diagram.json → Simulação do Wokwi 
CMakeLists.txt → Configuração do CMake para compilação. 
interrupcao.c → Código principal do projeto. pio_config.h → Configuração do PIO para LEDs NeoPixel. 
pico_sdk_import.cmake → Importação do SDK do Raspberry Pi Pico. 
README.md → Documentação do projeto. 
wokwi.toml / wokwi-project.txt → Arquivos de configuração para simulação no Wokwi. 
ws2812.pio / ws2812.pio.h → Código PIO para controle dos LEDs WS2812.