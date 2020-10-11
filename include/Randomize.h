/*!
   \file Randomize class header
   \brief defines the member data and methods of Randomize class
   \author Don Castillo
   \date 07/10/2020
*/

#ifndef RANDOMIZE_H_INCLUDED
#define RANDOMIZE_H_INCLUDED
#include <vector>

class Randomize {
 public:
   /*!
      \brief constructor
   */
    Randomize();

    /*!
       \brief desctructor
    */
    ~Randomize();

    /*!
       \brief gives random number
       \param minInt  minimum number that can possibly be returned
       \param maxInt  maximum number that can possibly be returned
       \return random integer between minInt and maxInt
    */
    static int randomize(int minInt, int maxInt);

    static int randomize(std::vector<int> integers);
};

#endif // RANDOMIZE_H_INCLUDED
