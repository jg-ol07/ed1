<div align="center">

# 📦 Estruturas de Dados I (ED1)

<p align="center">
  <strong>Resoluções, implementações e anotações das listas de exercícios da disciplina.</strong>
</p>

<!-- Badges de Tecnologias e Status -->
<p align="center">
  <img src="https://img.shields.io/badge/Linguagem-C%20%2F%20C%2B%2B-00599C?style=for-the-badge&logo=c" alt="Linguagem C" />
  <img src="https://img.shields.io/badge/Status-Em%20Progresso-brightgreen?style=for-the-badge" alt="Status" />
  <img src="https://img.shields.io/badge/Semestre-2026.1-orange?style=for-the-badge" alt="Semestre" />
</p>

---

</div>

## 📌 Sobre o Repositório

Este repositório contém as soluções das listas práticas e teóricas da disciplina de **Estruturas de Dados I**. O objetivo principal é consolidar conceitos fundamentais de computação, como gerenciamento de memória, análise assintótica e implementação de estruturas lineares clássicas.

---

## 🗺️ Tópicos Abordados

- [ ] Ponteiros e Alocação Dinâmica de Memória (`malloc`, `free`, `realloc`)
- [ ] Tipos Abstratos de Dados (TADs) e Modularização
- [ ] Análise de Complexidade de Algoritmos (Notação Big-O)
- [ ] Listas Estáticas e Dinâmicas (Simplesmente e Duplamente Encadeadas)
- [ ] Pilhas (Stacks) e Filas (Queues)
- [ ] Listas Circulares
- [ ] Algoritmos de Ordenação Elementares (*Bubble*, *Insertion*, *Selection*)

---

## 📁 Estrutura de Pastas

A organização dos arquivos segue o padrão modular abaixo:

```text
.
├── 📂 Lista-01_Ponteiros_Alocacao/
│   ├── exercicio_01.c
│   ├── exercicio_02.c
│   └── README.md
├── 📂 Lista-02_TADs/
│   ├── ponto.h
│   ├── ponto.c
│   └── main.c
├── 📂 Lista-03_Listas_Encadeadas/
│   ├── lista.h
│   ├── lista.c
│   └── teste_lista.c
├── 📂 Lista-04_Pilhas_e_Filas/
│   ├── pilha.c
│   └── fila.c
└── 📄 README.md
```

---

## 📋 Acompanhamento das Listas

| Lista | Tópico Principal | Status | Exercícios |
| :---: | :--- | :---: | :---: |
| **01** | Revisão de C, Ponteiros & Alocação Dinâmica | 🔄 Em andamento | 4 / 8 |
| **02** | Tipos Abstratos de Dados (TAD) | ⏳ Pendente | 00 / 06 |
| **03** | Listas Lineares Encadeadas | ⏳ Pendente | 00 / 08 |
| **04** | Pilhas e Filas (Estáticas e Dinâmicas) | ⏳ Pendente | 00 / 06 |
| **05** | Aplicações e Algoritmos de Ordenação | ⏳ Pendente | 00 / 05 |

---

## 🚀 Como Compilar e Executar

Para compilar e rodar os programas localmente com o **GCC**:

### 1. Clonar o repositório
```bash
git clone https://github.com/seu-usuario/estruturas-de-dados-1.git
cd estruturas-de-dados-1
```

### 2. Compilar um arquivo simples
```bash
gcc -Wall -Wextra -std=c99 Lista-01_Ponteiros_Alocacao/exercicio_01.c -o programa
./programa
```

### 3. Compilar programas modulares (TADs)
```bash
cd Lista-02_TADs
gcc -Wall -Wextra -std=c99 main.c ponto.c -o teste_ponto
./teste_ponto
```

---

## 🛠️ Tecnologias e Ferramentas

- **Linguagem:** C (padrão C99/C11)
- **Compilador:** GCC / Clang
- **Depuração e Validação de Memória:** Valgrind & GDB
- **Editor Recomendado:** VS Code / Neovim

---

<div align="center">

Feito com dedicação para a disciplina de **Estruturas de Dados I** 🚀  
*Sinta-se à vontade para sugerir melhorias ou reportar bugs através de Issues!*

</div>
