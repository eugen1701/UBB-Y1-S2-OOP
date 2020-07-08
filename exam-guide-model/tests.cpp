//
// Created by sweethuman on 20.06.2020.
//

#include "Domain.h"
#include <fstream>
#include "Repository.h"
#include <cassert>
void testRepo(){
    std::ofstream file{"test.txt"};
    file << "Fax,gaia,5,6,20" << std::endl;
    file.close();
    Star star{};
    star.name = "Faxia";
    star.constellation = "gaia";
    star.ra = 5;
    star.dec = 5;
    star.diameter = 5;
    Repository<Star> repository{"test.txt"};
    repository.add(star);
    Star star2{};
    star2.name = "Fax";
    star2.constellation = "gaia";
    star2.ra = 5;
    star2.dec = 5;
    star2.diameter = 5;
    try{
        repository.add(star2);
        assert(false);
    }catch(std::exception &e){
        assert(true);
    }

}