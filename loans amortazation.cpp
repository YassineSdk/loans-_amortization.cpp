#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Fonction pour calculer le paiement mensuel
double calculerPaiementMensuel(double capital, int nbPaiements) {
    return capital / nbPaiements;
}

// Fonction pour calculer les intérêts
double calculerInterets(double capital, double tauxInteretAnnuel) {
    double tauxInteretMensuel = tauxInteretAnnuel / 12 / 100;
    return capital * tauxInteretMensuel;
}

int main() {
    double capital;
    double tauxInteretAnnuel;
    int nbPaiements;

    cout << "Entrer le montant du prêt :\n";
    cin >> capital;
    cout << "Entrer le taux d'intérêt annuel en % :\n";
    cin >> tauxInteretAnnuel;
    cout << "Entrer le nombre de paiements :\n";
    cin >> nbPaiements;
    cout.setf(ios::fixed);
    cout.precision(2);

    double paiementMensuel = calculerPaiementMensuel(capital, nbPaiements);
        cout << setw(7) << "Mois" << setw(12) << "CRD" << setw(15) << "Intérêts" << setw(20) << "Amortissement" << setw(12) << "Annuité" << endl;
    cout << string(66, '-') << endl; // Separator line



    double solde = capital;
    for (int i = 1; i <= nbPaiements; i++) {
        double interets = calculerInterets(solde, tauxInteretAnnuel);
        double annuite = interets + paiementMensuel;
        solde -= paiementMensuel;

        cout << setw(7) << i << setw(12) << solde << setw(15) << interets << setw(20) << paiementMensuel << setw(12) << annuite << endl;
    }

    return 0;
}