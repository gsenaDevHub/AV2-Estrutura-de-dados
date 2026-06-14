#include "header.hpp"
#include <iostream>
#include <string>
using namespace std;

// ================= PACIENTES =================

int empty(PacienteLista &l){
    if(l.inicio == nullptr){
        cout << "Não há pacientes no consultorio!" << endl;
        return 0;
    }
    return 1;
}

Paciente* buscarPaciente(PacienteLista &l, int valor){
    if(empty(l) == 0) return nullptr;
    Paciente* aux = l.inicio;
    while(aux->id != valor && aux->prox != nullptr)
        aux = aux->prox;
    if(aux->id != valor){ cout << "Paciente não encontrado!" << endl; return nullptr; }
    return aux;
}

Paciente* proximoPaciente(PacienteLista &l){
    if(empty(l) == 0) return nullptr;
    Paciente* aux = l.inicio;
    while(aux->prox != nullptr) aux = aux->prox;
    return aux;
}

int cadastrarPaciente(PacienteLista &l){
    Paciente* novo = new Paciente();
    novo->id = ++l.total_list;
    cin.ignore();
    cout << "Digite o nome do paciente: ";
    getline(cin, novo->nome);
    cout << "Digite a idade do paciente: ";
    cin >> novo->idade;
    cin.ignore();
    cout << "Digite o cpf do paciente: ";
    getline(cin, novo->cpf);
    cout << "Digite o telefone do paciente: ";
    getline(cin, novo->telefone);
    cout << "Digite o endereço do paciente: ";
    getline(cin, novo->endereco);
    novo->prox = nullptr;
    if(l.inicio == nullptr){ l.inicio = novo; return 1; }
    proximoPaciente(l)->prox = novo;
    return 1;
}

int removerPaciente(PacienteLista &l){
    int valor;
    if(empty(l) == 0) return 0;
    cout << "Qual paciente você gostaria de remover: " << endl;
    cin >> valor;
    Paciente* aux = buscarPaciente(l, valor);
    if(aux == nullptr) return 0;
    if(aux == l.inicio){
        l.inicio = aux->prox;
        delete aux;
        return 1;
    }
    Paciente* anterior = l.inicio;
    while(anterior->prox != nullptr && anterior->prox != aux)
        anterior = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    return 1;
}

void listarPacientes(PacienteLista &l){
    if(empty(l) == 0) return;
    Paciente* aux = l.inicio;
    int cont = 1;
    cout << "=========== Lista Pacientes ===========" << endl;
    while(aux != nullptr){
        cout << "Paciente " << cont++ << endl;
        cout << aux->nome << endl;
        aux = aux->prox;
    }
    cout << "=======================================" << endl;
}

int atualizarPaciente(PacienteLista &l){
    int valor, op;
    if(empty(l) == 0) return 1;
    cin >> valor;
    Paciente* aux = buscarPaciente(l, valor);
    if(aux == nullptr) return 1;
    do{
        cout << "1-Nome\n2-Idade\n3-CPF\n4-Tel\n5-End\n6-Sair: ";
        cin >> op;
        switch(op){
            case 1: cout << "Digite um novo nome: ";      cin.ignore(); getline(cin, aux->nome);      break;
            case 2: cout << "Digite uma nova idade: ";    cin >> aux->idade;                          break;
            case 3: cout << "Digite um novo CPF: ";       cin.ignore(); getline(cin, aux->cpf);       break;
            case 4: cout << "Digite um novo telefone: ";  cin.ignore(); getline(cin, aux->telefone);  break;
            case 5: cout << "Digite um novo endereço: ";  cin.ignore(); getline(cin, aux->endereco);  break;
            case 6: cout << "Saindo..." << endl; break;
            default: cout << "Valor invalido" << endl;
        }
    }while(op != 6);
    return 0;
}

// ================= MÉDICOS =================

int empty(MedicoLista &l){
    if(l.inicio == nullptr){
        cout << "Não há médicos cadastrados!" << endl;
        return 0;
    }
    return 1;
}

Medico* buscarMedico(MedicoLista &l, int valor){
    if(empty(l) == 0) return nullptr;
    Medico* aux = l.inicio;
    while(aux->id != valor && aux->prox != nullptr)
        aux = aux->prox;
    if(aux->id != valor){ cout << "Médico não encontrado!" << endl; return nullptr; }
    return aux;
}

Medico* proximoMedico(MedicoLista &l){
    if(empty(l) == 0) return nullptr;
    Medico* aux = l.inicio;
    while(aux->prox != nullptr) aux = aux->prox;
    return aux;
}

