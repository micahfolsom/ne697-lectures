#ifndef ARG_PARSER_HPP
#define ARG_PARSER_HPP

namespace mc1d { 
  class ArgParser {
    public:
      ArgParser(int argc, char* argv[]);

      int get_track_length() const;
      int get_num_particles() const;
      float get_absorption() const;

    private:
      static int const MAX_TRACK_LENGTH = 100;

      int m_trackLength;
      int m_nParticles;
      float m_absorption;
  };
}

#endif
