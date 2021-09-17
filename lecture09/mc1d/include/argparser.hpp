#ifndef ARGPARSER_HPP
#define ARGPARSER_HPP

namespace mc1d {
  class ArgParser {
    public:
      ArgParser(int argc, char* argv[]);

      int get_track_length() const;
      float get_absorption() const;
      int get_num_particles() const;

    private:
      static int const MAX_TRACK_LENGTH = 75;

      int m_trackLength;
      float m_absorption;
      int m_nParticles;
  };
}

#endif
