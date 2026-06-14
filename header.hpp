#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <iostream>
#include <string>

using namespace std;

// ================= PACIENTES =================

struct Paciente{
    int id;
    string nome;
    int idade;
    string cpf;
    string telefone;
    string endereco;
    Paciente* prox = nullptr;
};

struct PacienteLista{
    Paciente* inicio = nullptr;
    int total_list = 0;
};

int empty(PacienteLista& l);
Paciente* buscarPaciente(PacienteLista& l, int valor);
Paciente* proximoPaciente(PacienteLista& l);
int cadastrarPaciente(PacienteLista& l);
int removerPaciente(PacienteLista& l);
void listarPacientes(PacienteLista& l);
int atualizarPaciente(PacienteLista& l);

// ================= MÉDICOS =================

struct Medico{
    int id;
    string nome;
    string especialidade;
    string crm;
    string telefone;
    Medico* prox = nullptr;
};

struct MedicoLista{
    Medico* inicio = nullptr;
    int total_list = 0;
};

int empty(MedicoLista& l);
Medico* buscarMedico(MedicoLista& l, int valor);
Medico* proximoMedico(MedicoLista& l);
int cadastrarMedico(MedicoLista& l);
int removerMedico(MedicoLista& l);
void listarMedicos(MedicoLista& l);
int atualizarMedico(MedicoLista& l);

// ================= MEDICAMENTOS =================

struct Medicamento{
    int id;
    string nome;
    int quantidade;
    string validade;
    Medicamento* prox = nullptr;
};

struct MedicamentoLista{
    Medicamento* inicio = nullptr;
    int total_list = 0;
};

int empty(MedicamentoLista& l);
Medicamento* buscarMedicamento(MedicamentoLista& l, int valor);
Medicamento* proximoMedicamento(MedicamentoLista& l);
int cadastrarMedicamento(MedicamentoLista& l);
int removerMedicamento(MedicamentoLista& l);
void listarMedicamentos(MedicamentoLista& l);
int atualizarMedicamento(MedicamentoLista& l);

// ================= SALAS =================

struct Sala{
    int id;
    int numero;
    int capacidade;
    bool disponivel;
    Sala* prox = nullptr;
};

struct SalaLista{
    Sala* inicio = nullptr;
    int total_list = 0;
};

int empty(SalaLista& l);
Sala* buscarSala(SalaLista& l, int valor);
Sala* proximaSala(SalaLista& l);
int cadastrarSala(SalaLista& l);
int removerSala(SalaLista& l);
void listarSalas(SalaLista& l);
int atualizarSala(SalaLista& l);

// ================= FILA =================

struct NoFila{
    Paciente* paciente = nullptr;
    Medico* medico = nullptr;
    Sala* sala = nullptr;
    NoFila* prox = nullptr;
};

struct FilaLista{
    NoFila* inicio = nullptr;
};

int filaVazia(FilaLista& f);
void enfileirar(FilaLista& f, Paciente* paciente, Medico* medico, Sala* sala);
void desenfileirar(FilaLista& f);
void listarFila(FilaLista& f);

#endif