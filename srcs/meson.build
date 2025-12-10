sources = files(
  'mvmath.c'
)

headers = files(
  'mvmath.h'
)

dependencies = []
cc = meson.get_compiler('c')
m = cc.find_library('m')
dependencies += [m]

include_directories = []

# This is designed as a project submodule so we add project name as prefix.
if get_option('buildtype') == 'debug'
  mvmath = static_library(
    meson.project_name() + '-mvmath',
    sources: sources,
    c_args: mv_c_args,
    include_directories: include_directories,
    dependencies: dependencies,
    # Do not install static libray, we already linked against it.
    install: false
  )
else
  mvmath = shared_library(
    meson.project_name() + '-mvmath',
    sources: sources,
    c_args: mv_c_args,
    include_directories: include_directories,
    dependencies: dependencies,
    install: true
  )
endif
mvmath_dep = declare_dependency(
  link_with: mvmath,
  include_directories: include_directories('.')
)
