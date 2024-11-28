#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include <iostream>

# define SRC_SIZE 4

class MateriaSource: public IMateriaSource {
	private:
		unsigned char size_;
		AMateria* arr_[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		~MateriaSource();
		const MateriaSource& operator=(const MateriaSource& assign);
		void learnMateria(AMateria*);
		AMateria* createMateria(const std::string& type);
};

#endif