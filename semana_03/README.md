# Semana 3 — Buffer Circular e Filtro de Média Móvel (FIR)

## 📍 Objetivo

Nesta etapa, o objetivo foi compreender profundamente como a memória funciona em C e aplicar esse conhecimento na construção de um sistema simples de processamento de sinais.

O foco principal foi:

* uso de ponteiros
* manipulação de vetores
* construção de buffer circular
* implementação de filtro de média móvel (FIR)
* otimização de algoritmo para tempo real

---

## 🧠 Conceitos Fundamentais

### 🔹 Ponteiros

Ponteiros permitem acessar e modificar diretamente posições de memória.

* `&` → obtém o endereço de uma variável
* `*` → acessa o valor armazenado naquele endereço

Exemplo:

```c
int x = 10;
int *p = &x;

*p = 20; // altera o valor de x
```

---

### 🔹 Vetores como memória contínua

Um vetor é um bloco contínuo de memória.

```c
v[i] == *(v + i)
```

Isso significa que acessar um vetor é, na prática, manipular endereços de memória.

---

## 🔁 Buffer Circular

O buffer circular é uma estrutura que permite reutilizar um vetor de tamanho fixo, sobrescrevendo os dados antigos.

### 📌 Implementação

```c
buffer[*pos] = valor;
*pos = (*pos + 1) % TAM;
```

---

## 💡 Como o comportamento circular é criado

É importante destacar:

* `TAM` define o tamanho do buffer
* o operador `%` (resto da divisão) é o responsável por criar o ciclo

Exemplo com `TAM = 5`:

```txt
0 → 1 → 2 → 3 → 4 → 0 → 1 → ...
```

Ou seja, quando o índice chega ao final, ele volta automaticamente ao início.

---

## ⚙️ Estrutura do Sistema

O sistema segue o fluxo:

```txt
Sensor → Buffer → Processamento → Saída
```

Estado do sistema (armazenado na `main`):

```c
int buffer[TAM];
int pos;
int soma;
int indiceSensor;
```

---

## 📊 Filtro de Média Móvel (FIR)

O filtro de média móvel suaviza o sinal, reduzindo variações rápidas.

---

### 🔴 Versão inicial (ineficiente)

```c
for (int i = 0; i < TAM; i++) {
    soma += buffer[i];
}
```

* custo: O(N)
* recalcula toda a soma a cada leitura

---

### 🟢 Versão otimizada

```c
soma = soma - valor_antigo + valor_novo;
```

* custo: O(1)
* evita recalcular toda a soma
* ideal para sistemas embarcados

---

## 🔧 Lógica da Inserção

A ordem das operações é fundamental:

1. remover o valor antigo da soma
2. adicionar o novo valor
3. atualizar o buffer
4. avançar a posição circular

```c
*soma = *soma - buffer[*pos] + valor;
buffer[*pos] = valor;
*pos = (*pos + 1) % TAM;
```

---

## 🔬 Validação do Sistema

Para validar corretamente o funcionamento, foi utilizado um sensor simulado com dados fixos:

```c
int dados[] = {10, 20, 30, 40, 50, 60, 70};
```

### 📌 Por que não usar `rand()`?

* não permite prever resultados
* dificulta validação
* impede verificação manual

Com dados fixos, foi possível confirmar o comportamento esperado do filtro.

---

## 📈 Comportamento Observado

Exemplo:

Entrada:

```txt
10 → 20 → 30 → 40 → 50
```

Saída:

```txt
Média = 30
```

Após atualização:

```txt
60 substitui 10 → Média = 40
```

---

## ⚠️ Comportamento inicial

No início, o buffer contém zeros:

```txt
[10, 0, 0, 0, 0]
```

Isso faz com que a média seja menor até o buffer ser completamente preenchido.

---

## 🧠 Aprendizados

* diferença entre valor e endereço na memória
* uso de ponteiros para alterar dados fora da função
* funcionamento de vetores em C
* construção de buffer circular
* uso do operador `%` para controle de índice
* otimização de algoritmos (O(N) → O(1))
* separação entre estado do sistema e funções
* importância da validação com dados controlados

---

## 🚀 Conclusão

Foi possível evoluir de uma solução simples para uma solução eficiente e próxima de aplicações reais de sistemas embarcados.

O sistema desenvolvido já segue princípios importantes de firmware:

* controle explícito de estado
* processamento eficiente
* comportamento previsível
* estrutura modular

---

## 🔜 Próximos Passos

* manipulação de bits
* registradores
* acesso direto ao hardware
* início da programação embarcada real (ESP32)
