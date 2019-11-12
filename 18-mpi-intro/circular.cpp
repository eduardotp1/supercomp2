#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>
#include <iostream>
namespace mpi = boost::mpi;

int main(int argc, char* argv[]) {
    mpi::environment env(argc, argv);
    mpi::communicator world;
    
    if (world.rank() == 0) {
        int data;
        world.send(1, world.rank(), world.rank()*world.rank());
        world.recv(world.size()-1, 0, data);
        std::cout << "Received" << data << " from "<<world.size()-1<<" \n";
    }
    if (world.rank() == world.size()-1) {
        int data;
        world.send(0, 0, world.rank()*world.rank());
        world.recv(world.rank()-1, world.rank()-1, data);
        std::cout << "Received" << data << " from "<<world.rank()-1<<" \n";
    }
    
     else{
        int data;
        world.send(world.rank()+1, world.rank(), world.rank()*world.rank());
        world.recv(world.rank()-1, world.rank()-1, data);
        std::cout << "Received" << data << " from"<<world.rank()-1<<" \n";
    }
    return 0;
}