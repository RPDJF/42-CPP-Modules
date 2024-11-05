#include "classes/Character.hpp"
#include "classes/Ice.hpp"
#include "classes/Cure.hpp"

int main(void) {
    Character Franculin("Franculin");
    Character Carapute("Carapute");
    AMateria *df_ice;
    (void)df_ice;
    (void)Franculin;
    (void)Carapute;

    df_ice = new Ice();
    Franculin.equip(df_ice);
    Franculin.equip(new Cure());
    Franculin.use(0, Carapute);
    return (0);
}