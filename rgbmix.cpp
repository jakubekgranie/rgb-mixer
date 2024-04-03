#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
void rgbcalc() {
	cout << "\n----------\nENTER COLORS:\n";
	int no = 0;
	vector<int> hexR, hexG, hexB;
	string hex;
	long unsigned int addedHex[3] = { 0 };
	while(1) {
		cout << "\nHEX NO. " << no + 1 << "\n";
		cin >> hex;
		if (hex == "END" || hex.length() != 6) break;
		cout << "HEX '#" << hex << "' LOGGED.\n";
		int rgb[3] = { 0 };
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 2; j++) {
				char value = hex[i * 2 + j];
				if (!isdigit(value)) {
					if (islower(value))
						value -= 32;
					value -= 55;
				}
				else value -= 48;
				if (j == 0) rgb[i] = value * 16;
				else rgb[i] += value;
			}
		hexR.push_back(rgb[0]);
		hexG.push_back(rgb[1]);
		hexB.push_back(rgb[2]);
		no++;
	}
	size_t hexSize = hexR.size();
	for (int i = 0; i < hexSize; i++) {
		addedHex[0] += hexR[i];
		addedHex[1] += hexG[i];
		addedHex[2] += hexB[i];
	}
	cout << "\nAverage RGB/HEX:\nrgb(";
	double rgbAvg[3];
	hex = "";
	for (int i = 0; i < 3; i++) {
		rgbAvg[i] = addedHex[i];
		rgbAvg[i] /= hexSize;
		cout << rgbAvg[i];
		if (i < 2) cout << ", ";
	}
	cout << ")\n#";
	for (int i = 0; i < 3; i++) {
		int val = rgbAvg[i];
		int typeData[2];
		typeData[0] = val / 16;
		typeData[1] = val - typeData[0] * 16;
		for (int j = 0; j < 2; j++) {
			if (typeData[j] > 9)
				cout << char('A' + typeData[j] - 10);
			else cout << typeData[j];
		}
	}
	cout << "\n\nRepeat? (0/1)\n>>";
	cin >> no;
	if (no == 1) rgbcalc();
}
int main() {
	cout << "(C) Jakub Namyslak. All rights reserved.";
	rgbcalc();
}