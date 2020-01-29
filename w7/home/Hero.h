#ifndef HERO_H
#define HERO_H
#define SIZE 41
#include <iostream>

namespace sict {
    class Hero {
        char name_[SIZE];    
        int  attack_;
        int  maximumHealth_;
        int  health_;
        
        bool isEmpty () const;

    public:
        // constructors
        Hero ();
        Hero (const char name[], int maximumHealth, int attack);

        // member functions
        void respawn();
        bool isAlive () const           {    return health_ > 0;  	}
        int  getAttack () const         {    return attack_;       }
        void deductHealth(int);

        // friend helper function to insert name into ostream
        friend std::ostream& operator<<(std::ostream&, const Hero&);
    };

    void applyDamage (Hero& A, Hero& B);
    const Hero & operator*(const Hero &, const Hero &);
}

#endif
