#include <iostream>

using namespace std;

int main() {
    int opcao;

    do {
        cout << "\n===== Conversor de bases =====\n";
        cout << "1 - Converter numero entre bases (2 a 16)\n";
        cout << "2 - Calculadora em uma base (2 a 16)\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        long long resultado = 0;
        int baseSaida = 10;
        bool valido = true;

        if (opcao == 1 || opcao == 2) {
            int baseEntrada;
            int qtdNumeros;
            char operacao = '+';

            if (opcao == 1) {
                int baseDestino;
                cout << "Base de origem (2 a 16): ";
                cin >> baseEntrada;
                cout << "Base de destino (2 a 16): ";
                cin >> baseDestino;
                baseSaida = baseDestino;
                qtdNumeros = 1;
                if (baseDestino < 2 || baseDestino > 16) valido = false;
            } else {
                cout << "Base (2 a 16): ";
                cin >> baseEntrada;
                baseSaida = baseEntrada;
                qtdNumeros = 2;
                cout << "Operacao (+, -, *, /): ";
                cin >> operacao;
            }

            if (baseEntrada < 2 || baseEntrada > 16) valido = false;

            if (!valido) {
                cout << "Erro: as bases devem estar entre 2 e 16.\n";
            } else {
                long long numeros[2] = {0, 0};

                // Le cada numero digito a digito (como texto) e converte para decimal
                for (int k = 0; k < qtdNumeros && valido; k++) {
                    cout << "Digite o " << k + 1 << "o numero (base "
                         << baseEntrada << "): ";
                    cin >> ws;
                    int c = cin.get();
                    bool negativo = false;
                    long long valor = 0;

                    if (c == '-') {
                        negativo = true;
                        c = cin.get();
                    }
                    while (c != '\n' && c != ' ' && c != EOF) {
                        int d;
                        if (c >= '0' && c <= '9') d = c - '0';
                        else if (c >= 'A' && c <= 'F') d = c - 'A' + 10;
                        else if (c >= 'a' && c <= 'f') d = c - 'a' + 10;
                        else d = -1;

                        if (d < 0 || d >= baseEntrada) valido = false;
                        else valor = valor * baseEntrada + d;
                        c = cin.get();
                    }
                    if (!valido) cout << "Erro: digito invalido para a base "
                                      << baseEntrada << ".\n";
                    if (negativo) valor = -valor;
                    numeros[k] = valor;
                }

                if (valido) {
                    if (opcao == 1) {
                        resultado = numeros[0];
                    } else {
                        switch (operacao) {
                            case '+': resultado = numeros[0] + numeros[1]; break;
                            case '-': resultado = numeros[0] - numeros[1]; break;
                            case '*': resultado = numeros[0] * numeros[1]; break;
                            case '/':
                                if (numeros[1] == 0) {
                                    cout << "Erro: divisao por zero.\n";
                                    valido = false;
                                } else {
                                    resultado = numeros[0] / numeros[1];
                                    cout << "(divisao inteira; resto em decimal = "
                                         << numeros[0] % numeros[1] << ")\n";
                                }
                                break;
                            default:
                                cout << "Erro: operacao invalida.\n";
                                valido = false;
                        }
                    }
                }

                // Escreve o resultado na base de saida, do digito mais significativo ao menos
                if (valido) {
                    cout << "Resultado (base " << baseSaida << "): ";
                    if (resultado < 0) {
                        cout << "-";
                        resultado = -resultado;
                    }
                    if (resultado == 0) {
                        cout << "0";
                    } else {
                        long long potencia = 1;
                        while (potencia <= resultado / baseSaida)
                            potencia *= baseSaida;

                        while (potencia > 0) {
                            int d = resultado / potencia;
                            if (d < 10) cout << (char)('0' + d);
                            else cout << (char)('A' + d - 10);
                            resultado = resultado % potencia;
                            potencia /= baseSaida;
                        }
                    }
                    cout << endl;
                }
            }
        } else if (opcao != 0) {
            cout << "Opcao invalida.\n";
        }

    } while (opcao != 0);

    cout << "Finalizado \n";
    return 0;
}
