// function prototypes
// kingdom.h
// 30/5/2017
// Sahil lapsiwala


// TODO: header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H
// TODO: sict namespace
namespace sict {
	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom {
		char m_name[32];
		int m_population;
	};
	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(const Kingdom&);
	void display(const Kingdom* king, int size);

}
#endif
