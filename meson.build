project ('Vectors Library', ['cpp'],
         default_options : ['cpp_std=c++20', 'b_ndebug=if-release'],
         license : 'GPL-3.0')

cpp = meson.get_compiler('cpp')

if cpp.get_id() == 'clang'
  extra_args = []
else
  extra_args = ['-ftrack-macro-expansion=0',
                '-fno-diagnostics-show-caret']
endif

add_global_arguments (extra_args, language: 'cpp')

boost_dep = dependency ('boost')

if not cpp.has_header ('experimental/simd')
  error ("SIMD experimental headers must exist.")
endif

subdir ('include')

subdir ('tests')