int cadastrarMedico(MedicoLista &l){
    Medico* novo = new Medico();
    novo->id = ++l.total_list;
    cin.ignore();
    cout << "Digite o nome do médico: ";
    getline(cin, novo->nome);
    cout << "Digite a especialidade: ";
    getline(cin, novo->especialidade);
    cout << "Digite o CRM: ";
    getline(cin, novo->crm);
    cout << "Digite o telefone: ";
    getline(cin, novo->telefone);
    novo->prox = nullptr;
    if(l.inicio == nullptr){ l.inicio = novo; return 1; }
    proximoMedico(l)->prox = novo;
    return 1;
}

int removerMedico(MedicoLista &l){
    int valor;
    if(empty(l) == 0) return 0;
    cout << "Qual médico você gostaria de remover: " << endl;
    cin >> valor;
    Medico* aux = buscarMedico(l, valor);
    if(aux == nullptr) return 0;
    if(aux == l.inicio){
        l.inicio = aux->prox;
        delete aux;
        return 1;
    }
    Medico* anterior = l.inicio;
    while(anterior->prox != nullptr && anterior->prox != aux)
        anterior = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    return 1;
}

void listarMedicos(MedicoLista &l){
    if(empty(l) == 0) return;
    Medico* aux = l.inicio;
    int cont = 1;
    cout << "=========== Lista Médicos ===========" << endl;
    while(aux != nullptr){
        cout << "Médico " << cont++ << endl;
        cout << aux->nome << endl;
        aux = aux->prox;
    }
    cout << "=====================================" << endl;
}

int atualizarMedico(MedicoLista &l){
    int valor, op;
    if(empty(l) == 0) return 1;
    cin >> valor;
    Medico* aux = buscarMedico(l, valor);
    if(aux == nullptr) return 1;
    do{
        cout << "1-Nome\n2-Especialidade\n3-CRM\n4-Telefone\n5-Sair: ";
        cin >> op;
        switch(op){
            case 1: cout << "Digite um novo nome: ";           cin.ignore(); getline(cin, aux->nome);          break;
            case 2: cout << "Digite uma nova especialidade: "; cin.ignore(); getline(cin, aux->especialidade); break;
            case 3: cout << "Digite um novo CRM: ";            cin.ignore(); getline(cin, aux->crm);           break;
            case 4: cout << "Digite um novo telefone: ";       cin.ignore(); getline(cin, aux->telefone);      break;
            case 5: cout << "Saindo..." << endl; break;
            default: cout << "Valor invalido" << endl;
        }
    }while(op != 5);
    return 0;
}

// ================= MEDICAMENTOS =================

int empty(MedicamentoLista &l){
    if(l.inicio == nullptr){
        cout << "Não há medicamentos cadastrados!" << endl;
        return 0;
    }
    return 1;
}

Medicamento* buscarMedicamento(MedicamentoLista &l, int valor){
    if(empty(l) == 0) return nullptr;
    Medicamento* aux = l.inicio;
    while(aux->id != valor && aux->prox != nullptr)
        aux = aux->prox;
    if(aux->id != valor){ cout << "Medicamento não encontrado!" << endl; return nullptr; }
    return aux;
}

Medicamento* proximoMedicamento(MedicamentoLista &l){
    if(empty(l) == 0) return nullptr;
    Medicamento* aux = l.inicio;
    while(aux->prox != nullptr) aux = aux->prox;
    return aux;
}

int cadastrarMedicamento(MedicamentoLista &l){
    Medicamento* novo = new Medicamento();
    novo->id = ++l.total_list;
    cin.ignore();
    cout << "Digite o nome do medicamento: ";
    getline(cin, novo->nome);
    cout << "Digite a quantidade: ";
    cin >> novo->quantidade;
    cin.ignore();
    cout << "Digite a validade: ";
    getline(cin, novo->validade);
    novo->prox = nullptr;
    if(l.inicio == nullptr){ l.inicio = novo; return 1; }
    proximoMedicamento(l)->prox = novo;
    return 1;
}

int removerMedicamento(MedicamentoLista &l){
    int valor;
    if(empty(l) == 0) return 0;
    cout << "Qual medicamento você gostaria de remover: " << endl;
    cin >> valor;
    Medicamento* aux = buscarMedicamento(l, valor);
    if(aux == nullptr) return 0;
    if(aux == l.inicio){
        l.inicio = aux->prox;
        delete aux;
        return 1;
    }
    Medicamento* anterior = l.inicio;
    while(anterior->prox != nullptr && anterior->prox != aux)
        anterior = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    return 1;
}

