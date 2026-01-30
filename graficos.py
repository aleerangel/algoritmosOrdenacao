import pandas as pd 
import matplotlib.pyplot as plt
import seaborn as sns 
import os 

pasta_saida = 'Graficos'
if not os.path.exists(pasta_saida):
    os.makedirs(pasta_saida)

df = pd.read_csv('resultados.csv')

df.columns = df.columns.str.strip()
df['Algoritmo'] = df['Algoritmo'].str.strip()
df['Tipo'] = df['Tipo'].str.strip()

tamanhos = [10000, 100000, 500000]
tipos = ['aleatorio', 'crescente', 'decrescente']
metricas = [
    {'coluna': 'Tempo(ms)', 'nome_arquivo': 'Tempo', 'titulo': 'Tempo de Execucao (ms)'},
    {'coluna': 'Comparacoes', 'nome_arquivo': 'Comparacoes', 'titulo': 'Numero de Comparacoes'},
    {'coluna': 'Trocas', 'nome_arquivo': 'Trocas', 'titulo': 'Numero de Trocas'}
]

sns.set_theme(style="whitegrid")

print("Iniciando geracao dos graficos")

for n in tamanhos:
    for t in tipos:
        for m in metricas:
            coluna = m['coluna']

            subset = df[(df['N'] == n) & (df['Tipo'] == t)].sort_values(coluna, ascending=True)

            if subset.empty:
                continue

            plt.figure(figsize=(14, 8))

            ax = sns.barplot(x=coluna, y='Algoritmo', data=subset, palette='magma')

            for container in ax.containers:
                ax.bar_label(container, fmt='%.0f', padding=5, fontsize=10)

            plt.title(f"{m['titulo']} - N={n} ({t.capitalize()})", fontsize=16, fontweight='bold')
            plt.xlabel(m['titulo'], fontsize=12)
            plt.ylabel('Algoritmo', fontsize=12)

            plt.tight_layout()

            nome_arquivo = f"{pasta_saida}/{m['nome_arquivo']}_{n}_{t}.pdf"
            plt.savefig(nome_arquivo)
            plt.close()

            print(f"Gerado: {nome_arquivo}")
