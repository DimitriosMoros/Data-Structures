
// COS30008 - Particle Simulation

#include <iostream>
#include <string>

#include "Particle2D.h"

int main( int argc, char* argv[] )
{
    std::cout << "A simple particle simulation\n" << std::endl;
    
    Particle2D obj( 0.0f,
                    10.0f,
                    Vector2D( 10.0f, 20.0f ),
                    Vector2D( 4.0f, 15.0f ),
                    Vector2D( 0.0f, -0.1f )
                   );

    // Set initial direction of velocity if specified.
    if ( argc == 2 )
    {
        obj.align( std::stof( argv[1] )) ;
    }

    do
    {
        std::cout << obj << std::endl;

        obj.update();
    } while ( obj.getPosition().getY() >= 20.0f );

    std::cout << obj << std::endl;

    return 0;
}
