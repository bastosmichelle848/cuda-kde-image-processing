# Kernel Density Estimation (KDE)

Este projeto implementa o cálculo da **Kernel Density Estimation (KDE)** em três versões:

- **Sequencial em Python**
- **Acelerada por GPU com CUDA**
- **Utilizando OpenMP em C++**

## Arquivos do Projeto

### 1. **Python (Sequencial)**
- **Arquivo:** `kernel_density_estimation4.py`
  - Implementação da KDE utilizando Python de forma sequencial.

### 2. **C++ (OpenMP)**
- **Arquivo:** `kernel_density_estimation_open_mp4.cpp`
  - Implementação da KDE utilizando OpenMP para paralelização.

### 3. **C++ (CUDA)**
- **Arquivo:** `kde_cuda.cu`
  - Implementação da KDE utilizando CUDA para aceleração com GPU.

### 4. **Arquivos de Saída**
- **Python:** `output_sequencial.txt`
  - Arquivo contendo o resultado da KDE utilizando a versão sequencial em Python.
- **C++ (OpenMP):** `output_openmp.yml`
  - Arquivo contendo o resultado da KDE utilizando OpenMP.
- **C++ (CUDA):** `output_cuda.yml`
  - Arquivo contendo o resultado da KDE utilizando CUDA.

## Como Rodar o Código

### 1. **Comando para Transferir Arquivos para o Super Computador**

Para enviar arquivos para o supercomputador, use o seguinte comando no **Git Bash**:

```bash
scp /c/Users/USUARIO_EXEMPLO/script/exemplo.py usuario_ficticio@rolf.ficticio.pt:/home/alunos/tei/2024/usuario_ficticio/

