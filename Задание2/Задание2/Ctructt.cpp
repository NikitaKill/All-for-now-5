#include <iostream>

using namespace std;

struct Auto {
	string Name, Color;
	double Maxspeed;
};


Auto* MakeAuto(string Name, string Color, double Maxspeed) {
	Auto* c = new Auto();
	c->Name = Name;
	c->Color = Color;
	c->Maxspeed = Maxspeed;
	return c;
}

//void DemoCars() {
//	Auto* c[2];
//	c[0] = MakeAuto("BMW", "White", 382.4);
//	c[1] = MakeAuto("Ferrari", "Black", 411.6);
//	c[2] = MakeAuto("Bugati", "Blue", 464.2);
//}

void GetCarWithMaxSpeed(Auto* Maxsp[3]) {
	double max = 0.0;
	for (int i = 0; i < 3; i++) {
		if (Maxsp[i]->Maxspeed > max) {
			max = Maxsp[i]->Maxspeed;
			cout << "Максимальная скорость: " << max;
		}
	}
}

int main() {
	Auto* c[2];
	c[0] = MakeAuto("BMW", "White", 382.4);
	c[1] = MakeAuto("Ferrari", "Black", 411.6);
	c[2] = MakeAuto("Bugati", "Blue", 464.2);
	void GetCarWithMaxSpeed(Auto * Maxsp[3]);
}
