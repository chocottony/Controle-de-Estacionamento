#include <iostream>
#include <locale>
#include <cstring>
#include <iomanip>
#include <vector>

struct Horas {
    int hora;
    int minuto;
};

struct carro {
    char placa[9];
    Horas HoraEntrada;
    Horas HoraSaída;
    Horas tempo;
    float ValorPago;
};

struct data {
    int dia;
    int mes;
    int ano;
};

int DiferencaMinutos (Horas h1, Horas h2) {
    int minutos1, minutos2;

    minutos1 = h1.hora * 60 + h1.minuto;
    minutos2 = h2.hora * 60 + h2.minuto;

    return minutos2 - minutos1;
    
}

Horas DiferençaHorarios (Horas h1, Horas h2) {
    Horas resultado; 
    int minutos1, minutos2, diferença;

    minutos1 = h1.hora * 60 + h1.minuto;
    minutos2 = h2.hora * 60 + h2.minuto;

    diferença = minutos2 - minutos1;
    resultado.hora = diferença / 60;
    resultado.minuto = diferença % 60;

    return resultado;
    
}

float valorapagar (Horas h1, Horas h2, float valor) {
    float valorMinuto; 
    int minutos;

    minutos = DiferencaMinutos(h1, h2);
    valorMinuto = valor / 60;

    return minutos * valorMinuto;
    
}

int main () {
    setlocale (LC_ALL, "pt_BR.utf8");
    

        int i = 0, j, k, opcão;
        float pagar, valor, total = 0;
        std::vector<carro> cliente;
        Horas h1, h2, resultado;
        data hoje;
        carro novoCliente;
        char placaBusca[9];
        bool encontrado = false;

        std::cout << " \n Olá, bem-vindo!\n Informe a data de hoje (dd mm aaaa): ";
        std::cin >> hoje.dia >> hoje.mes >> hoje.ano;

        std::cout << " Qual o valor da hora do estacionamento (usar ponto para centavos): R$";
        std::cin >> valor;

    do{
        std::cout << "\n ======== Menu ========\n"; 
        std::cout << " 1 - Registro de cliente\n 2 - Registro de saída\n 3 - Finalizar dia\n";
        std::cout << " Opção desejada: ";
        std::cin >> opcão;

        switch (opcão) {
            case 1: {
                std::cout << "\n Placa do carro: ";
                std::cin >> novoCliente.placa;

                do {
                    std::cout << " Hora de entrada (hh mm): ";
                    std::cin >> novoCliente.HoraEntrada.hora >> novoCliente.HoraEntrada.minuto;
                    if ((novoCliente.HoraEntrada.hora < 0 || novoCliente.HoraEntrada.hora > 23) || (novoCliente.HoraEntrada.minuto < 00 || novoCliente.HoraEntrada.minuto > 59)) {
                        std::cout << " Hora inválida. Tenta novamente...\n";
                    }
                } while ((novoCliente.HoraEntrada.hora < 0 || novoCliente.HoraEntrada.hora > 23) || (novoCliente.HoraEntrada.minuto < 0 || novoCliente.HoraEntrada.minuto > 59));

                cliente.push_back(novoCliente);
                std::cout << " Cliente registrado com sucesso!\n";
        
                break;
            }

            case 2:{
                encontrado = false;

                std::cout << "\n Placa para saída: ";
                std::cin >> placaBusca;

                for (j = 0; j < cliente.size(); j++) {
                    if (strcmp(cliente[j].placa, placaBusca) == 0) {
                        std::cout << " Carro encontrado!\n";
                        h1.hora = cliente[j].HoraEntrada.hora; 
                        h1.minuto = cliente[j].HoraEntrada.minuto;
                        encontrado = true;
                        break;
                    }
                }

                if (!encontrado) {
                    std::cout << " Nenhum carro com essa placa foi encontrado.\n";
                    break;
                }
        
                std::cout << " Digite a hora da saída (hh mm): ";
                std::cin >> h2.hora >> h2.minuto;
                cliente[j].HoraSaída.hora = h2.hora;
                cliente[j].HoraSaída.minuto = h2.minuto;

                resultado = DiferençaHorarios(h1, h2);
                cliente[j].tempo = resultado;
                pagar = valorapagar(h1, h2, valor);
                cliente[j].ValorPago = pagar;
                total = total + pagar;

                std::cout << "\n ============== RECIBO DO ESTACIONAMENTO ============== ";
                std::cout << "\n Placa: " << placaBusca << "\n";
                std::cout << " Entrada: " << h1.hora << ":" << std::setw(2) << std::setfill('0') << h1.minuto << "\n";
                std::cout << " Saída: " << h2.hora << ":" << std::setw(2) << std::setfill('0') << h2.minuto << "\n";
                std::cout << " Tempo decorrido: " << resultado.hora << "h " << resultado.minuto << "min\n";
                std::cout << " Total a pagar: R$" << std::fixed << std::setprecision(2) << pagar << "\n";
                std::cout << " ======================================================\n";

                break;
            }

            case 3:{
                std::cout << "\n--------------------------- Relatório do dia ---------------------------\n";
                std::cout << "                               " << hoje.dia << "/" << hoje.mes << "/" << hoje.ano << "                               \n";
                std::cout << "\nPlaca\t\tEntrada\t\tSaída\t\tTempo\t\tValor\n";

                for (int k = 0; k < cliente.size(); k++) {
                    std::cout << "------------------------------------------------------------------------\n";
                    std::cout << cliente[k].placa << "\t\t"
                        << cliente[k].HoraEntrada.hora << ":" << std::setw(2) << std::setfill('0') << cliente[k].HoraEntrada.minuto << "\t\t"
                        << cliente[k].HoraSaída.hora << ":" << std::setw(2) << std::setfill('0') << cliente[k].HoraSaída.minuto << "\t\t"
                        << cliente[k].tempo.hora * 60 + cliente[k].tempo.minuto << "min\t\t"
                        << "R$" << std::fixed << std::setprecision(2) << cliente[k].ValorPago << "\n";
                }

                    std::cout << "\nTotal arrecadado: R$" << std::fixed << std::setprecision(2) << total;
                    std::cout << "\n------------------------------------------------------------------------\n";

                break;
            }
        } 

    } while (opcão != 3);

    std::cout << "\n Programa encerrado. Pressione ENTER para sair.";
    std::cin.ignore();
    std::cin.get();

    return 0;
}