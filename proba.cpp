#include <iostream>
#include <fstream>

//A szoftver f�ggv�ny seg�ts�g�vel megsz�molja a k�l�nb�z� m�ssalhangz�k
//sz�m�t!

int checkCharacter(unsigned char* elements, int size, unsigned char element) {
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (elements[i] == element)
		{
			found = true;
			break;
		}
	}

	return found;
}

int countMsh(unsigned char* C,int size)
{
	int numberofMsh = 0;
	unsigned char elements[20] = { 0 };

	for (int i = 0; i < size; i++) {
		if (
			(C[i] != 'a') &&
			(C[i] != 'e') &&
			(C[i] != 'i') &&
			(C[i] != 'o') &&
			(C[i] != 'u')
			)
		{
			if (!checkCharacter(elements, 20, C[i])) {
				elements[numberofMsh] = C[i];
				numberofMsh += 1;
			}
		}
	}

	return numberofMsh;
}

//A szoftver lehet�s�get biztos�t elj�r�s seg�ts�g�vel a mag�nhangz�k
//sz�mjegyekk� val� kicser�l�s�re!

void replaceMgh(unsigned char* C, int size) {
	for (int i = 0; i < size; i++) {
		if (
			(C[i] == 'a') ||
			(C[i] == 'e') ||
			(C[i] == 'i') ||
			(C[i] == 'o') ||
			(C[i] == 'u')
			)
		{
			C[i] = rand() % (57 + 1 - 48) + 48;
		}
	}
}

//A szoftver lehet�s�get biztos�t elj�r�s seg�ts�g�vel a felhaszn�l� �ltal megadott
//karakter �sszes el�fordul�s�nak t�rl�s�re a t�mbben

//--------laboron meg�rt elj�r�s �jrafelhaszn�l�sa----------------
void clearElement(unsigned char* C, unsigned int index, unsigned int& currentSize)
{
	unsigned char* element = &C[index + 1];

	for (int i = index; i < currentSize - 1; ++i) {
		C[i] = *element;
		++element;
	}
	C[currentSize - 1] = '\0';
	currentSize -= 1;
}

void removeCharacter(unsigned char* C, int arraySize) {
	unsigned int currentSize = arraySize;
	unsigned char c = 0;
	std::cout << "Torlendo karakter: ";
	std::cin >> c;

	for (int i = 0; i < arraySize; i++) {
		if (C[i] == c) {
			clearElement(C, i, currentSize);
		}
	}
}

void writeCharacters(unsigned char* C, int size) {
	unsigned char elements[34] = { 0 };
	int iterator = 0;

	for (int i = 0; i < size; i++) {
		if (!checkCharacter(elements, 34, C[i])) {
			elements[iterator] = C[i];
			iterator += 1;
		}
	}

	std::ofstream out;
	out.open("characters.txt", std::ios::out);

	if (out.is_open()) {
		for (int i = 0; i < iterator; i++) {
			out << elements[i] << " ";
		}
	}

	out.close();
}

int main()
{
	// A szoftver els� l�p�sk�nt k�rjen be a felhaszn�l�t�l h�rom eg�sz t�pus� sz�m�rt�ket!
	int size = 0, min = 0, max = 0;
	std::cin >> size >> min >> max;

	//A szoftver foglaljon le az el�z�leg bek�rt v�ltoz��rt�kek alapj�n egy karakter t�pus� t�mb�t, 
	//melyet v�letlenszer� kisbet�s karakterekkel t�lts�n fel!
	unsigned char* C = new unsigned char[size];

	for (int i = 0; i < size; i++) {
		C[i] = rand() % (max + 1 - min) + min;
	}

	countMsh(C, size);
	removeCharacter(C, size);
	writeCharacters(C, size);
	return 0;
}