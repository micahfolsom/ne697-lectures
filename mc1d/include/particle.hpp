#ifndef PARTICLE_HPP
#define PARTICLE_HPP

namespace mc1d {
  class Particle {
    public:
      Particle(int id);

      int get_id() const;
      int get_position() const;
      void set_position(int pos);
      bool alive() const;
      void kill();

    private:
      int m_id;
      int m_position;
      bool m_fAlive;
  };
}

#endif
