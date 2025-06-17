#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Variables globales
vector<string> laberinto;
int filas, columnas;
bool encontrado = false;

// Direcciones de movimiento: arriba, abajo, izquierda, derecha
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


void mostrarLaberinto() {
    for (size_t i = 0; i < laberinto.size(); i++) {
        cout << laberinto[i] << endl;
    }
}

void recorrer(int x, int y) {
    if (encontrado) return;
    if (x < 0 || x >= filas || y < 0 || y >= columnas) return;

    char c = laberinto[x][y];
    if (c == '|' || c == '-' || c ==  '*' || c == '\n') return;
 if (c == 'S') {  //S es la salida
        encontrado = true;
        return;
    }

    if (c != 'E') laberinto[x][y] = '*';

    for (int i = 0; i < 4; i++) {
        recorrer(x + dx[i], y + dy[i]);
        if (encontrado) return;
    }

    if (laberinto[x][y] == '*') laberinto[x][y] = ' ';
}

int main() {
    ifstream archivo("laberinto.txt");

    if (archivo.is_open()) {
        cout << "Archivo abierto correctamente. Leyendo laberinto...\n";

        string linea;
        while (getline(archivo, linea)) {
            laberinto.push_back(linea);
        }

 archivo.close();

        filas = laberinto.size();
        columnas = laberinto[0].length();

        // Buscar la entrada 'E'
        int startX = -1, startY = -1;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (laberinto[i][j] == 'E') {
                    startX = i;
                    startY = j;
                    break;
                }
            }
            if (startX != -1) break;
        }

        if (startX == -1) {
            cerr << "Error: No se encontró la entrada 'E' en el laberinto." << endl;
            return 1;
        }

 recorrer(startX, startY);

        cout << (encontrado ? "\n¡Salida encontrada!\n" : "\nNo se encontró la salida.\n");
        mostrarLaberinto();

    } else {
        cerr << "Error: No se pudo abrir el archivo." << endl;
    }

 return 0;
}
