#include "classes/Character.hpp"
#include "utils/materias.hpp"

int main(void) {
	std::cout << C_YELLOW << "Once upon a time, two mighty clans were locked in an eternal struggle." << C_RESET << std::endl;
	std::cout << "On one side stood the " << C_BOLD << C_MAGENTA << "Clan of Simps" << C_RESET << ", led by the valiant fisherman " << C_BOLD << C_YELLOW << "Ilyanar" << C_RESET << " and the master of cables, " << C_BOLD << C_YELLOW << "Fclivaz" << C_RESET << "." << std::endl;
	std::cout << "Opposing them was the " << C_BOLD << C_CYAN<< "Clan of Alcoholics" << C_RESET << ", commanded by the indomitable " << C_BOLD << C_YELLOW << "Rude-jes the Unemployed" << C_RESET << " and the fiery " << C_BOLD << C_YELLOW << "Rrouille the Redhead" << C_RESET << "." << std::endl;
	std::cout << "\nThe reason for their conflict had long been forgotten, lost to the sands of time." << std::endl;
	std::cout << C_BOLD << C_CYAN << "After millennia of relentless warfare, the end was finally in sight." << C_RESET << std::endl;
	std::cout << "The battlefield was littered with the remnants of countless battles, and only four warriors remained standing." << std::endl;
	std::cout << C_BOLD << C_YELLOW << "Rude-jes, Rrouille, Ilyanar, and Fclivaz" << C_RESET << " faced each other, their eyes burning with determination." << std::endl;
	std::cout << "\nWith a final surge of energy, they summoned their chakra and ki, preparing for the ultimate showdown." << std::endl;
	std::cout << C_RED << "The air crackled with power as they charged towards each other, ready to decide the fate of their clans in one last, epic battle." << C_RESET << std::endl;
	std::cout << "\n\n";
	std::cout << C_BCYAN << "                   " << C_BWHITE << "/\\" << C_BCYAN << "                          " << C_RESET << std::endl;
	std::cout << C_BCYAN << "                  " << C_BWHITE << "/  \\" << C_BCYAN << "                         " << C_RESET << std::endl;
	std::cout << C_BCYAN << "   " << C_BWHITE << "/\\" << C_BCYAN << "            " << C_BWHITE << "/    \\" << C_BCYAN << "    " << C_BWHITE << "/\\" << C_BCYAN << "             " << C_BWHITE << "/\\" << C_BCYAN << "   " << C_RESET << std::endl;
	std::cout << C_BCYAN << "  " << C_BGREEN << "/  \\" << C_BCYAN << "          " << C_BGREEN << "/      \\" << C_BCYAN << "  " << C_BGREEN << "/  \\" << C_BCYAN << "   " << C_BGREEN << "/\\" << C_BCYAN << "      " << C_BGREEN << "/  \\" << C_BCYAN << "  " << C_RESET << std::endl;
	std::cout << C_BCYAN << " " << C_BGREEN << "/    \\" << C_BCYAN << "   " << C_BGREEN << "/\\" << C_BCYAN << "   " << C_BGREEN << "/        \\" << C_BCYAN << "" << C_BGREEN << "/    \\" << C_BCYAN << " " << C_BGREEN << "/  \\" << C_BCYAN << "    " << C_BGREEN << "/    \\" << C_BCYAN << " " << C_RESET << std::endl;
	std::cout << C_BGREEN << "/______\\_/  \\_/__________\\______\\____\\_/______\\" << C_RESET << std::endl;
	std::cout << "\nThe final battle was upon them, and fate would soon be decided." << std::endl;

	Character Rudejes("Rude-jes"), Rrouille("Rrouille"), Ilyanar("Ilyanar"), Fclivaz("Fclivaz");

	Rudejes.talk("You two are still busy simping? This is a real fight.");
	Rrouille.talk("Your loyalty won’t save you. You’re just a joke to us.");

	Ilyanar.talk("Simping is about respect, Rude-jes. Something you’ll never understand.");
	Fclivaz.talk("We fight for something real. Your drinking won’t change that.");

	Rudejes.talk("Respect? You’ll get no respect in the grave, Ilyanar.");
	Rrouille.talk("Your ‘loyalty’ is a weakness, Fclivaz. You can’t win with that.");

	Ilyanar.talk("We fight for honor, something you’ve lost in your drunken haze.");
	Fclivaz.talk("You think we’re weak, but you’ve already lost. We’re stronger than you realize.");

	Rudejes.talk("You’ll regret standing in our way. Simping won’t save you.");
	Rrouille.talk("Your hearts are soft, but this battlefield is no place for softness.");

	Ilyanar.talk("The tide may be strong, but we’ll never give up. We have something worth fighting for.");
	Fclivaz.talk("Your drunken delusions end here. We won’t let you take this from us.");

	std::cout << std::endl;
	AMateria *df_ice = new Ice();
	AMateria *df_thunder = new Thunder();
	std::cout << C_BOLD << C_YELLOW << Rudejes.getName() << C_RESET << C_BOLD << " quickly grabs the new two materials." << std::endl;
	Rudejes.equip(df_ice);
	Rudejes.equip(df_thunder);
	Ilyanar.equip(df_ice);
	std::cout << C_BOLD << C_YELLOW << Ilyanar.getName() << C_RESET << C_BOLD << " also tried to grab one of them, but " << C_YELLOW << Rudejes.getName() << C_RESET << C_BOLD << " was too quick for him." << std::endl;
	Rudejes.talk("Here " + Rrouille.getName() + ", take one of my materias.");
	Rudejes.unequip(1);
	Rrouille.equip(df_thunder);
	Rrouille.talk("Thanks " + Rudejes.getName() + "!");

	Rudejes.talk("You won't escape this! Feel the cold of my Ice!");
	Rudejes.use(0, Ilyanar);

	std::cout << C_BOLD << C_YELLOW << Ilyanar.getName() << C_RESET << C_BOLD << " feels the cold bite of " << Rudejes.getName() << "'s Ice attack." << std::endl;

	std::cout << Ilyanar.getName() << ", shivering but unfazed, responds:" << std::endl;
	Ilyanar.talk("Your Ice won't stop me, " + Rudejes.getName() + ". Time to heat things up!");
	Ilyanar.equip(new Fire());
	Ilyanar.use(0, Rudejes);

	std::cout << C_BOLD << C_YELLOW << Rudejes.getName() << C_RESET << C_BOLD << " is scorched by " << Ilyanar.getName() << "'s Fire spell." << std::endl;

	std::cout << Rrouille.getName() << " steps forward, noticing the intense battle, and calls out:" << std::endl;
	Rrouille.talk("That's it, enough of the fire and ice! Let's see how you like this!");
	Rrouille.use(0, Ilyanar);

	std::cout << C_BOLD << C_YELLOW << Ilyanar.getName() << C_RESET << C_BOLD << " is blasted away by the powerful Thunder attack!" << std::endl;

	std::cout << Rudejes.getName() << ", seeing the situation, decides to use something even more dangerous:" << std::endl; 
	Rudejes.talk("This will poison you, " + Ilyanar.getName() + "! You won't be able to keep up with me!");
	Rudejes.equip(new Poison());
	Rudejes.use(1, Ilyanar);

	std::cout << C_BOLD << C_YELLOW << Ilyanar.getName() << C_RESET << C_BOLD << " feels the toxic poison coursing through his veins." << std::endl;

	std::cout << Ilyanar.getName() << ", grimacing from the poison but still standing, calls back:" << std::endl;
	Ilyanar.talk("Not so fast, " + Rudejes.getName() + ". I still have my Cure Materia!");
	Ilyanar.equip(new Cure());
	Ilyanar.use(1, Ilyanar);

	std::cout << C_BOLD << C_YELLOW << Ilyanar.getName() << C_RESET << C_BOLD << " heals himself, shaking off the effects of the poison." << std::endl;

	std::cout << Rrouille.getName() << ", now watching " << Ilyanar.getName() << " recover, decides to act:" << std::endl;
	Rrouille.talk("You're getting stronger, but can you handle this?");
	Rrouille.use(0, Ilyanar);

	std::cout << C_BOLD << C_YELLOW << Ilyanar.getName() << C_RESET << C_BOLD << " is struck by a powerful Thunderbolt from Rrouille!" << std::endl;

	std::cout << Ilyanar.getName() << ", now heavily damaged but resolute, looks at his opponents and says:" << std::endl;
	Ilyanar.talk("You may have Thunder, Fire, and Ice... But I will not fall!");
	std::cout << Ilyanar.getName() << " quickly summons a healing spell to restore his energy." << std::endl;
	Ilyanar.use(1, Ilyanar);

	std::cout << C_BOLD << C_YELLOW << Ilyanar.getName() << C_RESET << C_BOLD << " restores his strength, determined to continue the fight!" << std::endl;

	std::cout << Rudejes.getName() << ", frustrated by " << Ilyanar.getName() << "'s resilience, raises his hand and shouts:" << std::endl;
	Rudejes.talk("Enough! I will finish this!");
	Rudejes.use(0, Ilyanar);

	std::cout << C_BOLD << C_YELLOW << Ilyanar.getName() << C_RESET << C_BOLD << " is struck by a devastating Ice bolt, freezing him in place!" << std::endl;

	std::cout << Fclivaz.getName() << ", not willing to let the battle end so easily, calls out:" << std::endl;
	Fclivaz.talk("I won't let you get away with that, " + Rudejes.getName() + "! This ends now!");
	Fclivaz.equip(new Thunder());
	Fclivaz.use(0, Rudejes);

	std::cout << C_BOLD << C_YELLOW << Rudejes.getName() << C_RESET << C_BOLD << " is shocked by the Thunder spell, staggering back from the impact." << std::endl;
    return (0);
}