#include <iostream>
#include <string>

struct fasta {
  std::string name, data;

  bool empty() const
  {
    return name.empty() || data.empty();
  }

  friend std::istream& operator>>(std::istream& i, fasta& f)
  {
    /*
     * TODO: Cannot read data like
     *
     * >Blabla
     * GATTACA
     * GATTACA
     * > Next
     *
     * So fix that.
     */

    char sep;
    i >> sep;

    if ( sep == '>' ) {
      i >> f.name;
      i >> f.data;
    }

    return i;
  }

  friend std::ostream& operator<<(std::ostream& o, const fasta& f)
  {
    if ( !f.empty() ) {
      o << '>' << f.name << std::endl
        << f.data << std::endl;
    }
    return o;
  }
};
