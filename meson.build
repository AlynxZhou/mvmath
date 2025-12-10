mv_c_args = []
if get_option('debug') == true
  warning_level = 3
  mv_c_args += ['-D__DEBUG__']
endif
mv_c_args += ['-std=gnu11']

subdir('srcs')
