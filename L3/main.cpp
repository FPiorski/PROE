#include <iostream>
#include <vector>
#include "Ksiazka.h"
#include "Drukowana.h"
#include "Ebook.h"

int main()
{
    std::vector<Ksiazka*> biblioteczka;
    biblioteczka.push_back(new Ebook);
    biblioteczka.push_back(new Ebook(200, 10));
    biblioteczka.push_back(new Ebook(345, 92));
    biblioteczka.push_back(new Ebook(2300, 124));
    biblioteczka.push_back(new Drukowana(322, "Miekka"));
    biblioteczka.push_back(new Drukowana(321, "Twarda"));
    biblioteczka.push_back(new Drukowana(529, "Miekka"));
    biblioteczka.push_back(new Drukowana(822, "Twarda"));
    biblioteczka.push_back(new Drukowana(322, "Twarda"));
    for (auto i : biblioteczka)
        i->info();
    for (auto i : biblioteczka)
        delete i;
	return 0;
}
