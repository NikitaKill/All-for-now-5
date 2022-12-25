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

void DemoCars() {
	/*Auto* c1 = MakeAuto("BMW", "White", 382.4);
	Auto* c2 = MakeAuto("Ferrari", "Black", 411.6);
	Auto* c3 = MakeAuto("Bugati", "Green", 461.3);*/
	Auto* c[3];
	c[0] = MakeAuto("BMW", "White", 382.4);
	c[1] = MakeAuto("Ferrari", "Black", 411.6);
	c[2] = MakeAuto("Bugati", "Green", 461.3);
}

int GetCarWithMaxSpeed(Auto* c) {
	double max = 0.0;

	for (int i = 0; i < 4; i++) {
		if (c[i].Maxspeed > max) {
			max = c[i].Maxspeed;
			cout << c[i].Maxspeed << c[i].Color;
			c = c + i;
			
		}
	}
	return max;

}

int main() {
	Auto *c[3];
	c[0] = MakeAuto("BMW", "White", 382.4);
	c[1] = MakeAuto("Ferrari", "Black", 411.6);
	c[2] = MakeAuto("Bugati", "Green", 461.3);
	//Auto* c1 = MakeAuto("BMW", "White", 382.4);
	//Auto* c2 = MakeAuto("Ferrari", "Black", 411.6);
	//Auto* c3 = MakeAuto("Bugati", "Green", 461.3);
	cout<<GetCarWithMaxSpeed(c[2]);

}