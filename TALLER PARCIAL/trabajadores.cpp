#include <iostream>
#include <algorithm>

const int NUM_TRABAJADORES = 5;
const float VALOR_HORA_EXTRA = 0.75;

struct Trabajador {
    float salarioBase;
    float auxTrans;
    float bonificacion;
    float vacaciones;
    int horasExtras;
};

int main() {
    Trabajador trabajadores[NUM_TRABAJADORES];
    float salariosTotal = 0;
    float auxTransTotal = 0;
    float bonificacionesTotal = 0;
    float vacacionesTotal = 0;
    int horasExtrasTotal = 0;

    // Entrada de datos de los trabajadores
    for (int i = 0; i < NUM_TRABAJADORES; i++) {
        std::cout << "Ingrese los datos del Trabajador " << i + 1 << ":" << endl;
        std::cout << "Salario base: $";
        cin >> trabajadores[i].salarioBase;
        cout << "Auxilio de transporte: $";
        cin >> trabajadores[i].auxTrans;
        cout << "Bonificación: $";
        cin >> trabajadores[i].bonificacion;
        cout << "Vacaciones: $";
        cin >> trabajadores[i].vacaciones;
        cout << "Horas extras trabajadas: ";
        cin >> trabajadores[i].horasExtras;

        salariosTotal += trabajadores[i].salarioBase;
        auxTransTotal += trabajadores[i].auxTrans;
        bonificacionesTotal += trabajadores[i].bonificacion;
        vacacionesTotal += trabajadores[i].vacaciones;
        horasExtrasTotal += trabajadores[i].horasExtras;
    }

    // Calcular pagos y estadísticas
    float totalNomina = 0;
    float salarioMasBajo = trabajadores[0].salarioBase;
    float salarioMasAlto = trabajadores[0].salarioBase;

    for (int i = 0; i < NUM_TRABAJADORES; i++) {
        float valorHora = trabajadores[i].salarioBase / 30 / 8;
        float pagoHorasExtras = trabajadores[i].horasExtras * valorHora * VALOR_HORA_EXTRA;
        float pagoTotal = trabajadores[i].salarioBase + trabajadores[i].bonificacion + trabajadores[i].auxTrans + trabajadores[i].vacaciones + pagoHorasExtras;

        totalNomina += pagoTotal;
        salarioMasBajo =std::min(salarioMasBajo, trabajadores[i].salarioBase);
        salarioMasAlto = std::max(salarioMasAlto, trabajadores[i].salarioBase);
    }

    float mediaNomina = totalNomina / NUM_TRABAJADORES;

    // Mostrar resultados
    std::cout << "\n--- Resultados de la Nómina ---" << std::endl;
    std::cout << "Pago total de cada trabajador:" << std::endl;
    for (int i = 0; i < NUM_TRABAJADORES; i++) {
        float valorHora = trabajadores[i].salarioBase / 30 / 8;
        float pagoHorasExtras = trabajadores[i].horasExtras * valorHora * VALOR_HORA_EXTRA;
        float pagoTotal = trabajadores[i].salarioBase + trabajadores[i].bonificacion + trabajadores[i].auxTrans + trabajadores[i].vacaciones + pagoHorasExtras;
        cout << "Trabajador " << i + 1 << ": $" << pagoTotal << endl;
    }

    cout << "\nSalario más bajo: $" << salarioMasBajo << endl;
    cout << "Salario más alto: $" << salarioMasAlto << endl;
    cout << "Media del total de la nómina: $" << mediaNomina << endl;
    cout << "Total de la nómina: $" << totalNomina << endl;
    cout << "Informe Detallado:" << endl;
    cout << "Suma total de salario base: $" << salariosTotal << endl;
    cout << "Suma total de auxilio de transporte: $" << auxTransTotal << endl;
    cout << "Suma total de bonificaciones: $" << bonificacionesTotal << endl;
    cout << "Suma total de vacaciones: $" << vacacionesTotal << endl;
    cout << "Total de horas extras: " << horasExtrasTotal << " horas" << endl;

    return 0;
}
