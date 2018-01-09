#include <stdio.h>
#include "CUDAProbeCLP.h"

// Use an anonymous namespace to keep class types and function names
// from colliding when module is used as shared object module.  Every
// thing should be in an anonymous namespace except for the module
// entry point, e.g. main()
//
namespace
{


} // end of anonymous namespace

int main( int argc, char * argv[] )
{
  PARSE_ARGS;

  printf ("Hello from CUDAProbe\n");
  FILE *fp = fopen (returnParameterFile.c_str(), "wb");
  if (!fp) return EXIT_FAILURE;
  fprintf (fp, "CUDAProbeResults = %s\n", "Hello from CUDA Probe!");
  fclose (fp);

  return EXIT_SUCCESS;
}