void listarMedicamentos(MedicamentoLista &l){
    if(empty(l) == 0) return;
    Medicamento* aux = l.inicio;
    int cont = 1;
    cout << "=========== Lista Medicamentos ===========" << endl;
    while(aux != nullptr){
        cout << "Medicamento " << cont++ << endl;
        cout << aux->nome << endl;
        aux = aux->prox;
    }
    cout << "==========================================" << endl;
}

int atualizarMedicamento(MedicamentoLista &l){
    int valor, op;
    if(empty(l) == 0) return 1;
    cin >> valor;
    Medicamento* aux = buscarMedicamento(l, valor);
    if(aux == nullptr) return 1;
    do{
        cout << "1-Nome\n2-Quantidade\n3-Validade\n4-Sair: ";
        cin >> op;
        switch(op){
            case 1: cout << "Digite um novo nome: ";        cin.ignore(); getline(cin, aux->nome);     break;
            case 2: cout << "Digite uma nova quantidade: "; cin >> aux->quantidade;                    break;
            case 3: cout << "Digite uma nova validade: ";   cin.ignore(); getline(cin, aux->validade); break;
            case 4: cout << "Saindo..." << endl; break;
            default: cout << "Valor invalido" << endl;
        }
    }while(op != 4);
    return 0;
}

// ================= SALAS =================

int empty(SalaLista &l){
    if(l.inicio == nullptr){
        cout << "Não há salas cadastradas!" << endl;
        return 0;
    }
    return 1;
}

Sala* buscarSala(SalaLista &l, int valor){
    if(empty(l) == 0) return nullptr;
    Sala* aux = l.inicio;
    while(aux->id != valor && aux->prox != nullptr)
        aux = aux->prox;
    if(aux->id != valor){ cout << "Sala não encontrada!" << endl; return nullptr; }
    return aux;
}

Sala* proximaSala(SalaLista &l){
    if(empty(l) == 0) return nullptr;
    Sala* aux = l.inicio;
    while(aux->prox != nullptr) aux = aux->prox;
    return aux;
}

int cadastrarSala(SalaLista &l){
    Sala* novo = new Sala();
    novo->id = ++l.total_list;
    cout << "Digite o número da sala: ";
    cin >> novo->numero;
    cout << "Digite a capacidade: ";
    cin >> novo->capacidade;
    novo->disponivel = true;
    novo->prox = nullptr;
    if(l.inicio == nullptr){ l.inicio = novo; return 1; }
    proximaSala(l)->prox = novo;
    return 1;
}

int removerSala(SalaLista &l){
    int valor;
    if(empty(l) == 0) return 0;
    cout << "Qual sala você gostaria de remover: " << endl;
    cin >> valor;
    Sala* aux = buscarSala(l, valor);
    if(aux == nullptr) return 0;
    if(aux == l.inicio){
        l.inicio = aux->prox;
        delete aux;
        return 1;
    }
    Sala* anterior = l.inicio;
    while(anterior->prox != nullptr && anterior->prox != aux)
        anterior = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    return 1;
}

void listarSalas(SalaLista &l){
    if(empty(l) == 0) return;
    Sala* aux = l.inicio;
    int cont = 1;
    cout << "=========== Lista Salas ===========" << endl;
    while(aux != nullptr){
        cout << "Sala " << cont++ << endl;
        cout << "Numero: " << aux->numero
             << " | Capacidade: " << aux->capacidade
             << " | Disponivel: " << (aux->disponivel ? "Sim" : "Não") << endl;
        aux = aux->prox;
    }
    cout << "===================================" << endl;
}

int atualizarSala(SalaLista &l){
    int valor, op;
    if(empty(l) == 0) return 1;
    cin >> valor;
    Sala* aux = buscarSala(l, valor);
    if(aux == nullptr) return 1;
    do{
        cout << "1-Numero\n2-Capacidade\n3-Disponibilidade\n4-Sair: ";
        cin >> op;
        switch(op){
            case 1: cout << "Digite um novo numero: ";     cin >> aux->numero;     break;
            case 2: cout << "Digite uma nova capacidade: ";cin >> aux->capacidade; break;
            case 3: aux->disponivel = !aux->disponivel;
                    cout << "Disponibilidade alterada para: " << (aux->disponivel ? "Sim" : "Não") << endl; break;
            case 4: cout << "Saindo..." << endl; break;
            default: cout << "Valor invalido" << endl;
        }
    }while(op != 4);
    return 0;
}
