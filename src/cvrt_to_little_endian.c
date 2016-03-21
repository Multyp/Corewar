#include "vm_corewar.h"

int		convert_to_little_endian(int size)
{
  return (((size >> 24) & 0xFF) |
	  ((size << 8) & 0xFF0000) |
	  ((size >> 8) & 0xFF00) |
	  ((size << 24 & 0xFF000000)));
}
