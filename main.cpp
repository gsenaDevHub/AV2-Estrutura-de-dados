#include <iostream>
#include "header.hpp"

using namespace std;

// ===== MENUS =====

void menuPrincipal(){
    cout << "\n===== SISTEMA HOSPITALAR =====\n";
    cout << "1 - Pacientes\n";
    cout << "2 - Medicos\n";
    cout << "3 - Medicamentos\n";
    cout << "4 - Salas\n";
    cout << "5 - Fila\n";
    cout << "0 - Sair\n";
    cout << "Escolha: ";
}

void menuCRUD(string nome){
    cout << "\n===== " << nome << " =====\n";
    cout << "1 - Cadastrar\n";
    cout << "2 - Listar\n";
    cout << "3 - Buscar\n";
    cout << "4 - Atualizar\n";
    cout << "5 - Remover\n";
    cout << "0 - Voltar\n";
    cout << "Escolha: ";
}

void menuFila(){
    cout << "\n===== FILA =====\n";
    cout << "1 - Enfileirar\n";
    cout << "2 - Atender (Desenfileirar)\n";
    cout << "3 - Listar Fila\n";
    cout << "0 - Voltar\n";
    cout << "Escolha: ";
}

// ===== MAIN =====

int main(){

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

        // ================= PACIENTES =================
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
                        if(buscarPaciente(pacientes,id))
                            cout << "Encontrado!\n";
                        break;
                    }
                    case 4: atualizarPaciente(pacientes); break;
                    case 5: removerPaciente(pacientes); break;
                }

            }while(op2 != 0);
        break;

        // ================= MEDICOS =================
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
                        if(buscarMedico(medicos,id))
                            cout << "Encontrado!\n";
                        break;
                    }
                    case 4: atualizarMedico(medicos); break;
                    case 5: removerMedico(medicos); break;
                }

            }while(op2 != 0);
        break;

        // ================= MEDICAMENTOS =================
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
                        if(buscarMedicamento(medicamentos,id))
                            cout << "Encontrado!\n";
                        break;
                    }
                    case 4: atualizarMedicamento(medicamentos); break;
                    case 5: removerMedicamento(medicamentos); break;
                }

            }while(op2 != 0);
        break;

        // ================= SALAS =================
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
                        if(buscarSala(salas,id))
                            cout << "Encontrado!\n";
                        break;
                    }
                    case 4: atualizarSala(salas); break;
                    case 5: removerSala(salas); break;
                }

            }while(op2 != 0);
        break;

        }

    }while(op != 0);

    cout << "\nEncerrando sistema...\n";
    return 0;
}