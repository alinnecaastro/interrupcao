# Interrupções com Matriz

## Estrutura do Projeto  
- **build/** → Diretório de compilação gerado pelo CMake.  
- **debounce.c** → Arquivo que importa a interrupção e o debounce do codigo 
- **definicoes.h** → Arquivo que importa as variaveis dos botoes, matriz,delay,led... 
- **numeros.c** → Arquivos que importa as funções do numeros e a função que mostra os leds na matriz. 
- **diagram.json** → Simulação do Wokwi 
- **CMakeLists.txt** → Configuração do CMake para compilação.  
- **interrupcao.c** → Código principal do projeto.  
- **pio_config.h** → Configuração do PIO para LEDs NeoPixel.  
- **pico_sdk_import.cmake** → Importação do SDK do Raspberry Pi Pico.  
- **README.md** → Documentação do projeto.  
- **teclado.h** → Definições e funções para o teclado.  
- **wokwi.toml / wokwi-project.txt** → Arquivos de configuração para simulação no Wokwi.  
- **ws2812.pio / ws2812.pio.h** → Código PIO para controle dos LEDs WS2812.  

## Simulador online
[https://wokwi.com/projects/421756301808734209](https://wokwi.com/projects/421756301808734209 "https://wokwi.com/projects/421756301808734209")

## Descrição Geral

Este projeto utiliza um Raspberry Pi Pico W na plataforma de apredizagem BitDogLab e uma matriz de LEDs RGB 5x5 (WS2812). 
O projeto combina tanto aspectos de hardware quanto de software e busca explorar funcionalidades como controle de LEDs, tratamento de ruído em botões (bouncing) e a implementação de interrupções.
 

## Video do funcionamento do projeto
"https://drive.google.com/file/d/1En1FajGNNJt90o80t0FL2H02QNDTWV8I/view?usp=sharing"


## Funcionalidades do Projeto
° O LED vermelho do LED RGB deve piscar continuamente 5 vezes por segundo.
° O botão A deve incrementar o número exibido na matriz de LEDs cada vez que for pressionado (0 a 9).
° O botão B deve decrementar o número exibido na matriz de LEDs cada vez que for pressionado (9 a 0).


## Requisitos do Projeto
° Uso de interrupções: Todas as funcionalidades relacionadas aos botões devem ser implementadas
utilizando rotinas de interrupção (IRQ).
° Debouncing: É obrigatório implementar o tratamento do bouncing dos botões via software.
° Controle de LEDs: O projeto deve incluir o uso de LEDs comuns e LEDs WS2812, demonstrando o
domínio de diferentes tipos de controle.
° Organização do código: O código deve estar bem estruturado e comentado para facilitar o
entendimento.

## Conclusão
Este projeto oferece uma excelente oportunidade para praticar a integração de hardware e software em sistemas embarcados, ao mesmo tempo em que permite explorar técnicas essenciais como o uso de interrupções, debouncing de botões e controle de LEDs endereçáveis. A execução bem-sucedida deste projeto mostrará não só a compreensão desses conceitos, mas também a habilidade de projetar um sistema funcional e bem estruturado para uma placa de microcontrolador.