# 🅿️ Controle de Estacionamento

Um sistema de gerenciamento de estacionamento desenvolvido em C++ que controla entrada, saída e cobrança de veículos.

## 📋 Funcionalidades

- **Registro de Cliente** - Registra a entrada de um veículo com placa e horário
- **Registro de Saída** - Registra a saída de um veículo e calcula o valor a pagar
- **Cálculo de Tarifa** - Calcula automaticamente o tempo de permanência e valor cobrado
- **Histórico** - Mantém registro de todos os veículos do dia
- **Relatório Final** - Finaliza o dia exibindo total arrecadado

## 🚀 Como Compilar e Executar

1. Certifique-se de ter um compilador C++ instalado
2. Compile o programa:
   ```bash
   g++ "Controle de Estacionamento.cpp" -o estacionamento
   ```
3. Execute o programa:
   ```bash
   ./estacionamento
   ```

## 📖 Como Usar

1. O programa solicitará a data de hoje (dd mm aaaa)
2. Informe o valor da hora do estacionamento em reais
3. Escolha uma opção no menu:
   - **Opção 1**: Registrar entrada de um veículo (informe a placa e horário)
   - **Opção 2**: Registrar saída de um veículo (informe a placa e horário)
   - **Opção 3**: Finalizar o dia (exibe total arrecadado)

**Exemplo de uso:**
```
Informe a data de hoje (dd mm aaaa): 14 11 2025
Qual o valor da hora do estacionamento: R$15.00

======== Menu ========
1 - Registro de cliente
2 - Registro de saída
3 - Finalizar dia
Opção desejada: 1

Placa do carro: ABC1234
Hora de entrada (hh mm): 10 30
```

## 🛠️ Tecnologias

- C++
- Vector (para armazenamento dinâmico de dados)
- Structs (para organização de dados)

## 💰 Características

- Cálculo automático de tarifa por minuto
- Validação de horários
- Registro detalhado de cada veículo
- Suporte a múltiplos veículos por dia

## 📝 Licença

Este projeto é de código aberto.

---

*Projeto desenvolvido para gerenciamento de estacionamentos* 🚗
