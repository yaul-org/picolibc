srcs_tlsf = [
    'tlsf.c',
]

srcs_tlsf_use = []
foreach file : srcs_tlsf
  s_file = fs.replace_suffix(file, '.S')
  if file in srcs_machine
    message('libc/tlsf/' + file + ': machine overrides generic')
  elif s_file in srcs_machine
    message('libc/tlsf/' + s_file + ': machine overrides generic')
  else
    srcs_tlsf_use += file
  endif
endforeach

src_tlsf = files(srcs_tlsf_use)
