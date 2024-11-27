#include "classes/Character.hpp"
#include "classes/Ice.hpp"
#include "classes/Cure.hpp"

int main(void) {
    Character Franculin("Franculin");
	Character Macchiotte("Macchiotte");
	AMateria *df_ice = new Ice();
	AMateria *df_cure = new Cure();

	Macchiotte.equip(df_ice);
    Franculin.equip(df_ice);
	Macchiotte.unequip(0);
	Macchiotte.equip(df_ice);
	Macchiotte.unequip(0);
    Franculin.equip(df_cure);
	Franculin.equip(df_ice->clone());
	Franculin.equip(df_cure);
	Franculin.unequip(0);
	Franculin.unequip(0);
	Franculin.unequip(0);
	Franculin.unequip(0);
	Franculin.unequip(0);
    return (0);
}