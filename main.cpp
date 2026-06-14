#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "header.hpp"

using namespace std;

void limparTela() {
    system("cls");
}

void mudarCor(int cor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

void configurarCharEspeciais() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

void esperar5Segundos() {
    Sleep(5000);
}

void menuPrincipal(){
    limparTela();
    mudarCor(11);
    cout << "\n===== SISTEMA HOSPITALAR =====\n";
    mudarCor(7);
    cout << "1 - Pacientes\n";
    cout << "2 - Medicos\n";
    cout << "3 - Medicamentos\n";
    cout << "4 - Salas\n";
    cout << "5 - Fila\n";
    cout << "0 - Sair" << endl;
    mudarCor(14);
    cout << "Escolha: ";
    mudarCor(7);
}

void menuCRUD(string nome){
    limparTela();
    mudarCor(10);
    cout << "\n===== " << nome << " =====\n";
    mudarCor(7);
    cout << "1 - Cadastrar\n";
    cout << "2 - Listar\n";
    cout << "3 - Buscar\n";
    cout << "4 - Atualizar\n";
    cout << "5 - Remover\n";
    cout << "0 - Sair" << endl;
    mudarCor(14);
    cout << "Escolha: ";
    mudarCor(7);
}

void menuFila(){
    limparTela();
    mudarCor(13);
    cout << "\n===== FILA =====\n";
    mudarCor(7);
    cout << "1 - Enfileirar\n";
    cout << "2 - Atender\n";
    cout << "3 - Listar Fila\n";
    cout << "0 - Sair" << endl;
    mudarCor(14);
    cout << "Escolha: ";
    mudarCor(7);
}

int main(){
    configurarCharEspeciais();
    
    PacienteLista pacientes;
    MedicoLista medicos;
    MedicamentoLista medicamentos;
    SalaLista salas;
    FilaLista fila;
    
    int op, op2;
    
    do{
        menuPrincipal();
        cin >> op;
        
        switch(op){
            case 1:
                do{
                    menuCRUD("PACIENTES");
                    cin >> op2;
                    
                    switch(op2){
                        case 1: cadastrarPaciente(pacientes); break;
                        case 2: listarPacientes(pacientes); break;
                        case 3:{
                            int id;
                            cout << "ID: ";
                            cin >> id;
                            if(buscarPaciente(pacientes, id)) {
                                mudarCor(10);
                                cout << "Encontrado!\n";
                                mudarCor(7);
                            }
                            break;
                        }
                        case 4: atualizarPaciente(pacientes); break;
                        case 5: removerPaciente(pacientes); break;
                    }
                    esperar5Segundos();
                }while(op2 != 0);
                break;
            
            case 2:
                do{
                    menuCRUD("MEDICOS");
                    cin >> op2;
                    
                    switch(op2){
                        case 1: cadastrarMedico(medicos); break;
                        case 2: listarMedicos(medicos); break;
                        case 3:{
                            int id;
                            cout << "ID: ";
                            cin >> id;
                            if(buscarMedico(medicos, id)) {
                                mudarCor(10);
                                cout << "Encontrado!\n";
                                mudarCor(7);
                            }
                            break;
                        }
                        case 4: atualizarMedico(medicos); break;
                        case 5: removerMedico(medicos); break;
                    }
                    esperar5Segundos();
                }while(op2 != 0);
                break;
            
            case 3:
                do{
                    menuCRUD("MEDICAMENTOS");
                    cin >> op2;
                    
                    switch(op2){
                        case 1: cadastrarMedicamento(medicamentos); break;
                        case 2: listarMedicamentos(medicamentos); break;
                        case 3:{
                            int id;
                            cout << "ID: ";
                            cin >> id;
                            if(buscarMedicamento(medicamentos, id)) {
                                mudarCor(10);
                                cout << "Encontrado!\n";
                                mudarCor(7);
                            }
                            break;
                        }
                        case 4: atualizarMedicamento(medicamentos); break;
                        case 5: removerMedicamento(medicamentos); break;
                    }
                    esperar5Segundos();
                }while(op2 != 0);
                break;
            
            case 4:
                do{
                    menuCRUD("SALAS");
                    cin >> op2;
                    
                    switch(op2){
                        case 1: cadastrarSala(salas); break;
                        case 2: listarSalas(salas); break;
                        case 3:{
                            int id;
                            cout << "ID: ";
                            cin >> id;
                            if(buscarSala(salas, id)) {
                                mudarCor(10);
                                cout << "Encontrado!\n";
                                mudarCor(7);
                            }
                            break;
                        }
                        case 4: atualizarSala(salas); break;
                        case 5: removerSala(salas); break;
                    }
                    esperar5Segundos();
                }while(op2 != 0);
                break;
            
            case 5:
                do{
                    menuFila();
                    cin >> op2;

                    switch(op2){
                        case 1:
                            enfileirar(fila, pacientes, medicos, salas);

                            mudarCor(10);
                            cout << "Paciente enfileirado!\n";
                            mudarCor(7);
                            break;

                        case 2:
                            desenfileirar(fila);

                            mudarCor(10);
                            cout << "Paciente atendido!\n";
                            mudarCor(7);
                            break;

                        case 3:
                            listarFila(fila);
                            break;
                    }

                    esperar5Segundos();

                }while(op2 != 0);
                break;
        }
    }while(op != 0);
    
    limparTela();
    mudarCor(10);
    cout << "\n===== SISTEMA ENCERRADO =====\n";
    mudarCor(7);
    
    return 0;
}