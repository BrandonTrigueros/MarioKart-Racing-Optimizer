#include "common.hpp"


class Controller {
    private:
        part_s* ruedas;
        part_s* planeadores;
        part_s* carros;
        part_s* motos;
        Conductor* conductores [12];      
        
    public:
        Controller ()
        : ruedas (nullptr)
        , planeadores(nullptr)
        , carros(nullptr)
        , motos(nullptr) {}
        
        part_s* read_esta () {
            std::string nombre_partes;
            int numero_partes;
            std::getline(std::cin, nombre_partes, ',');
            std::cin >> numero_partes;
            part_s* partes = new part_s [numero_partes + 1];
            partes[0].nombre = nombre_partes;
            partes[0].velocidad = numero_partes;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for (int i = 1; i < numero_partes + 1; ++i) {
                std::getline(std::cin, partes[i].nombre, ',');
                std::cin >> partes[i].velocidad;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return partes;
        }
        
        void read_partes () {
            this->ruedas = read_esta();
            this->planeadores = read_esta();
            this->carros = read_esta();
            this->motos = read_esta();
        }
        
        bool buscar_parte (part_s* partes, std::string nombre, part_s& parte) {
            for (int i = 1; i < partes[0].velocidad + 1; ++i) {
                if (partes[i].nombre == nombre) {
                    parte = partes[i];
                    return true;
                }
            }
            return false;
        }
        
        void read_conductores (int& d_tierra, int& d_agua, int& d_aire) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> d_tierra >> d_agua >> d_aire;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            std::string tag, personaje, vehiculo, ruedas, planeador;
            part_s ruedas_s, planeador_s, vehiculo_s;
            
            for (int i = 0; i < 12; ++i) {
                std::getline(std::cin, tag, ',');
                std::getline(std::cin, personaje, ',');
                std::getline(std::cin, vehiculo, ',');
                std::getline(std::cin, ruedas, ',');
                std::getline(std::cin, planeador, '\n');
                
                if (!buscar_parte(this->ruedas, ruedas, ruedas_s) || !buscar_parte(this->planeadores, planeador, planeador_s)) {
                    conductores[i] = new Conductor(tag, personaje);
                }
                else {
                    if (buscar_parte(this->carros, vehiculo, vehiculo_s)) {
                        conductores[i] = new ConductorCarro (tag, personaje, ruedas_s, planeador_s, vehiculo_s);
                    }
                    else if (buscar_parte(this->motos, vehiculo, vehiculo_s)) {
                        conductores[i] = new ConductorMoto (tag, personaje, ruedas_s, planeador_s, vehiculo_s);
                    }
                    else {
                        conductores[i] = new Conductor(tag, personaje);
                    }
                }
            }
        }
        
        void mostrar_stats (Conductor* conductores[], int d_tierra, int d_agua, int d_aire) {
            for (int i = 0; i < 12; ++i) {
                if (conductores[i]->getValido()) {
                    double tiempo = (conductores[i]->get_vel_tierra()) + (conductores[i]->get_vel_agua()) + (d_aire / conductores[i]->get_vel_aire());
                    std::cout << conductores[i]->getTag() << " " << conductores[i]->getPersonaje() << ": " << tiempo << std::endl;  
                }
                else {
                    std::cout << conductores[i]->getTag() << " " << conductores[i]->getPersonaje() << ": invalid config" << std::endl;
                }
            }
        }
        
        void run () {
            this->read_partes();
            int d_tierra, d_agua, d_aire;
            this->read_conductores(d_tierra, d_agua, d_aire);
            this->mostrar_stats(this->conductores, d_tierra, d_agua, d_aire);
        }
};