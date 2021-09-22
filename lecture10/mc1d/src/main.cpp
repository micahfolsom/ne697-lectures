#include "argparser.hpp"
#include "runmanager.hpp"
#include <iostream>
using namespace mc1d;
using namespace std;

int main(int argc, char* argv[]) {
  try {
    ArgParser arg_parser(argc, argv);

    RunManager run_manager(arg_parser.get_track_length(),
        arg_parser.get_absorption()
    );
    run_manager.run(arg_parser.get_n_particles());
  } catch (invalid_argument const& ex) {
    cout << "Usage: ./mc1d [track length] [absorption] [n particles]" << endl;
    cout << "Maximum [track length]: " << ArgParser::MAX_TRACK_LENGTH << endl;
    cout << "Error: " << ex.what() << endl;
  }

  return 0;
}
