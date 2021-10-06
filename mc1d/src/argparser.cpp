#include "argparser.hpp"
#include <stdexcept>
#include <sstream>
using namespace std;

namespace mc1d {
  ArgParser::ArgParser(int argc, char* argv[]):
    m_trackLength(0),
    m_nParticles(0),
    m_absorption(0.f)
  {
    if (argc != 4) {
      throw std::invalid_argument("Must be 4 arguments");
    }
    m_trackLength = std::atoi(argv[1]);
    if (m_trackLength > MAX_TRACK_LENGTH) {
      stringstream msg;
      msg << "Track length must be <= " << MAX_TRACK_LENGTH;
      throw std::invalid_argument(msg.str());
    }
    m_absorption = std::atof(argv[2]);
    m_nParticles = std::atoi(argv[3]);
  }

  int ArgParser::get_track_length() const {
    return m_trackLength;
  }

  int ArgParser::get_num_particles() const {
    return m_nParticles;
  }

  float ArgParser::get_absorption() const {
    return m_absorption;
  }
}
