#include <iostream>
#include "argparser.hpp"
#include "runmanager.hpp"
using namespace std;

int main(int argc, char* argv[]) {
  try {
    mc1d::ArgParser parser(argc, argv);
    mc1d::RunManager run_manager(
        parser.get_track_length(),
        parser.get_absorption()
    );
    run_manager.run(parser.get_num_particles());
  } catch (invalid_argument const& ex) {
    cout << "Error: " << ex.what() << endl;
    cout << "Usage: ./mc1d [track length] [absorption] [n particles]" << endl;
    return 1;
  }
  return 0;
}
