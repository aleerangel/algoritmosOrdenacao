# 📊 Análise Comparativa de Algoritmos de Ordenação

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Python](https://img.shields.io/badge/Python-3.x-yellow.svg)
![Status](https://img.shields.io/badge/Status-Completed-green.svg)
![Course](https://img.shields.io/badge/UFES-Estrutura%20de%20Dados%20II-red.svg)

Este repositório contém a implementação e análise de desempenho de **14 algoritmos de ordenação**, desenvolvido como parte da disciplina de **Estrutura de Dados II** da Universidade Federal do Espírito Santo (UFES).

O objetivo é comparar a eficiência de algoritmos de diferentes classes de complexidade em cenários variados (aleatório, crescente e decrescente) com grandes volumes de dados (até 500.000 elementos).

---

## 🚀 Algoritmos Implementados

O projeto contempla implementações otimizadas em C dos seguintes métodos:

| Categoria | Algoritmos |
| :--- | :--- |
| **Quadráticos O(n²)** | • Bubble Sort (Clássico e com Parada)<br>• Selection Sort<br>• Insertion Sort (Direta, Binária e Ternária) |
| **Eficientes O(n log n)** | • Quick Sort (Pivôs: Fim, Centro e Mediana de 3)<br>• Merge Sort<br>• Heap Sort<br>• Shell Sort |
| **Lineares O(n)** | • Radix Sort<br>• Bucket Sort |

---

## 🛠️ Estrutura do Projeto

    ├── Entrada/          # Arquivos de texto com os vetores gerados
    ├── Saida/            # Vetores ordenados gerados pelos algoritmos
    ├── Graficos/         # Gráficos gerados automaticamente (PNG)
    ├── gera.c            # Gerador de massa de dados
    ├── main.c            # Programa principal (Benchmark)
    ├── sorts.c / .h      # Implementação dos algoritmos de ordenação
    ├── utils.c / .h      # Funções auxiliares (leitura, escrita, timer)
    ├── graficos.py       # Script Python para plotar os resultados
    └── resultados.csv    # Tabela com as métricas coletadas

---

## 💻 Pré-requisitos

Para rodar este projeto, você precisará de:
* **Compilador C** (GCC recomendado).
* **Python 3.x** (para gerar os gráficos).
* Bibliotecas Python: `pandas`, `matplotlib`, `seaborn`.

Instale as dependências do Python:
    pip install pandas matplotlib seaborn

---

## ⚙️ Como Compilar e Executar

Siga os passos abaixo para reproduzir os experimentos:

### 1. Compilar os programas em C
Abra o terminal na pasta raiz do projeto e compile o gerador de dados e o programa principal:

    # Compilar o Gerador de Números
    gcc gera.c -o gera

    # Compilar o Benchmark (Main)
    gcc main.c sorts.c utils.c -o benchmark

### 2. Gerar as Massas de Dados
O programa principal espera arquivos específicos na pasta `Entrada`. Você deve criá-los usando o executável `gera`. 

Exemplo de comando manual:
    ./gera -a 10000 input_10000_aleatorio.txt

*(Para o trabalho completo, gere os arquivos de 10k, 100k e 500k para os tipos aleatório, crescente e decrescente).*

### 3. Rodar o Benchmark
Execute o programa principal. Ele irá ler os arquivos da pasta `Entrada`, ordenar usando todos os 14 algoritmos, salvar o resultado ordenado na pasta `Saida` e registrar as métricas no arquivo `resultados.csv`.

    ./benchmark
    # (Ou .\benchmark.exe no Windows)

*Aguarde... o processamento de 500k elementos nos algoritmos quadráticos pode levar alguns minutos.*

### 4. Gerar os Gráficos
Após o fim da execução do benchmark, use o script Python para visualizar os dados:

    python graficos.py

Os gráficos serão salvos na pasta `Graficos/`.

---

## 📄 Artigo Técnico

Um artigo completo detalhando a metodologia, a análise da complexidade e a discussão dos resultados está disponível no arquivo PDF incluído neste repositório.

---

## 👨‍💻 Autor

**Alexandre Cesar de Souza Rangel** Aluno de Ciência da Computação - UFES

---

*Projeto desenvolvido para a disciplina de Estrutura de Dados II, lecionada pelo Prof. Dayan de Castro Bissoli.*
