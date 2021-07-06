// Finde die Anzahl der nicht negativen Elemente in einer Liste
// Beispiel: [7, -5, -16, -8, 12] -> 2 Elemente sind nicht negativ.
#include <iostream>
#include <vector>

using namespace std;

int nonNegative(vector<int> arr, int idx1, int idx2) {
    // breche solange das Problem runter bis Größe = 1 
    if(idx1 >= idx2) {
        return arr.at(idx1) >= 0 ? 1 : 0;
    }
    int middle = (idx1 + idx2) / 2; 
    // Teile Aufgabe in 2 Teilaufgaben (links und rechts)
    return nonNegative(arr, idx1, middle) + nonNegative(arr, middle+1, idx2);
}

int main() {
    vector<int> arr = { 7, -5, -16, -8, 12 };
    cout << nonNegative(arr, 0, arr.size() - 1) << endl;
}