#include "SnackMachine.h"
int main(){
	Machine m;
	do{
		m.MainMenu();
	}while(m.WantsToContinue());
	return 0;
}