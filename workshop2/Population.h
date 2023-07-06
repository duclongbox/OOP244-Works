#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
	bool load(const char Filename[]);
	struct Population {
		char* postalcode;
		int population;
	};
	void sort();
	bool load(Population& popul);
	bool load(const char Filename[]);
	void display(const Population& pop);
	void display();
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_