if get_option('debug') == true
  warning_level = 3
  add_project_arguments('-D__DEBUG__', language: ['c'])
endif
add_project_arguments('-std=gnu11', language: ['c'])

subdir('srcs')
