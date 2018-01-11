#include <stdio.h>
#if _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#include "CUDAProbeCLP.h"
#include "CUDAProbe.h"

// Use an anonymous namespace to keep class types and function names
// from colliding when module is used as shared object module.  Every
// thing should be in an anonymous namespace except for the module
// entry point, e.g. main()
//
namespace
{

bool
check_library (const char *library_name)
{
#if _WIN32
    HINSTANCE handle;
    handle = LoadLibrary (library_name);
    if (handle != NULL) {
        FreeLibrary (handle);
        return true;
    }
    return false;
#else
    void *handle = dlopen (library_name, RTLD_LAZY);
    if (handle) {
        dlclose (handle);
        return true;
    }
    return false;
#endif
}



} // end of anonymous namespace

int main( int argc, char * argv[] )
{
  PARSE_ARGS;

  printf ("Hello from CUDAProbe\n");
  FILE *fp = fopen (returnParameterFile.c_str(), "wb");
  if (!fp) return EXIT_FAILURE;

  fprintf (fp, "CUDAProbeResults1 = %s\n", 
#if CUDA_FOUND
      "CUDA was installed on the build system" 
#else
      "CUDA was not installed on the build system"
#endif
  );

  bool driver_found = false;
# if _WIN32
  driver_found = check_library ("nvcuda.dll");
# else
  driver_found = check_library ("libcuda.so");
# endif
  fprintf (fp, "CUDAProbeResults2 = %s\n", 
      driver_found
      ? "CUDA driver found by Slicer"
      : "CUDA driver NOT found by Slicer");

  bool runtime_found = false;
# if _WIN32
  runtime_found = check_library ("cudart64_80.dll");
# else
  runtime_found = check_library ("libcudart.so");
# endif
  fprintf (fp, "CUDAProbeResults3 = %s\n", 
      runtime_found
      ? "CUDA runtime found by Slicer"
      : "CUDA runtime NOT found by Slicer");

  fprintf (fp, "CUDAProbeResults4 = *\n");

  fclose (fp);

  return EXIT_SUCCESS;
}
