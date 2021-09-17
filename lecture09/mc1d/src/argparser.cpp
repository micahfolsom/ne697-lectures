#include "argparser.hpp"
#include <stdexcept>
using namespace std;

namespace mc1d {
  ArgParser::ArgParser(int argc, char* argv[]) {
    // TODO: check argc

    // TODO: Error-check track length
    m_trackLength = std::atoi(argv[1]);

    // TODO: Error-check absorption
    m_absorption = std::atof(argv[2]);

    // TODO: Error-check number of particles
    m_nParticles = std::atoi(argv[3]);
  }

  int ArgParser::get_track_length() const {
    return m_trackLength;
  }

  float ArgParser::get_absorption() const {
    return m_absorption;
  }

  int ArgParser::get_num_particles() const {
    return m_nParticles;
  }
}
