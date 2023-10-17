#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Funciones para Bit de Paridad
bool checkParity(int number, bool isEvenParity) {
    int count = 0; 
    while (number) {
        count += number & 1;
        number >>= 1;
    }
    return isEvenParity ? count % 2 == 0 : count % 2 != 0;
}

// Funciones para Checksum
char getChecksum(char* data, size_t length) {
    char checksum = 0;
    for (size_t i = 0; i < length; ++i) {
        checksum += data[i];
    }
    return checksum;
}

// Funciones para LRC
unsigned char calculateLRC(const vector<unsigned char>& data) {
    unsigned char lrc = 0;
    for (auto byte : data) {
        lrc ^= byte;
    }
    return lrc;
}

// Funciones para CRC
unsigned char getCRC(unsigned char* data, size_t length) {
    unsigned char crc = 0x00;
    while (length--) {
        unsigned char extract = *data++;
        for (unsigned char tempI = 8; tempI; tempI--) {
            unsigned char sum = (crc ^ extract) & 0x01;
            crc >>= 1;
            if (sum) {
                crc ^= 0x8C;
            }
            extract >>= 1;
        }
    }
    return crc;
}

int main() {
    cout << "=== BIT DE PARIDAD ===" << endl;
    int number = 5; //Valor de prueba
    cout << "El número " << number << " tiene paridad: ";
    cout << (checkParity(number, true) ? "Impar" : "Par") << endl << endl;


    cout << "=== CHECKSUM ===" << endl;
    char dataChecksum[] = "Hello, World!";
    char checksum = getChecksum(dataChecksum, sizeof(dataChecksum) - 1);
    cout << "Checksum: " << hex << (int)checksum << endl << endl;

    cout << "=== LRC ===" << endl;
    vector<unsigned char> dataLRC = {'H', 'e', 'l', 'l', 'o'};
    unsigned char lrc = calculateLRC(dataLRC);
    cout << "LRC: " << hex << static_cast<int>(lrc) << endl << endl;

    cout << "=== CRC ===" << endl;
    unsigned char dataCRC[] = "Hello, CRC!";
    unsigned char crc = getCRC(dataCRC, sizeof(dataCRC) - 1);
    cout << "CRC: " << hex << (int)crc << endl << endl;

    return 0;
}
