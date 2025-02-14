# 🚗 Sistema de Gerenciamento de Aluguel de Carros e Clientes

Este programa em C implementa um sistema para gerenciar aluguel de carros e cadastro de clientes. Ele permite cadastrar, listar, alterar e excluir registros, além de gerenciar o aluguel e a devolução de veículos.

---

## 📋 Funcionalidades

- **Cadastro**:
  - Cadastrar novos carros e clientes.
- **Listagem**:
  - Visualizar todos os carros cadastrados.
  - Visualizar todos os clientes cadastrados.
  - Listar carros disponíveis.
  - Listar carros alugados.
- **Alteração**:
  - Alterar os dados de carros ou clientes.
- **Exclusão**:
  - Marcar carros e clientes como inativos.
- **Aluguel e Devolução**:
  - Alugar um carro para um cliente.
  - Registrar a devolução de um carro alugado.

---

## 📂 Estrutura de Dados

O programa utiliza duas estruturas principais:

### `struct Registro_Carro`
- `Placa` (char[10])
- `Modelo` (char[50])
- `Ano` (int)
- `Cor` (char[30])
- `Flag` (int) - Marca ativa/inativa para exclusão lógica
- `CpfAlugado` (int) - CPF do cliente que alugou o carro
- `Situacao` (int) - 0 para disponível, 1 para alugado

### `struct Registro_Cliente`
- `Nome` (char[50])
- `Cpf` (int)
- `Nascimento` (char[10])
- `Flag` (int) - Marca ativa/inativa para exclusão lógica

---

## 🛠️ Requisitos

- Compilador C (como GCC).
- Sistema operacional com suporte para a linguagem C.

---

## 🚀 Como Usar

### Compilação
Para compilar o programa, execute o seguinte comando no terminal:

```bash
gcc programa.c -o aluguel

