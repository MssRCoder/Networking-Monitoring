# Networking-Monitoring

Desafio: Monitoramento de Latência de Rede
Descrição do Desafio

Crie um sistema simples para monitorar a latência da rede entre seu computador e um conjunto de servidores. Este sistema deve:

    Utilizar um script Bash para configurar e iniciar o monitoramento.
    Utilizar um script Python para coletar e armazenar os dados de latência.
    Utilizar um programa em C++ para calcular estatísticas básicas sobre os dados de latência coletados.
    Utilizar arquivos de configuração para especificar os servidores a serem monitorados.

Detalhes

    Arquivo de Configuração (servidores.txt):
        Crie um arquivo chamado servidores.txt que contenha a lista de servidores a serem monitorados, um por linha. Por exemplo:

        google.com
        facebook.com
        amazon.com

    Script Bash (monitor.sh):
        Escreva um script Bash chamado monitor.sh que:
            Leia o arquivo de configuração (servidores.txt).
            Chame periodicamente (por exemplo, a cada 5 segundos) o script Python para coletar dados de latência.

    Script Python (coletar_latencia.py):
        Escreva um script Python chamado coletar_latencia.py que:
            Leia o arquivo de configuração (servidores.txt).
            Faça ping em cada servidor da lista.
            Salve os tempos de resposta em um arquivo CSV chamado latencia.csv com a estrutura: timestamp, host, latência.

    Programa em C++ (calcular_estatisticas.cpp):
        Escreva um programa em C++ chamado calcular_estatisticas.cpp que:
            Leia o arquivo CSV gerado pelo script Python (latencia.csv).
            Calcule estatísticas básicas (média, mínima e máxima) da latência para cada servidor.
            Exiba essas estatísticas de forma clara.

Instruções

    Arquivo de Configuração:
        Crie o arquivo servidores.txt e adicione a lista de servidores que deseja monitorar.

    Script Bash:
        Crie um arquivo chamado monitor.sh.
        No monitor.sh, escreva um script que:
            Leia o arquivo servidores.txt.
            Execute periodicamente o script Python coletar_latencia.py para coletar dados de latência.
            Use o comando sleep para definir o intervalo entre as execuções.

    Script Python:
        Crie um arquivo chamado coletar_latencia.py.
        No coletar_latencia.py, escreva um script que:
            Leia o arquivo servidores.txt.
            Utilize o comando ping para medir a latência de cada servidor.
            Salve os resultados em um arquivo CSV (latencia.csv) com colunas para timestamp, host e latência.

    Programa em C++:
        Crie um arquivo chamado calcular_estatisticas.cpp.
        No calcular_estatisticas.cpp, escreva um programa que:
            Leia o arquivo latencia.csv.
            Calcule as estatísticas de latência (média, mínima, máxima) para cada servidor.
            Exiba as estatísticas calculadas.

    Execução:
        Compile o programa em C++ usando um compilador como o g++:

        bash

g++ calcular_estatisticas.cpp -o calcular_estatisticas

Execute o script Bash para iniciar o monitoramento:

bash

./monitor.sh

Após coletar dados por um período, pare o script Bash e execute o programa em C++ para calcular as estatísticas:

bash

        ./calcular_estatisticas

Seguindo essas instruções, você será capaz de criar um sistema básico de monitoramento de latência de rede utilizando Bash, Python e C++.
