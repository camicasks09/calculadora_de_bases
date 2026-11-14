Conversor de Bases Numéricas em C++

1. Introdução

O projeto é uma calculadora programada para conversão de bases. Foi desenvolvida na linguagem C++ e voltada para transformar valores entre as bases binária (2), octal (8), decimal (10) e hexadecimal (16).

Além disso, também oferece a opção de o usuário escolher as bases de sua preferência, entre 2 e 16. No terminal do VS Code, o sistema permanece em execução até que seja encerrado.

2. Local de desenvolvimento

O código foi escrito em linguagem C++ no Visual Studio Code (VS Code). O código foi desenvolvido, compilado e testado no próprio terminal do editor.

3. Funcionamento

O programa é organizado em três etapas:

Operação: é apresentado um menu de opções, no qual o usuário pode escolher a conversão desejada, como binário para decimal. O switch organiza automaticamente as bases de origem e destino.

Conversão para decimal: o número digitado é convertido para a base 10.

Conversão do decimal para a base final: o valor decimal é convertido para a base desejada.

3.1. Qualquer base para decimal

O programa irá ler o número digitado. A cada novo dígito, ele multiplica o valor acumulado pela base original e soma o dígito atual.

Fórmula:

decimal = decimal * base + dígito

Exemplo: conversão de 1011 (binário) para decimal

0 × 2 + 1 = 1
1 × 2 + 0 = 2
2 × 2 + 1 = 5
5 × 2 + 1 = 11

Sendo assim, temos o resultado 11 (10).

Com bases maiores que 10, como é o caso do hexadecimal, o código utiliza as letras de A a F, com valores de 10 a 15. Caso o usuário digite 2 em um número binário, o sistema irá apontar um erro.

3.2. Decimal para a base final

Utilizando o while, é encontrada a maior potência da base final que cabe dentro do número decimal.

Depois, o número é dividido por essas potências. O quociente da divisão será o dígito atual, e o resto será utilizado no próximo cálculo.

Exemplo: conversão de 25 para binário

Maior potência de 2 que cabe em 25: 16.

25 ÷ 16 = 1, resto 9  → dígito 1
9 ÷ 8 = 1, resto 1    → dígito 1
1 ÷ 4 = 0, resto 1    → dígito 0
1 ÷ 2 = 0, resto 1    → dígito 0
1 ÷ 1 = 1, resto 0    → dígito 1

Resultado: 11001

4. Recursos utilizados

Estrutura sequencial: declaração de variáveis e prática com cin e cout.

Estrutura condicional: uso do if para validar dígitos e tratar o caso do número zero; switch para o menu de opções.

Estrutura iterativa: do...while para o menu ficar ativo até o encerramento; while para ler os dígitos e calcular as potências.

Operadores aritméticos: multiplicação (*), soma (+), divisão inteira (/) e resto (%).

5. Conclusão

As estruturas sequencial, condicional e iterativa foram utilizadas em conjunto para resolver um problema real. O uso do decimal como base intermediária facilita o algoritmo e permite converter entre quaisquer bases de 2 a 16.
